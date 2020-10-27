/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:30:42 by kgouacid          #+#    #+#             */
/*   Updated: 2020/10/24 13:33:27 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     ft_strlen_quotes(char *word)
{
    int         i;
    int         len;
    t_quotes    quotes;

    ft_bzero(&quotes, sizeof(t_quotes));
    i = 0;
    len = i;
    while (word[i])
    {
        ft_quote_open(&quotes, word[i]);
        if (!(!quotes.dq && word[i] == '"') && !(!quotes.q && word[i] == '\''))
        {
            i++;
            len++;
        }
        else
            i++;
    }
    return (len);
}
