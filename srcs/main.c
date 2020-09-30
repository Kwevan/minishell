/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:00:39 by afoulqui          #+#    #+#             */
/*   Updated: 2020/09/30 17:58:26 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		init_env(t_minishell *minishell, char **env)
{
	int			i;
	int			len;

	len = ft_strlen2(env);
	minishell->env = (char **)ft_calloc(sizeof(char *), (len + 1));
	if (!(minishell->env))
		exit_shell(minishell);
	i = 0;
	while (env[i])
	{
		minishell->env[i] = ft_strdup(env[i]);
		if (!(minishell->env[i]))
			exit_shell(minishell);
		i++;
	}
}

int				main(int argc, char **argv, char **env)
{
	t_minishell	minishell;
	/*char		*input;*/

	(void)argc;
	(void)argv;
	ft_bzero(&minishell, sizeof(t_minishell));
	ft_putstr_fd("\nMINISHELL 42 by kgouacid & afoulqui\n\n", 1);
	init_env(&minishell, env);
	while (1)
	{
		/*prompt_msg();
		input = get_input(&minishell);
		handle_input(&minishell, input);*/
	}
	return (0);
}