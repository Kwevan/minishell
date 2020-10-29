/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:33:13 by afoulqui          #+#    #+#             */
/*   Updated: 2020/10/29 17:21:54 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_builtin(t_minishell *minishell, char **command)
{
	if (!ft_strcmp(command[0], "cd"))
		ft_putstr_fd("cd command", 1);
	else if (!ft_strcmp(command[0], "echo"))
		ft_echo(command);
	else if (!ft_strcmp(command[0], "env"))
		ft_putstr2(minishell->env);
	else if (!ft_strcmp(command[0], "pwd"))
		ft_pwd(minishell);
	else if (!ft_strcmp(command[0], "exit"))
		ft_exit(minishell, command + 1);
	else
		return (0);
	return (1);
}

int		exec_bin(t_minishell *minishell, char **command)
{
	char *bin_path;

	ft_putstr_fd(command[0], 1);
	bin_path = ft_get_bin_path(minishell, command[0]);
	minishell->pid = fork();
	if (minishell->pid == -1)
		perror("fork");
	else if (minishell->pid > 0)
	{
		waitpid(minishell->pid, &minishell->status, 0);
		kill(minishell->pid, SIGTERM);
	}
	else
	{
		if (execve(bin_path, command, minishell->env) == -1)
			perror("shell");
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	ft_exec_command(t_minishell *minishell, char **command)
{
	if (!exec_builtin(minishell, command))
		exec_bin(minishell, command);
}
