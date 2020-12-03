/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:25:33 by afoulqui          #+#    #+#             */
/*   Updated: 2020/12/03 12:50:58 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_checkunseterr(t_minishell *minishell, char *cmd)
{
	int		err_ret;

	err_ret = ft_isvalidenv(cmd);
	if (err_ret < 0)
	{
		ft_putstr_fd("minishell: unset: \" ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd(" \" : not a valid identifier\n", STDERR_FILENO);
		minishell->ret = 1;
		return (1);
	}
	return (0);
}

void		ft_unset(t_minishell *minishell, char **cmd)
{
	int		i;
	int		argc;

	argc = ft_countstrarr(cmd);
	minishell->ret = 0;
	if (argc == 1)
		return ;
	else
	{
		i = 1;
		while (i < argc)
		{
			if (ft_checkunseterr(minishell, cmd[i]) == 1)
				i++;
			else
			{
				if (ft_isenv(minishell, cmd[i]) == 1)
					remove_env(minishell, cmd[i]);
				i++;
			}
		}
	}
}
