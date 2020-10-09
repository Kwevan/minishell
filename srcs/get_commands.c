/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:56:24 by afoulqui          #+#    #+#             */
/*   Updated: 2020/10/08 16:25:44 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd		parse_pieces_cmds(char *cmd)
{
	int		i;
	char	**pieces;
	t_cmd	res;

	pieces = ft_split(cmd, ' ');
	free(cmd);
	res.cmd = pieces[0];
	res.argc = ft_countstrarr(pieces) + 1;
	res.args = ft_calloc(sizeof(char *), res.argc);
	if (res.args == NULL)
		return (res);
	i = 0;
	while (pieces[i])
	{
		res.args[i] = pieces[i];
		i++;
	}
	res.args[i] = NULL;
	return (res);
}

t_cmd		*parse_pipe_cmds(char *cmd)
{
	int		i;
	int		count;
	char	**pipes;
	t_cmd	*cmds;
	t_cmd	last;

	pipes = ft_split(cmd, "|");
	free(cmd);
	last.cmd = NULL;
	count = ft_countstrarr(pipes) + 1;
	cmds = ft_calloc(sizeof(t_cmd), count);
	if (cmds == NULL)
		return (NULL);
	i = 0;
	while (pipes[i])
	{
		cmds[i] = parse_pieces_cmds(pipes[i]);
		i++;
	}
	cmds[i] = last;
	return (cmds);
}

void		get_cmds(t_minishell *minishell, char **commands)
{
	int		i;
	int		j;
	t_cmd	*new_cmd;

	i = 0;
	while (commands[i])
	{
		new_cmd = parse_pipe_cmds(commands[i]);
		j = 0;
		while (new_cmd->cmd)
		{
			/*exec_cmd(minishell, new_cmd[j]);*/
			j++;
		}
		free(new_cmd);
	}
}