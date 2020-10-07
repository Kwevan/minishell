/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:35:26 by kgouacid          #+#    #+#             */
/*   Updated: 2020/10/07 14:35:29 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//mem leak si start end ou res malloc fails

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

char	*parse_input(char **env, char *input)
{
	int		i;
	char	*ret;

	ret = NULL;
	i = 0;
	while (input[i])
	{
		if (input[i] == '~')
		{
			ret = replace_tilde(ft_get_envv(env, "HOME"), input, i);
			return (ret);
		}
		i++;
	}
	ret = ft_strdup(input);
	free(input);
	return (ret);
}

char	*get_input(t_minishell *mini)
{
	int		ret;
	char	buf;
	int		i;
	char	*input;

	i = 0;
	input = ft_strnew(1);
	while (((ret = read(STDIN_FILENO, &buf, 1)) > 0) && buf != '\n')
	{
		input[i] = buf;
		input = ft_realloc(input, i + 1, i + 2);
		i++;
	}
	input[i] = '\0';
	if (ret < 1)
	{
		ft_putstr_fd("todo: free and exit function 3", 1);
		ft_putstr_fd(strerror(errno), 1);
		exit(1);
	}
	return (parse_input(mini->env, input));
}
