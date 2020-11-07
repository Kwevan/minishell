/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:46:45 by kgouacid          #+#    #+#             */
/*   Updated: 2020/11/07 21:01:43 by kwe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec_pipe(t_minishell *mini, char *cmd, int *fd_in, int last)
{
	int		p[2];
	int		i;
	char	*bin_path;
	char	**splitted;
	char	**parsed;

	i = 0;
	pipe(p);
	if ((mini->pid = fork()) == -1)
		ft_putstr_fd(strerror(errno), 1);
	if (mini->pid == 0)
	{
		dup2(*fd_in, 0);
		if (!last)
			dup2(p[1], 1);
		close(p[0]);
		splitted = ft_split_quote(cmd, " ");
		parsed = ft_parse(mini, splitted);
		bin_path = ft_get_bin_path(mini, parsed[0]);
		if (!exec_builtin(mini, parsed))
		{
			bin_path = ft_get_bin_path(mini, parsed[0]);
			if (execve(bin_path, parsed, mini->env) == -1)
				ft_putstr_fd(strerror(errno), 1);
			ft_strdel(&bin_path);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(&mini->pid);
		close(p[1]);
		dup2(p[0], *fd_in);
		close(p[0]);
	}
}

void	ft_pipe_redir(t_minishell *mini, char *cmd)
{
	int		old_stdin;
	int		fd_in;
	int		i;
	char	**splitted;

	splitted = ft_split_quote(cmd, "|");
	i = 0;
	fd_in = 0;
	old_stdin = dup(0);
	while (splitted[i])
	{
		if (1)
			ft_exec_pipe(mini, splitted[i], &fd_in, (splitted[i + 1] == 0));
		i++;
	}
	dup2(old_stdin, 0);
	ft_freestrarr(splitted);
}
