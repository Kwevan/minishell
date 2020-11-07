/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:46:45 by kgouacid          #+#    #+#             */
/*   Updated: 2020/11/07 19:47:25 by yay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec_pipe(t_minishell *mini, char *cmd, int *fd_in, int last)
{
	int		p[2];
	pid_t	pid;
	int		i;
	
(void)mini;(void)fd_in;(void)last;
	i = 0;
	pipe(p);
	if ((pid = fork()) == -1)
		exit_shell(mini, 1);//faddut free commands ou simplement strerror puis quitter la boucle de pipe... flemme
	if (pid == 0)// 0 == child
	{
		dup2(*fd_in, 0);
		if (!last)
			dup2(p[1], 1);
		close(p[0]);
		
		char **splitted = ft_split_quote(cmd, " ");
		char  **parsed = ft_parse(mini, splitted);
		ft_exec_command(mini, parsed);
		exit (0);
	}
	else
	{
		close(p[1]);
		dup2(p[0], *fd_in);
		close(p[0]);
	}

	while (cmd[i])
	{
		ft_putchar_fd(cmd[i], 1);
		i++;
	}

	
}

void	ft_pipe_redir(t_minishell *mini, char *cmd)
{
	int old_stdin;
	int fd_in;
	int i;
	char **splitted;

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
