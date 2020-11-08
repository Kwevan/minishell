/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 22:02:33 by kgouacid          #+#    #+#             */
/*   Updated: 2020/11/08 19:15:50 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_exec_commands(t_minishell *mini, char **commands)
{
	int		i;
	char	**splitted_cmd;
	char	**new;

	i = 0;
	new = NULL;
	while (commands[i])
	{
		if (ft_check_multilines(commands[i]))
		{
			ft_putstr_fd("NO MULTILINE\n", STDERR_FILENO);
			ft_freestrarr(commands);
			return ;
		}
		if (!ft_pipe_redir(mini, commands[i]))
		{
			splitted_cmd = ft_split_quote(commands[i], " ");
			new = ft_parse(mini, splitted_cmd);
			ft_exec_command(mini, new);
		}
		i++;
	}
	ft_freestrarr(new);
	ft_freestrarr(commands);
}
