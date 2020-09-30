/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_multilines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:19:56 by kgouacid          #+#    #+#             */
/*   Updated: 2020/09/30 13:29:11 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"

int		ft_check_multilines(char *str)
{
	int			i;
	t_quotes	quotes;

	ft_bzero(&quotes, sizeof(t_quotes));
	i = 0;
	while (str[i])
	{
		ft_quote_open(&quotes, str[i]);
		i++;
	}
	return (quotes.q || quotes.dq);	
}
