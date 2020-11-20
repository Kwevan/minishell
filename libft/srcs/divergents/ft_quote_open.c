/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote_open.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:01:11 by kgouacid          #+#    #+#             */
/*   Updated: 2020/11/20 10:42:59 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** j'avais inversé les 2 enfait mdrrrrrrrr mais trop tard pour changer, rip
*/

int		ft_quote_open(t_quotes *quotes, char c)
{
	if (quotes->bs)
	{
		quotes->bs = 0;
		quotes->nx = 1;
		return (1);
	}
	else
		quotes->nx = 0;
	if (!quotes->bs && !quotes->dq && c == '"')
		quotes->q = (quotes->q) ? 0 : 1;
	else if (!quotes->bs && !quotes->q && c == '\'')
		quotes->dq = (quotes->dq) ? 0 : 1;
	if (c == '\\')
		quotes->bs = 1;
	return (quotes->q || quotes->dq);
}
