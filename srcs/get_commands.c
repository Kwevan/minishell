/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:56:24 by afoulqui          #+#    #+#             */
/*   Updated: 2020/10/13 17:53:32 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd		parse_pieces_cmds(char *cmd)
{
	int		i;
	char	**pieces;
	t_cmd	res;

	pieces = ft_split_quote(cmd, " ");
	free(cmd);
	i = 0;
	while (pieces[i])
	{
		pieces[i] = ft_removequotes(pieces[i]);
		printf("\n%s\n", pieces[i]);
		i++;
	}
	res.cmd = pieces[0];
	res.argc = ft_countstrarr(pieces) + 1;
	if (!(res.args = ft_calloc(sizeof(char *), res.argc)))
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

	pipes = ft_split_quote(cmd, "|");
	free(cmd);
	last.cmd = NULL;
	count = ft_countstrarr(pipes) + 1;
	if (!(cmds = ft_calloc(sizeof(t_cmd), count)))
		return (NULL);
	i = 0;
	while (pipes[i])
	{
		if (ft_isonlyspaces(pipes[i]))
			cmds[i] = parse_pieces_cmds(pipes[i]);
		else
			free(pipes[i]);
		i++;
	}
	ft_freestrarr(pipes);
	cmds[i] = last;
	return (cmds);
}

void		get_cmds(char **commands)
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
	ft_freestrarr(commands);
}