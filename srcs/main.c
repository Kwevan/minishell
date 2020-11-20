/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:00:39 by afoulqui          #+#    #+#             */
/*   Updated: 2020/11/20 15:05:49 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell		minishell;

static void		handle_ctrl_c(int signal)
{
	ft_putstr_fd("\n", STDOUT_FILENO);
	if (!(minishell.pid))
	{
		minishell.ret = 130;
		ft_prompt_msg();
	}
	else
		kill(minishell.pid, signal);
}

static void		handle_ctrl_bl(int signal)
{
	char	*str_signal;

	str_signal = ft_itoa(signal);
	if (minishell.pid)
	{
		kill(minishell.pid, signal);
		minishell.ret = 131;
		ft_putstr_fd("\nQuit : ", STDERR_FILENO);
		ft_putstr_fd(str_signal, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	free(str_signal);
}

void			handle_signal()
{
	if (signal(SIGINT, &handle_ctrl_c) == SIG_ERR)
		ft_putstr_fd("SIGINT error", STDOUT_FILENO);
	if (signal(SIGQUIT, &handle_ctrl_bl) == SIG_ERR)
		ft_putstr_fd("SIGQUIT error", STDOUT_FILENO);
}

static void		init_env(t_minishell *minishell, char **env)
{
	int			i;
	int			len;

	len = ft_strlen2(env);
	minishell->env = (char **)ft_calloc(sizeof(char *), (len + 1));
	if (!(minishell->env))
		exit_shell(minishell, 1);
	i = 0;
	while (env[i])
	{
		minishell->env[i] = ft_strdup(env[i]);
		if (!(minishell->env[i]))
			exit_shell(minishell, 1);
		i++;
	}
}

int				main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	ft_bzero(&minishell, sizeof(t_minishell));
	ft_putstr_fd("\nMINISHELL 42 by kgouacid & afoulqui\n\n", 1);
	init_env(&minishell, env);
	while (1)
	{
		ft_prompt_msg();
		handle_signal();
		get_input(&minishell);
		handle_input(&minishell);
	}
	return (0);
}
