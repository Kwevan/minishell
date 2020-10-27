/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 22:02:33 by kgouacid          #+#    #+#             */
/*   Updated: 2020/10/27 11:12:02 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_exec_commands(t_minishell *mini, char **commands)
{
	int		i;
	char	**splitted_cmd;
	char	**new_cmds;
	char	*cmd;

	i = 0;
	new_cmds = NULL;
	while (commands[i])
	{
		if (strchr(commands[i], '|') || strchr(commands[i], '>'))
		{
			ft_putstr_fd("todo", 1);
			//new_cmds = ft_split2(commands[i], "|"); // ou redir
			//ft_pipe(mini, new_cmds);
		}
		else
		{
			if (ft_check_multilines(commands[i]))
			{
				ft_putstr_fd("NO MULTILINE\n", STDERR_FILENO);	
				ft_freestrarr(commands);
				//var $?
				return ;
			}
			(void)cmd;
			splitted_cmd = ft_split2(commands[i], " "); // ou redir
			char **new = ft_parse(mini, splitted_cmd);
			ft_exec_command(mini, new);
		}
		i++;
	}
	ft_freestrarr(commands);
}
