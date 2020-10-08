/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:35:26 by kgouacid          #+#    #+#             */
/*   Updated: 2020/10/08 14:13:22 by kgouacid         ###   ########.fr       */
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
		exit_shell(mini);
	if (!(end = ft_strjoin(home_path, mini->input + i + 1)))
	{
		ft_strdel(&start);
		exit_shell(mini);
	}
	res = ft_strjoin(start, end);
	ft_strdel(&start);
	ft_strdel(&end);
	ft_strdel(&mini->input);
	if (!res)
		exit_shell(mini);
	return (res);
}

void	parse_input(t_minishell *mini, char **env)
{
	int		i;
	char	*ret;
	t_quotes quotes;

	ft_bzero(&quotes, sizeof(t_quotes));
	ret = NULL;
	i = 0;
	while (mini->input[i])
	{
		if ( !ft_quote_open(&quotes, mini->input[i]) && (mini->input[i] == '~'))
		{
			ret = replace_tilde(mini, ft_get_envv(env, "HOME"), i);
			mini->input = ret;
			parse_input(mini, env);
			return ;
		}
		i++;
	}
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
}
