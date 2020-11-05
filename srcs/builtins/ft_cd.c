/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:40:22 by afoulqui          #+#    #+#             */
/*   Updated: 2020/11/05 21:06:41 by kwe              ###   ########.fr       */
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
	char	*cwd;
	char	*path;

	argc = ft_countstrarr(cmd);
	cwd = NULL;
	path = get_path_cd(minishell, cmd[1]);
	if (argc > 2)
		ft_putstr_fd("cd : too many arguments\n", STDOUT_FILENO);
	else if (chdir(path) < 0)
	{
		ft_putstr_fd("cd : ", 1);
		ft_putstr_fd(strerror(errno), 1);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	else
	{
		if (!(cwd = getcwd(NULL, 0)))
		{
			ft_putstr_fd(strerror(errno), 1);
			return ;
		}
		path = ft_strjoin("PWD=", cwd);
		add_env(minishell, path);
	}
}
