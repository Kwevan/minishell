/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:00:30 by kgouacid          #+#    #+#             */
/*   Updated: 2020/11/22 21:35:42 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_error(t_minishell *mini, int ret)
{
	ft_putendl_fd("Error with |", STDERR_FILENO);
	mini->ret = 2;
	mini->pipe_err = 1;
	return (ret);
}

int		ft_check_pipe(t_minishell *mini, char *cmd)
{
	int			i;
	t_quotes	quotes;
	int			counter;
	int			open;

	i = 0;
	counter = 0;
	open = 0;
	while (cmd[i] == ' ')
		i++;
	if (cmd[i] == '|')
		return (ft_error(mini, 0));
	ft_bzero(&quotes, sizeof(t_quotes));
	while (cmd[i])
	{
		open = ft_quote_open(&quotes, cmd[i]);
		if (!open && cmd[i] == '|')
			counter ++;
		if (!open && counter == 1 && cmd[i] != ' '  && cmd[i] != '|')
			counter--;
		if (counter == 2)
			return (ft_error(mini, 0));
		i++;
	}
	if (counter == 1)
		return (ft_error(mini, 0));
	return (1);
}
