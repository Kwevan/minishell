/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:38:25 by afoulqui          #+#    #+#             */
/*   Updated: 2020/12/03 12:27:46 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_option(char *cmd)
{
	int		i;
	int		opt;

	opt = 0;
	i = 0;
	if (cmd[i] == '-')
	{
		i++;
		while (cmd[i])
		{
			if (cmd[i] == 'n')
				opt = 1;
			else
				return (0);
			i++;
		}
	}
	return (opt);
}

void		ft_echo(t_minishell *minishell, char **cmd)
{
	int		argc;
	int		i;
	int		j;

	i = 0;
	argc = ft_countstrarr(cmd);
	if (argc > 1)
	{
		j = 1;
		while (cmd[j] && ft_check_option(cmd[j]) > 0)
			j++;
		i += j;
		while (cmd[i])
		{
			ft_putstr_fd(cmd[i], 1);
			if (i < argc && cmd[i + 1])
				ft_putstr_fd(" ", STDOUT_FILENO);
			i++;
		}
		if (j <= 1)
			ft_putstr_fd("\n", STDOUT_FILENO);
	}
	else
		ft_putstr_fd("\n", STDOUT_FILENO);
	minishell->ret = 0;
}
