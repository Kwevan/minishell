/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bin_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:44:09 by kgouacid          #+#    #+#             */
/*   Updated: 2020/11/27 17:50:40 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_bin_path(t_minishell *mini, char *bin)
{
	char		*path;
	char		**folders;
	char		*bin_path;
	struct stat	buf;
	int			i;

	i = 0;
	path = ft_get_envv(mini, mini->env, "PATH");
	if (!(folders = ft_split2(path, ":")))
		exit_shell(mini, EXIT_FAILURE);
	while (folders[i])
	{
		if (!(bin_path = ft_strjoin2(folders[i], "/", bin)))
		{
			ft_freestrarr(folders);
			exit_shell(mini, EXIT_FAILURE);
		}
		if (!stat(bin_path, &buf))
			break ;
		ft_strdel(&bin_path);
		i++;
	}
	ft_freestrarr(folders);
	return (bin_path ? bin_path : ft_strdup(bin));
}
