/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freexit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:07:44 by afoulqui          #+#    #+#             */
/*   Updated: 2020/09/30 18:03:12 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_freestrarr(char **arr)
{
	int		i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void	exit_shell(t_minishell *minishell)
{
	if (minishell->env)
		ft_freestrarr(minishell->env);
	if (minishell)
	{
		free(minishell);
		minishell = NULL;
	}
	ft_putstr_fd("\n", 1);
	exit(0);
}