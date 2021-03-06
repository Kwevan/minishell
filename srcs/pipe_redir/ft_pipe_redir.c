/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:46:45 by kgouacid          #+#    #+#             */
/*   Updated: 2020/12/03 14:32:24 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parent(t_minishell *mini, int p[2], int fd_in, int last)
{
	(void)last;
	ft_add_process(mini);
	ft_close(p[1]);
	ft_close(fd_in);
	if (!last)
		dup2(p[0], fd_in);
	ft_close(p[0]);
}

void	ft_exec_pipe_cmd(t_minishell *mini, char **parsed)
{
	char *bin_path;

	bin_path = NULL;
	if (!exec_builtin(mini, parsed))
	{
		bin_path = ft_get_bin_path(mini, parsed[0]);
		if ((execve(bin_path, parsed, mini->env)) == -1)
		{
			ft_strdel(&bin_path);
			exit(print_errorcmd(parsed[0], 2));
		}
		ft_strdel(&bin_path);
	}
}

void	ft_exec_pipe(t_minishell *mini, char *cmd, int *fd_in, int last)
{
	int		p[2];
	char	**splitted;
	char	**parsed;

	pipe(p);
	if ((mini->pid = fork()) == -1)
		ft_putstr_fd(strerror(errno), 2);
	if (mini->pid == 0)
	{
		dup2(*fd_in, 0);
		if (!last)
			dup2(p[1], 1);
		else
			ft_close(p[1]);
		ft_close(p[0]);
		splitted = ft_split_quote(cmd, " ");
		parsed = ft_parse(mini, splitted);
		ft_exec_pipe_cmd(mini, parsed);
		ft_freestrarr(parsed);
		exit(mini->ret);
	}
	else
		ft_parent(mini, p, *fd_in, last);
}

void	ft_wait(t_minishell *mini, char ***splitted)
{
	int i;

	i = 0;
	while (i < mini->pcount)
	{
		waitpid(mini->pids[i], &mini->ret, WUNTRACED);
		i++;
	}
	if (WEXITSTATUS(mini->ret))
		mini->ret = WEXITSTATUS(mini->ret);
	mini->pcount = 0;
	mini->pid = 0;
	ft_strdel((void *)&mini->pids);
	ft_freestrarr(*splitted);
}

int		ft_pipe_redir(t_minishell *mini, char *cmd)
{
	int		old_stdin;
	int		fd_in;
	int		i;
	char	**splitted;

	if (!ft_is_pipe_or_redir(cmd))
		return (0);
	if (!ft_check_pipe(mini, cmd))
		return (1);
	mini->pids = malloc(sizeof(int));
	mini->pids[0] = 0;
	splitted = ft_split_quote(cmd, "|");
	i = 0;
	fd_in = 0;
	old_stdin = dup(0);
	while (splitted[i])
	{
		if (!ft_redir(mini, splitted[i], &fd_in))
			ft_exec_pipe(mini, splitted[i], &fd_in, (splitted[i + 1] == 0));
		i++;
	}
	dup2(old_stdin, 0);
	ft_close(old_stdin);
	ft_wait(mini, &splitted);
	return (1);
}
