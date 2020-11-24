/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_envv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 12:35:48 by kgouacid          #+#    #+#             */
/*   Updated: 2020/11/24 00:16:01 by kwe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_envv(t_minishell *mini, char **env, char *var)
{
	int	i;
	int same_len;

	(void)mini;
	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
	{
		same_len = (ft_index(env[i], '=') == (int)ft_strlen(var));
		if (same_len && (!ft_strncmp(env[i], var, ft_index(env[i], '='))))
			return (ft_strchr(env[i], '=') + 1);
		i++;
	}
	return (NULL);
}
