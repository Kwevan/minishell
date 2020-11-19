/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:17:47 by afoulqui          #+#    #+#             */
/*   Updated: 2020/11/19 16:21:25 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		print_exporterror(int error, char *arg)
{
	int		j;

	if (error == -1)
		ft_putstr_fd("export: not valid in this context: ", STDOUT_FILENO);
	else if (error == -2)
		ft_putstr_fd("zsh: bad assignment", STDOUT_FILENO);
	else if (error == -3)
		ft_putstr_fd("export: not an identifier: ", STDOUT_FILENO);
	j = 0;
	while (arg[j] && arg[j] != '=')
	{
		write(STDOUT_FILENO, &arg[j], 1);
		j++;
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
}

static int		ft_checkexporterr(t_minishell *minishell, char *cmd)
{
	int		err_ret;

	err_ret = ft_isvalidenv(cmd);
	if (err_ret < 0)
	{
		print_exporterror(err_ret, cmd);
		minishell->ret = 1;
		return (1);
	}
	minishell->ret = 0;
	return (0);
}

void			ft_export(t_minishell *minishell, char **cmd)
{
	int		i;
	int		argc;

	argc = ft_countstrarr(cmd);
	if (argc == 1)
		print_sortenv(minishell);
	else
	{
		i = 1;
		while (i < argc)
		{
			if (ft_checkexporterr(minishell, cmd[i]) == 1)
				return ;
			if (check_equality(cmd[i]))
				add_env(minishell, cmd[i]);
			else
				add_env(minishell, ft_strjoin(cmd[i], "=''"));
			i++;
		}
	}
	minishell->ret = 0;
}
