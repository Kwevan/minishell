/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:49:34 by kgouacid          #+#    #+#             */
/*   Updated: 2020/10/28 19:53:51 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_arg(char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) || (arg[i] == '-') || (arg[i] == '+'))
			return (0);
		i++;
	}
	return (1);
}

void	ft_set_exit_status(t_minishell *mini, char *arg)
{
	if (arg)
	{
		if (ft_check_arg(arg) && ft_strlen(arg) < 17)
			mini->ret = ft_atoi(arg);
		else
		{
			ft_putstr_fd("bash: exit: ", STDERR_FILENO);
			ft_putstr_fd(arg, STDERR_FILENO);
			ft_putstr_fd(" numeric argument require", STDERR_FILENO);
		}
	}
}

void	ft_exit(t_minishell *mini, char **args)
{
	if (args[0] && args[1])
	{
		ft_putstr_fd("bash: exit: too many arguments", STDERR_FILENO);
		mini->ret = 1;
		return ;
	}
	ft_set_exit_status(mini, args[0]);
	exit_shell(mini, mini->ret);
}
