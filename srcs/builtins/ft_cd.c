/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:40:22 by afoulqui          #+#    #+#             */
/*   Updated: 2020/11/17 16:51:07 by afoulqui         ###   ########.fr       */
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

static void		print_cderror(t_minishell *minishell, char *str)
{
	ft_putstr_fd("cd : ", STDOUT_FILENO);
	ft_putstr_fd(str, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	minishell->ret = 1;
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
		print_cderror(minishell, "too many arguments");
	else if (chdir(path) < 0)
		print_cderror(minishell, strerror(errno));
	else
	{
		if (!(cwd = getcwd(NULL, 0)))
		{
			print_cderror(minishell, strerror(errno));
			free(path);
			return ;
		}
		path = ft_strjoin("PWD=", cwd);
		add_env(minishell, path);
		minishell->ret = 0;
	}
	free(cwd);
	free(path);
}
