/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:45:01 by afoulqui          #+#    #+#             */
/*   Updated: 2020/10/15 15:10:12 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_ctrl_c(int signal, t_minishell *minishell)
{
	ft_putstr_fd('\n', 1);
	if(!(minishell->pid))
		ft_prompt_msg(minishell);
	else
		kill(minishell->pid, signal);	
}

void	handle_ctrl_backlash(int signal, t_minishell *minishell)
{
	char	*str_signal;

	str_signal = ft_itoa(signal);
	if (minishell->pid)
	{
		kill(minishell->pid, signal);
		ft_putstr_fd("\nQuit : ", 1);
		ft_putstr_fd(str_signal, 1);
		ft_putstr_fd("\n", 1);
	}
	free(str_signal);
}

void	handle_signal(t_minishell *minishell)
{
	if (signal(SIGINT, &handle_ctrl_c) == SIG_ERR)
		ft_putstr_fd("SIGINT error", 1);
	if (signal(SIGQUIT, &handle_ctrl_backlash) == SIG_ERR)
		ft_putstr_fd("SIGQUIT error", 1);
}