/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:23:30 by kwe               #+#    #+#             */
/*   Updated: 2020/11/18 14:18:06 by kwe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec_redir3(t_minishell *mini, char **parsed)
{
	char *bin_path;

	bin_path = NULL;
	if (!exec_builtin(mini, parsed))
	{
		bin_path = ft_get_bin_path(mini, parsed[0]);
		if ((execve(bin_path, parsed, mini->env)) == -1)
			ft_putendl_fd(strerror(errno), 2);
		ft_strdel(&bin_path);
	}
}

int		ft_exec_redir2(t_minishell *mini, int std[2], char *cmd)
{
	char **splitted;
	char **parsed;

	mini->pid = fork();
	if (mini->pid == -1)
		ft_putstr_fd("Error: fork", 2);
	else if (mini->pid == 0)
	{
		dup2(std[0], STDIN_FILENO);
		dup2(std[1], STDOUT_FILENO);
		splitted = ft_split_quote(cmd, " ");
		parsed = ft_parse(mini, splitted);
		ft_exec_redir3(mini, parsed);
		ft_freestrarr(parsed);
		exit(EXIT_SUCCESS);
	}
	else
		wait(&mini->pid);
	return (0);
}

int		ft_exec_redir(t_minishell *mini, t_redir *redir, int *fd_in)
{
	if (redir->redir && redir->type != -1)
	{
		if (get_fd(redir->type, redir->redir_fname, mini, 0) == -1)
			return (1);
		ft_exec_redir2(mini, mini->pipe, redir->redir_cmd);
		if (redir->type == 0 || redir->type == 1)
			ft_close(mini->pipe[1]);
		else
			ft_close(mini->pipe[0]);
		ft_strdel(&redir->redir_fname);
		ft_strdel(&redir->redir_cmd);
		pipe(mini->pipe);
		close(mini->pipe[1]);
		dup2(mini->pipe[0], *fd_in);
		close(mini->pipe[0]);
	}
	return (redir->redir);
}
