/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:00:39 by afoulqui          #+#    #+#             */
/*   Updated: 2020/11/20 16:28:09 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell		g_minishell;

static void		handle_ctrl_c(int signal)
{
	ft_putstr_fd("\n", STDOUT_FILENO);
	if (!(g_minishell.pid))
	{
		g_minishell.ret = 130;
		ft_prompt_msg();
	}
	else
		kill(g_minishell.pid, signal);
}

static void		handle_ctrl_bl(int signal)
{
	char	*str_signal;

	str_signal = ft_itoa(signal);
	if (g_minishell.pid)
	{
		kill(g_minishell.pid, signal);
		g_minishell.ret = 131;
		ft_putstr_fd("\nQuit : ", STDERR_FILENO);
		ft_putstr_fd(str_signal, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	free(str_signal);
}

void			handle_signal(void)
{
	if (signal(SIGINT, &handle_ctrl_c) == SIG_ERR)
		ft_putstr_fd("SIGINT error", STDOUT_FILENO);
	if (signal(SIGQUIT, &handle_ctrl_bl) == SIG_ERR)
		ft_putstr_fd("SIGQUIT error", STDOUT_FILENO);
}

static void		init_env(char **env)
{
	int			i;
	int			len;

	len = ft_strlen2(env);
	g_minishell.env = (char **)ft_calloc(sizeof(char *), (len + 1));
	if (!(g_minishell.env))
		exit_shell(&g_minishell, 1);
	i = 0;
	while (env[i])
	{
		g_minishell.env[i] = ft_strdup(env[i]);
		if (!(g_minishell.env[i]))
			exit_shell(&g_minishell, 1);
		i++;
	}
}

int				main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	ft_bzero(&g_minishell, sizeof(t_minishell));
	ft_putstr_fd("\nMINISHELL 42 by kgouacid & afoulqui\n\n", STDERR_FILENO);
	init_env(env);
	handle_signal();
	while (1)
	{
		ft_prompt_msg();
		get_input(&g_minishell);
		handle_input(&g_minishell);
	}
	return (g_minishell.ret);
}
