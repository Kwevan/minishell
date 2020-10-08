/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freexit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:07:44 by afoulqui          #+#    #+#             */
/*   Updated: 2020/10/05 14:05:14 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(t_minishell *minishell)
{
	if (minishell->env)
		ft_freestrarr(minishell->env);
	if (minishell->input)
		free(minishell->input);
	if (minishell->env)
		ft_freestrarr(minishell->commands);
	if (minishell)
		minishell = NULL;
	ft_putstr_fd("\n", 1);
	exit(0);
}
