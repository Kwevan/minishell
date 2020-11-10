/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:11:11 by kwe               #+#    #+#             */
/*   Updated: 2020/11/10 15:20:58 by kwe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int		get_fd(int i, char *fname)
{
	if (i)
		return (open(fname, O_APPEND | O_CREAT | O_WRONLY, S_IRWXU));
	else
		return (open(fname, O_TRUNC | O_CREAT | O_WRONLY, S_IRWXU));
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
				ft_putstr_fd(redir_fname, 1);
				free(redir_fname);
				close (fd);
								
			}
			len = i + 1; // si ya d espaces on est niqué bien profond
		}
			i++;
	}

//		return (0);
	return (1);
}
