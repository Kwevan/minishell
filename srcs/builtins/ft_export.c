/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:17:47 by afoulqui          #+#    #+#             */
/*   Updated: 2020/12/01 17:40:46 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_updateenv(t_minishell *minishell, char *env_update)
{
	char	**split;
	char	*key;
	char	*value;
	char	*new_env;
	int		ret;

	split = ft_split2(env_update, "+=");
	key = ft_strdup(split[0]);
	value = ft_strdup(split[1]);
	ft_freestrarr(split);
	ret = get_env_index(minishell, key);
	if (ret < 0)
		new_env = ft_strjoin2(key, "=", value);
	else
		new_env = ft_strjoin(minishell->env[ret], value);
	add_env(minishell, new_env);
	ft_strdel(&key);
	ft_strdel(&value);
}

static int		ft_checkexporterr(t_minishell *minishell, char *cmd)
{
	int		err_ret;

	err_ret = ft_isvalidenv(cmd);
	if (err_ret < 0)
	{
		ft_putstr_fd("minishell: export: \" ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd(" \" : not a valid identifier\n", STDERR_FILENO);
		minishell->ret = 1;
		return (1);
	}
	minishell->ret = 0;
	return (0);
}

void			ft_export(t_minishell *minishell, char **cmd)
{
	int		i;
	int		argc;

	argc = ft_countstrarr(cmd);
	if (argc == 1)
		print_sortenv(minishell);
	else
	{
		i = 1;
		while (i < argc)
		{
			if (ft_checkexporterr(minishell, cmd[i]) == 1)
				return ;
			else if (check_plus(cmd[i]) > 0)
				ft_updateenv(minishell, cmd[i]);
			else
				add_env(minishell, ft_strdup(cmd[i]));
			i++;
		}
	}
	minishell->ret = 0;
}
