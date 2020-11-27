/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 22:02:33 by kgouacid          #+#    #+#             */
/*   Updated: 2020/11/26 22:36:25 by kwe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_exec_commands(t_minishell *mini)
{
	int		i;
	char	**splitted_cmd;
	char	**new;

	i = 0;
	new = NULL;
	while (mini->commands[i])
	{
		if (ft_check_multilines(mini->commands[i]))
			(mini->ret = 1) ? ft_putstr_fd("NO MULTILINE\n", STDERR_FILENO) : 0;
		else if (!ft_pipe_redir(mini, mini->commands[i]))
		{
			splitted_cmd = ft_split_quote(mini->commands[i], " ");
			new = ft_parse(mini, splitted_cmd);
			ft_exec_command(mini, new);
			ft_freestrarr(new);
		}
		if (mini->pipe_err == 1)
			break ;
		i++;
	}
	ft_freestrarr(mini->commands);
	mini->commands = NULL;
}
