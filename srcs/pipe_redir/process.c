/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:35:32 by kwe               #+#    #+#             */
/*   Updated: 2020/12/03 12:39:17 by kwe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_process(t_minishell *mini)
{
	mini->pids = ft_realloc(mini->pids,
		mini->pcount * sizeof(int), (mini->pcount + 1) * sizeof(int));
	mini->pids[mini->pcount] = mini->pid;
	mini->pcount++;
}
