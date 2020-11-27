/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:58:52 by afoulqui          #+#    #+#             */
/*   Updated: 2020/11/27 17:49:33 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_plus(char *var)
{
	int		i;

	i = 0;
	while (var[i])
	{
		if (i != 0 && var[i - 1] == '+' && var[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int		check_equality(char *var)
{
	int		i;

	if (!ft_strlen(var))
		return (-1);
	i = 0;
	while (var[i])
	{
		if (i == 0 && var[i] == '=')
			return (-1);
		if (var[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int		ft_isvalidenv(char *env)
{
	int		i;
	int		len;
	char	**split;

	if (ft_isdigit(env[0]) == 1)
		return (-1);
	if (env[0] == '=')
		return (-2);
	split = ft_split2(env, "=");
	len = ft_strlen(split[0]);
	i = 0;
	while (split[0][i])
	{
		if (ft_isalnum(split[0][i]) == 0 && split[0][len - 1] != '+')
		{
			ft_freestrarr(split);
			return (-3);
		}
		i++;
	}
	ft_freestrarr(split);
	return (1);
}

int		ft_isenv(t_minishell *minishell, char *var)
{
	char	**split;
	char	*key;
	int		i;

	i = 0;
	while (minishell->env[i])
	{
		split = ft_split2(minishell->env[i], "=");
		key = ft_strdup(split[0]);
		ft_freestrarr(split);
		if (!strcmp(key, var))
		{
			free(key);
			return (1);
		}
		free(key);
		i++;
	}
	return (0);
}
