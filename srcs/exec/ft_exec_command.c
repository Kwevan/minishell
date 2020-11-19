/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:33:13 by afoulqui          #+#    #+#             */
/*   Updated: 2020/11/19 16:42:05 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_builtin(t_minishell *minishell, char **command)
{
	if (!ft_strcmp(command[0], "cd"))
		ft_cd(minishell, command);
	else if (!ft_strcmp(command[0], "echo"))
		ft_echo(minishell, command);
	else if (!ft_strcmp(command[0], "env"))
		ft_env(minishell);
	else if (!ft_strcmp(command[0], "pwd"))
		ft_pwd(minishell);
	else if (!ft_strcmp(command[0], "exit"))
		ft_exit(minishell, command + 1);
	else if (!ft_strcmp(command[0], "unset"))
		ft_unset(minishell, command);
	else if (!ft_strcmp(command[0], "export"))
		ft_export(minishell, command);
	else
		return (0);
	return (1);
}

int		exec_bin(t_minishell *minishell, char **command)
{
	char *bin_path;

	bin_path = ft_get_bin_path(minishell, command[0]);
	minishell->pid = fork();
	if (minishell->pid == -1)
		ft_putstr_fd(strerror(errno), 1);
	else if (minishell->pid > 0)
	{
		waitpid(minishell->pid, &minishell->ret, 0);
		kill(minishell->pid, SIGTERM);
	}
	else
	{
		if (execve(bin_path, command, minishell->env) == -1)
			ft_putstr_fd(strerror(errno), 1);
		ft_strdel(&bin_path);
		exit(EXIT_SUCCESS);
	}
	ft_strdel(&bin_path);
	return (0);
}

void	ft_exec_command(t_minishell *minishell, char **command)
{
	if (!exec_builtin(minishell, command))
		exec_bin(minishell, command);
}
