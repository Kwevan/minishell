/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:08:46 by afoulqui          #+#    #+#             */
/*   Updated: 2020/11/17 17:11:24 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_var(char *env)
{
	int		i;
	char	**split;
	char	*key;

	split = ft_split(env, '=');
	key = ft_strdup(split[0]);
	ft_freestrarr(split);
	i = 0;
	while (key[i])
	{
		if ((key[i] < 65 || key[i] > 90) && key[i] != '_')
		{
			free(key);
			return (0);
		}
		i++;
	}
	free(key);
	return (1);
}

void		ft_env(t_minishell *minishell)
{
	int		i;

	i = 0;
	while (minishell->env[i])
	{
		if (check_var(minishell->env[i]) && check_equality(minishell->env[i]))
		{
			ft_putstr_fd(minishell->env[i], STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		i++;
	}
	minishell->ret = 0;
}
