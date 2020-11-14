/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:11:11 by kwe               #+#    #+#             */
/*   Updated: 2020/11/14 14:48:21 by kwe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_remove_space(char *str)
{
	char	*ret;
	int		len;
	int		i;
	int		j;

	i = -1;
	j = -1;
	ret = NULL;
	len = 0;
	while (str[++i])
		if (str[i] != ' ' && str[i] != '\t')
			++len;
	i = -1;
	ret = ft_strnew(len);
	while (str[++i])
		if (str[i] != ' ' && str[i] != '\t')
			ret[++j] = str[i];
	if (j < 1)
		return (NULL);
	return (ret);
}

int		get_fd(int i, char *fname)
{
	int		fd;
	char	*parsed;

	fd = -1;
	if (!(parsed = ft_remove_space(fname)))
		return (-1);
	if (i)
		fd = open(parsed, O_APPEND | O_CREAT | O_WRONLY, S_IRWXU);
	else
		fd = open(parsed, O_TRUNC | O_CREAT | O_WRONLY, S_IRWXU);
	free(parsed);
	return (fd);
}

int		ft_redir(t_minishell *mini, char *cmd, int *fd_in, int last)
{
	(void)last;
	(void)mini;
	(void)fd_in;
	(void)cmd;
	int i;
	int fd;
	char *redir_cmd = NULL;
	char *redir_fname = NULL;
	int file = 0;
	int len = 0;
	i = 0;
	int old_fd;
	while (cmd[i])
	{
		if (cmd[i] == '>' || !cmd[i + 1])
		{
			if (file == 0 && cmd[i] == '>')
			{
				redir_cmd = ft_substr(cmd, 0, i);
				file = 1;
			}
			else if (file)
			{
				
				redir_fname = ft_substr(cmd, len, i - len + (cmd[i + 1] == 0));
				fd = get_fd(0, redir_fname);
				if (cmd [i + 1])
					ft_close(fd);
			}
			len = i + 1;
		}
			i++;
	}
	old_fd = dup(1);
	ft_exec_redir(mini, fd, redir_fname, redir_cmd);
	dup2(old_fd, 1);
	ft_close(old_fd);
	ft_close(fd);
	ft_strdel(&redir_cmd);
	ft_strdel(&redir_cmd);
	return (file);
}
