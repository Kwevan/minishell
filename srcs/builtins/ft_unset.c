/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:25:33 by afoulqui          #+#    #+#             */
/*   Updated: 2020/11/17 17:07:59 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_minishell *minishell, char **cmd)
{
	int		i;
	int		argc;

	argc = ft_countstrarr(cmd);
	if (argc == 1)
	{
		minishell->ret = 0;
		return ;
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (ft_isenv(minishell, cmd[i]) == 1)
				remove_env(minishell, cmd[i]);
			i++;
		}
	}
	minishell->ret = 0;
}
