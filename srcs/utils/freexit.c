/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freexit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:07:44 by afoulqui          #+#    #+#             */
/*   Updated: 2020/10/28 17:14:05 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(t_minishell *minishell, int status)
{
	if (minishell->env)
		ft_freestrarr(minishell->env);
	if (minishell->input)
		free(minishell->input);
	if (minishell)
		minishell = NULL;
	exit(status);
}
