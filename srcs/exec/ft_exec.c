/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 22:02:33 by kgouacid          #+#    #+#             */
/*   Updated: 2020/10/27 19:50:38 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_exec_commands(t_minishell *mini, char **commands)
{
	int		i;
	char	**splitted_cmd;
//	char	**new_cmds;
	char	**new;

	i = 0;
//	new_cmds = NULL;
	while (commands[i])
	{
		if (strchr(commands[i], '|') || strchr(commands[i], '>'))
		{
			//new_cmds = ft_split2(commands[i], "|");
			ft_pipe_redir(mini, commands[i]);
		}
		else
		{
			if (ft_check_multilines(commands[i]))
			{
				ft_putstr_fd("NO MULTILINE\n", STDERR_FILENO);
				ft_freestrarr(commands);
				return ;
			}
			splitted_cmd = ft_split_quote(commands[i], " ");
			new = ft_parse(mini, splitted_cmd);
			ft_exec_command(mini, new);
		}
		i++;
	}
	ft_freestrarr(commands);
}
