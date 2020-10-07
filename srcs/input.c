/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:35:26 by kgouacid          #+#    #+#             */
/*   Updated: 2020/10/07 16:19:18 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//rechecker  les mallocs

char	*replace_tilde(char *home, char *input, int i)
{
	char	*start;
	char	*end;
	char	*res;

	start = NULL;
	end = NULL;
	res = NULL;
	start = ft_strndup(input, i);
	end = ft_strjoin(home, input + i + 1);
	res = ft_strjoin(start, end);
	free(input);
	free(start);
	free(end);
	return (res);
}

//cassé avec les quotes
void	parse_input(t_minishell *mini, char **env)
{
	int		i;
	char	*ret;

	ret = NULL;
	i = 0;
	while (mini->input[i])
	{
		if (mini->input[i] == '~')
		{
			ret = replace_tilde(ft_get_envv(env, "HOME"), mini->input, i);
			mini->input = ret;
			return ;
		}
		i++;
	}
	ret = ft_strdup(mini->input);
	free(mini->input);
	mini->input = ret;
}

void	get_input(t_minishell *mini)
{
	int		ret;
	char	buf;
	int		i;

	i = 0;
	if (!(mini->input = ft_strnew(1)))
		exit_shell(mini);
	while (((ret = read(STDIN_FILENO, &buf, 1)) > 0) && buf != '\n')
	{
		mini->input[i] = buf;
		if (!(mini->input = ft_realloc(mini->input, i + 1, i + 2)))
			exit_shell(mini);
		i++;
	}
	mini->input[i] = '\0';
	if (ret < 1)
	{
		ft_putstr_fd(strerror(errno), 1);
		exit_shell(mini);
	}
	parse_input(mini, mini->env);
	ft_putstr_fd(mini->input, 1);
}
