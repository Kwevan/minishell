/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:00:03 by afoulqui          #+#    #+#             */
/*   Updated: 2020/11/05 18:50:51 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_env_index(t_minishell *minishell, char *var)
{
	int		i;
	int		len;
	char	*key;
	char	**split;

	split = ft_split(var, '=');
	key = ft_strdup(split[0]);
	ft_freestrarr(split);
	len = ft_strlen(key);
	i = 0;
	while (minishell->env[i])
	{
		if (!strncmp(minishell->env[i], key, len))
		{
			free(key);
			return (i);
		}
		i++;
	}
	free(key);
	return (-1);
}

void		remove_env(t_minishell *minishell, char *var, int len)
{
	int		i;
	int		j;
	int		index;
	char	**tmp_env;

	index = get_env_index(minishell, var);
	if (index == -1)
		return ;
	tmp_env = (char **)ft_calloc(sizeof(char *), len + 1);
	if (tmp_env == NULL)
		return ;
	i = 0;
	j = 0;
	while (minishell->env[i])
	{
		if (i != index)
		{
			tmp_env[j] = ft_strdup(minishell->env[i]);
			j++;
		}
		i++;
	}
	ft_freestrarr(minishell->env);
	minishell->env = tmp_env;
}

void		add_env(t_minishell *minishell, char *var)
{
	char	**tmp_env;
	int		i;
	int		len;

	len = ft_countstrarr(minishell->env);
	remove_env(minishell, var, len);
	tmp_env = (char **)ft_calloc(sizeof(char *), len + 2);
	if (tmp_env == NULL)
		return ;
	i = 0;
	while (minishell->env[i])
	{
		tmp_env[i] = ft_strdup(minishell->env[i]);
		i++;
	}
	tmp_env[i] = ft_strdup(var);
	ft_freestrarr(minishell->env);
	minishell->env = tmp_env;
}
