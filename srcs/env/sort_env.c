/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:41:05 by afoulqui          #+#    #+#             */
/*   Updated: 2020/11/27 18:02:39 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		sort_env(char **env, int len)
{
	int		ord;
	int		i;
	char	*tmp;

	ord = 0;
	while (env && ord == 0)
	{
		ord = 1;
		i = 0;
		while (i < len - 1)
		{
			if (ft_strcmp(env[i], env[i + 1]) > 0)
			{
				tmp = env[i];
				env[i] = env[i + 1];
				env[i + 1] = tmp;
				ord = 0;
			}
			i++;
		}
		len--;
	}
}

static void		print_env(char *env)
{
	char	*key;
	char	*value;
	int		i;

	value = NULL;
	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	key = ft_strndup(env, i);
	if (env[i] == '=')
		value = ft_strdup(&env[++i]);
	ft_putstr_fd("declare -x ", STDOUT_FILENO);
	ft_putstr_fd(key, STDOUT_FILENO);
	if (value)
	{
		ft_putstr_fd("=\"", STDOUT_FILENO);
		ft_putstr_fd(value, STDOUT_FILENO);
		ft_putstr_fd("\"", STDOUT_FILENO);
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
	ft_strdel(&value);
	ft_strdel(&key);
}

void			print_sortenv(t_minishell *minishell)
{
	int		i;
	int		j;
	int		argc;
	char	**tmp;

	argc = ft_countstrarr(minishell->env);
	tmp = (char **)ft_calloc(sizeof(char *), argc + 1);
	i = 0;
	j = 0;
	while (i < argc)
	{
		tmp[j] = ft_strdup(minishell->env[i]);
		i++;
		j++;
	}
	sort_env(tmp, ft_countstrarr(tmp));
	i = 0;
	while (i < argc)
	{
		print_env(tmp[i]);
		i++;
	}
	ft_freestrarr(tmp);
	minishell->ret = 0;
}
