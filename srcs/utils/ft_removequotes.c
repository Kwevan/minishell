/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removequotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 11:02:16 by afoulqui          #+#    #+#             */
/*   Updated: 2020/10/13 17:52:00 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_removequotes(char *str)
{
	char	**split;
	char	*res;

	split = ft_split2(str, "\'\"");
	free(str);
	res = split[0];
	return (res);
}