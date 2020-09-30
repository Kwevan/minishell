/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote_open.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:01:11 by kgouacid          #+#    #+#             */
/*   Updated: 2020/09/30 13:02:44 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_quote_open(t_quotes *quotes, char c)
{
	if (!quotes->dq && c == '"')
		quotes->q = (quotes->q) ? 0 : 1;
	else if (!quotes->q && c == '\'')
		quotes->dq = (quotes->dq) ? 0 : 1;
	return (quotes->q || quotes->dq);
}
