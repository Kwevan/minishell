/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:11:11 by kwe               #+#    #+#             */
/*   Updated: 2020/11/23 15:23:16 by kwe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_fd(int type, char *fname, t_minishell *mini, int close)
{
	int		fd;
	char	*parsed;

	fd = -1;
	if (!(parsed = ft_remove_space(fname)))
		return (-1);
	if (type == 0)
		fd = open(parsed, O_TRUNC | O_CREAT | O_WRONLY, S_IRWXU);
	else if (type == 1)
		fd = open(parsed, O_APPEND | O_CREAT | O_WRONLY, S_IRWXU);
	else if (type == 2)
		fd = open(parsed, O_RDONLY);
	free(parsed);
	if (fd == -1)
	{
		ft_putstr_fd(strerror(errno), 1);
		return (-1);
	}
	if (type == 0 || type == 1)
		mini->pipe[1] = fd;
	else if (type == 2)
		mini->pipe[0] = fd;
	if (close)
		ft_close(fd);
	return (fd);
}

int		ft_get_redir_file(t_minishell *mini, t_redir *redir, char *cmd, int i)
{
	ft_strdel(&redir->redir_fname);
	redir->redir_fname = ft_substr(cmd, redir->start,
		i - redir->start + (cmd[i + 1] == 0));
	ft_join_redir(mini, redir, cmd + redir->start, i + (cmd[i + 1] == 0));
	if (get_fd(redir->type, redir->redir_fname, mini, 1) == -1)
	{
		ft_putstr_fd("Error redir", 2);
		return (1);
	}
	return (0);
}

int		ft_get_redir_cmd(t_minishell *mini, t_redir *redir, char *cmd, int i)
{
	redir->redir_cmd = ft_substr(cmd, 0, i);
	redir->redir = 1;
	while (cmd[i] == ' ' || cmd[i] == '>' || cmd[i] == '<')
		i += 1;
	if (!cmd[i])
	{
		mini->ret = 2;
		ft_putstr_fd("Parse error near \\n\n", 2);
		return (1);
	}
	return (0);
}

void	ft_init(int *i, t_redir *redir, t_quotes *quotes, t_minishell *mini)
{
	*i = 0;
	ft_bzero(redir, sizeof(t_redir));
	ft_bzero(quotes, sizeof(t_quotes));
	mini->pipe[0] = 0;
	mini->pipe[1] = 1;
}

int		ft_redir(t_minishell *mini, char *cmd, int *fd_in)
{
	int			i;
	t_redir		redir;
	t_quotes	quotes;

	ft_init(&i, &redir, &quotes, mini);
	while (cmd[i])
	{
		if ((!ft_quote_open(&quotes, cmd[i])
			&& (cmd[i] == '>' || cmd[i] == '<')) || !cmd[i + 1])
		{
			if (redir.redir == 0 && (cmd[i] == '>' || cmd[i] == '<'))
			{
				if (ft_get_redir_cmd(mini, &redir, cmd, i))
					return (1);
			}
			else if (redir.redir && ft_get_redir_file(mini, &redir, cmd, i))
				return (1);
			ft_redir_type(cmd[i], cmd[i + 1], &redir.type, &i);
			redir.start = i + 1;
		}
		i++;
	}
	return (ft_exec_redir(mini, &redir, fd_in));
}
