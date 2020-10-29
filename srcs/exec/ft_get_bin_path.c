/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bin_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:44:09 by kgouacid          #+#    #+#             */
/*   Updated: 2020/10/29 17:17:55 by kgouacid         ###   ########.fr       */
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
	folders = ft_split(path, ':');
	while (folders[i])
	{
		bin_path = ft_strjoin2(folders[i], "/", bin);
		if (!stat(bin_path, &buf))
			break ;
		free(bin_path);
		bin_path = NULL;
		i++;
	}
	ft_freestrarr(folders);
	if (!bin_path)
		bin_path = ft_strdup(bin);
	return (bin_path);
}
