/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:40:22 by afoulqui          #+#    #+#             */
/*   Updated: 2020/12/03 11:25:19 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*get_path_cd(t_minishell *minishell, char *cmd)
{
	if (!cmd)
		return (ft_get_envv(minishell, minishell->env, "HOME"));
	else
		return (cmd);
}

static void		print_cderror(t_minishell *minishell, char *str, int code)
{
	if (code == 1)
		ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("cd: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	minishell->ret = 1;
}

void			ft_cd(t_minishell *minishell, char **cmd)
{
	char	*cwd;
	int		argc;

	cwd = NULL;
	argc = ft_countstrarr(cmd);
	minishell->ret = 0;
	if (chdir(get_path_cd(minishell, cmd[1])) < 0)
	{
		if (argc > 1)
			print_cderror(minishell, strerror(errno), 1);
		return ;
	}
	if (!(cwd = getcwd(NULL, 0)))
	{
		print_cderror(minishell, "error retrieving current directory: getcwd: "
		"cannot access parent directories: No such file or directory", 2);
		add_env(minishell,
		ft_strjoin(minishell->env[get_env_index(minishell, "PWD")], "/."));
		ft_editcwd(minishell, ft_get_envv(minishell, minishell->env, "PWD"));
		return ;
	}
	add_env(minishell, ft_strjoin("PWD=", cwd));
	ft_editcwd(minishell, ft_get_envv(minishell, minishell->env, "PWD"));
	ft_strdel(&cwd);
}
