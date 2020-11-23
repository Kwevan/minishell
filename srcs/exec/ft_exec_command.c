/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:33:13 by afoulqui          #+#    #+#             */
/*   Updated: 2020/11/21 12:08:25 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				exec_builtin(t_minishell *minishell, char **command)
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

int				print_errorcmd(char *cmd, int code)
{
	if (code == 1)
		ft_putstr_fd("minishell: fork error\n", STDOUT_FILENO);
	else if (code == 2)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
	}
	return (127);
}

void			exec_bin(t_minishell *minishell, char **command)
{
	char *bin_path;

	minishell->pid = fork();
	if (minishell->pid == -1)
		exit(print_errorcmd(command[0], 1));
	else if (minishell->pid > 0)
	{
		waitpid(minishell->pid, &minishell->ret, 0);
		kill(minishell->pid, SIGTERM);
		if (WEXITSTATUS(minishell->ret))
			minishell->ret = WEXITSTATUS(minishell->ret);
	}
	else
	{
		bin_path = ft_get_bin_path(minishell, command[0]);
		if (execve(bin_path, command, minishell->env) == -1)
		{
			ft_strdel(&bin_path);
			exit(print_errorcmd(command[0], 2));
		}
		ft_strdel(&bin_path);
		exit(EXIT_SUCCESS);
	}
	minishell->pid = 0;
}

void			ft_exec_command(t_minishell *minishell, char **command)
{
	if (!exec_builtin(minishell, command))
		exec_bin(minishell, command);
}
