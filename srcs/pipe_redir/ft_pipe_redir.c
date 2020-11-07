/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:46:45 by kgouacid          #+#    #+#             */
/*   Updated: 2020/11/04 16:58:35 by yay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec_pipe_redir(char *cmd, int start, int end, int leftp, int *rightp)
{

	while (cmd[start] && start < end)
	{
		ft_putchar_fd(cmd[start], 1);
		start++;
	}
	
}

void	ft_pipe_redir(t_minishell *mini, char *cmd)
{
	(void)mini;
	(void)cmd;
	// ex de cmd = ls | wc
	// boucle sur la cmd, si on a un pipe exec pipe
	// a la fin de la boucle on fait quoi ?
	// si on a un pipe on balance le mot dans ft_exec_pipe
	// exec pipe va pipe et 
	int i;
	int start;
	int rightp;

	i = 0;
	start = 0;
	rightp = 0;
	while (cmd[i])
	{
		if (strchr("<|", cmd[i] )) //weak evidemment
			ft_exec_pipe_redir(cmd, start, i, 1, &right);
		i++;
	}
}
