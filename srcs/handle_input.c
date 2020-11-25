/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:35:16 by kgouacid          #+#    #+#             */
/*   Updated: 2020/11/25 11:56:21 by kwe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse2(char *s, int *i, int *count, t_quotes *quotes)
{
	int c;
	int open;

	c = 0;
	while (s[*i] && s[*i] != ';')
	{
		if (s[*i] != ' ')
			c = 1;
		(*i) += 1;
		open = ft_quote_open(quotes, s[*i]);
	}
	if (c)
		(*count) += 1;
	c = 0;
}

int		ft_parse_error(char *s)
{
	int			i;
	int			count;
	t_quotes	quotes;
	int			open;

	i = 0;
	count = 0;
	ft_bzero(&quotes, sizeof(t_quotes));
	while (s[i] && ((open = ft_quote_open(&quotes, s[i])) != 15))
	{
		if (s[i] != ';')
			parse2(s, &i, &count, &quotes);
		else
		{
			if (!open)
				count--;
			if (count < 0)
				return (1);
			i++;
		}
	}
	return (count < 0);
}

void	handle_input(t_minishell *mini)
{
	int len;

	if (ft_parse_error(mini->input))
	{
		ft_putendl_fd("Parse error near ;", 2);
		mini->ret = 2;
		ft_strdel(&mini->input);
		return ;
	}
	if (!(mini->commands = ft_split_quote(mini->input, ";")))
		exit_shell(mini, 1);
	ft_strdel(&mini->input);
	mini->pipe_err = 0;
	len = ft_strlen2(mini->commands);
	len--;
	if (len >= 0 && ft_isallspace(mini->commands[len]))
	{
		free(mini->commands[len]);
		mini->commands[len] = NULL;
		len--;
	}
	if (mini->commands[0] == NULL)
		return ;
	ft_exec_commands(mini, mini->commands);
}
