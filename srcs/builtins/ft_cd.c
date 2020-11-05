/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:40:22 by afoulqui          #+#    #+#             */
/*   Updated: 2020/11/05 17:57:47 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*get_path_cd(t_minishell *minishell, char *cmd)
{
	char	*path;

	if (!cmd)
		path = ft_get_envv(minishell, minishell->env, "HOME");
	else
		path = ft_strdup(cmd);
	return (path);
}

void			ft_cd(t_minishell *minishell, char **cmd)
{
	int		argc;
	char	cwd[4096];
	char	*path;

	argc = ft_countstrarr(cmd);
	path = get_path_cd(minishell, cmd[1]);
	if (argc > 2)
	{
		ft_putstr_fd("cd : too many arguments\n", STDOUT_FILENO);
	}
	else if (chdir(path) < 0)
	{
		ft_putstr_fd("cd : no such file or directory : ", STDOUT_FILENO);
		ft_putstr_fd(cmd[1], STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	else
	{
		getcwd(cwd, 4096);
		path = ft_strjoin("PWD=", cwd);
		add_env(minishell, path);
	}
}
