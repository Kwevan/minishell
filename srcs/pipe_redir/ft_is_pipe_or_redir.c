/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_pipe_or_redir.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:55:20 by kgouacid          #+#    #+#             */
/*   Updated: 2020/11/22 17:03:19 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strchr_quotes(char *s, int c)
{
	int			i;
	t_quotes	quotes;

	i = 0;
	ft_bzero(&quotes, sizeof(t_quotes));
	while (s[i])
	{
		if (!ft_quote_open(&quotes, s[i]) && (s[i] == c))
			return (s + i);
		i++;
	}
	return (NULL);
}

int		ft_is_pipe_or_redir(char *cmd)
{
	if (ft_strchr_quotes(cmd, '|')
		|| ft_strchr_quotes(cmd, '>')
		|| ft_strchr_quotes(cmd, '<'))
		return (1);
	return (0);
}
