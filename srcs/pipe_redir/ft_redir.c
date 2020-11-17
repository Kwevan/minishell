/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:11:11 by kwe               #+#    #+#             */
/*   Updated: 2020/11/17 23:07:17 by kwe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_remove_space(char *str)
{
	int		i;

	i = 0;
	while (*str && (*str == ' '))
		str++;
	while (str[i] && str[i] != ' ')
		i++;
	return (ft_strndup(str, i));
}

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

int		ft_redir(t_minishell *mini, char *cmd, int *fd_in)
{
	int i;
	char *redir_cmd = NULL;
	char *redir_fname = NULL;
	int file = 0;
	int len = 0;
	int type;
	t_quotes quotes;

	type = 0;
	i = 0;
	mini->pipe[0] = 0;
	mini->pipe[1] = 1;
	ft_bzero(&quotes, sizeof(t_quotes));
	while (cmd[i])
	{
		if ((!ft_quote_open(&quotes, cmd[i]) && (cmd[i] == '>' || cmd[i] == '<')) || !cmd[i + 1])
		{
			if (file == 0 && (cmd[i] == '>' || cmd[i] == '<'))
			{
				redir_cmd = ft_substr(cmd, 0, i);
				file = 1;
			}
			else if (file)
			{
				redir_fname = ft_substr(cmd, len, i - len + (cmd[i + 1] == 0));
				if (get_fd(type, redir_fname, mini, 1) == -1)
					return (1);
			}
			if (cmd[i + 1])
			{
				ft_redir_type(cmd[i], cmd[i + 1], &type);
				if (type == 1)
					i++;
			}
			len = i + 1;
		}
		i++;
	}
	if (file && type != -1)
	{
		if (get_fd(type, redir_fname, mini, 0) == -1)
			return (1);
		ft_exec_redir(mini, mini->pipe, redir_cmd);
		if (type == 0 || type == 1)
			ft_close(mini->pipe[1]);
		else
			ft_close(mini->pipe[0]);
		ft_strdel(&redir_fname);
		ft_strdel(&redir_cmd);
		pipe(mini->pipe);
		close(mini->pipe[1]);
		dup2(mini->pipe[0], *fd_in);
		close(mini->pipe[0]);
	}
	return (file);
}
