/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:11:11 by kwe               #+#    #+#             */
/*   Updated: 2020/11/12 17:49:05 by kwe              ###   ########.fr       */
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

	int file = 0;
	int len = 0;
	i = 0;
//	if (!ft_detect_redir(mini))
	int old_fd = dup(1);
	while (cmd[i])
	{
		if (cmd[i] == '>' || !cmd[i + 1])
		{
			if (file == 0)
			{
			//char *redir_cmd = ft_substr(cmd, 0, i);
			file = 1;
			}
			else
			{
				char *redir_fname = ft_substr(cmd, len, i);
				int fd = get_fd(0, redir_fname);
				dup2(fd, 1);
				close (fd);
				ft_putstr_fd(redir_fname, 1);
				free(redir_fname);
				dup2(old_fd, 1);
			}
			len = i + 1; // si ya d espaces on est niqué bien profond
		}
			i++;
	}

//		return (0);
	return (1);
}
