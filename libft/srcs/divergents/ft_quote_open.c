/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote_open.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:01:11 by kgouacid          #+#    #+#             */
/*   Updated: 2020/10/25 14:04:18 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** j'avais inversé les 2 enfait mdrrrrrrrr mais trop tard pour changer, rip
*/

int		ft_quote_open(t_quotes *quotes, char c)
{
	if (!quotes->bs && !quotes->dq && c == '"')
		quotes->q = (quotes->q) ? 0 : 1;
	else if (!quotes->bs && !quotes->q && c == '\'')
		quotes->dq = (quotes->dq) ? 0 : 1;
	if (quotes->bs)
		quotes->bs = 0;
	else if (c == '\\')
		quotes->bs = 1;
	return (quotes->q || quotes->dq);
}
