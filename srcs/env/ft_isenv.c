/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:58:52 by afoulqui          #+#    #+#             */
/*   Updated: 2020/11/09 18:51:23 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_isenv(t_minishell *minishell, char *var)
{
	char	**split;
	char	*key;
	int		i;

	i = 0;
	while (minishell->env[i])
	{
		split = ft_split(minishell->env[i], '=');
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
