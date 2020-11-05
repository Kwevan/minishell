/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:38:25 by afoulqui          #+#    #+#             */
/*   Updated: 2020/11/05 18:50:06 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_option(char *cmd)
{
	if (!ft_strncmp(cmd, "-n", 2))
		return (1);
	else
		return (0);
}

void		ft_echo(char **cmd)
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
			if (i < argc)
				ft_putstr_fd(" ", STDOUT_FILENO);
			i++;
		}
		if (j <= 1)
			ft_putstr_fd("\n", STDOUT_FILENO);
	}
	else
		ft_putstr_fd("\n", STDOUT_FILENO);
}
