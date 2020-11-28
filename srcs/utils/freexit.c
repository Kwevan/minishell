/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freexit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:07:44 by afoulqui          #+#    #+#             */
/*   Updated: 2020/11/27 22:33:01 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(t_minishell *minishell, int status)
{
	if (minishell->env)
		ft_freestrarr(minishell->env);
	if (minishell->commands)
		ft_freestrarr(minishell->commands);
	if (minishell->input)
		free(minishell->input);
	if (minishell->curr_dir)
		free(minishell->curr_dir);
	if (minishell)
		minishell = NULL;
	ft_putstr_fd("exit\n", STDERR_FILENO);
	exit(status);
}
