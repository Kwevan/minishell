/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:35:26 by kgouacid          #+#    #+#             */
/*   Updated: 2020/11/28 11:17:20 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_tilde(t_minishell *mini, char *home_path, int i)
{
	char	*start;
	char	*end;
	char	*res;

	start = NULL;
	end = NULL;
	res = NULL;
	if (!home_path)
		return (mini->input);
	if (!(start = ft_strndup(mini->input, i)))
		exit_shell(mini, 1);
	if (!(end = ft_strjoin(home_path, mini->input + i + 1)))
	{
		ft_strdel(&start);
		exit_shell(mini, 1);
	}
	res = ft_strjoin(start, end);
	ft_strdel(&start);
	ft_strdel(&end);
	ft_strdel(&mini->input);
	if (!res)
		exit_shell(mini, 1);
	return (res);
}

void	parse_input(t_minishell *mini, char **env)
{
	int			i;
	char		*ret;
	t_quotes	quotes;

	ft_bzero(&quotes, sizeof(t_quotes));
	ret = NULL;
	i = 0;
	while (mini->input[i])
	{
		if (!ft_quote_open(&quotes, mini->input[i]) && (mini->input[i] == '~'))
		{
			ret = replace_tilde(mini, ft_get_envv(mini, env, "HOME"), i);
			mini->input = ret;
			parse_input(mini, env);
			return ;
		}
		i++;
	}
}

void	ft_mini_exit(t_minishell *mini)
{
	ft_putstr_fd(strerror(errno), 2);
	exit_shell(mini, 1);
}

void	get_input(t_minishell *mini)
{
	int		ret;
	char	buf;
	int		i;

	i = 0;
	mini->input = NULL;
	while (((ret = read(STDIN_FILENO, &buf, 1)) >= 0) && buf != '\n')
	{
		if (ret == 0 && mini->input == NULL)
			exit_shell(mini, mini->ret);
		if (ret > 0)
		{
			if (i == 0)
				if (!(mini->input = ft_strnew(1)))
					exit_shell(mini, 1);
			mini->input[i] = buf;
			if (!(mini->input = ft_realloc(mini->input, i + 1, i + 2)))
				exit_shell(mini, 1);
			i++;
		}
	}
	!mini->input ? mini->input = ft_strdup("") : 0;
	if (ret < 1)
		ft_mini_exit(mini);
	parse_input(mini, mini->env);
}
