/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:19:46 by kwe               #+#    #+#             */
/*   Updated: 2020/11/26 15:32:47 by kwe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_del_string(char ***p, int i)
{
	char **words;

	words = *p;
	ft_strdel(&words[i]);
	while (words[i + 1])
	{
		words[i] = words[i + 1];
		i++;
	}
	words[i] = NULL;
}
