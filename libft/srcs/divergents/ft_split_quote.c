/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 13:19:00 by kgouacid          #+#    #+#             */
/*   Updated: 2020/11/20 10:46:10 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"

static int		ft_is_in_str_quote(char c, char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static int		ft_count_word_quote(char *str, char *charset)
{
	int			i;
	int			nb;
	int			bl;
	t_quotes	quotes;

	ft_bzero(&quotes, sizeof(t_quotes));
	i = 0;
	nb = 0;
	while (str[i])
	{
		bl = 0;
		while (ft_is_in_str_quote(str[i], charset) && str[i])
			i++;
		while ((ft_quote_open(&quotes, str[i])
			|| !ft_is_in_str_quote(str[i], charset)) && str[i])
		{
			nb += (bl ? 0 : 1);
			bl = 1;
			i++;
		}
	}
	return (nb);
}

static char		*ft_cut_word_quote(char *str, char *charset, int *i)
{
	int			j;
	int			len;
	char		*strnew;
	t_quotes	quotes;

	j = 0;
	len = 0;
	ft_bzero(&quotes, sizeof(t_quotes));
	while (ft_is_in_str_quote(str[*i], charset) && str[*i])
		*i += 1;
	while ((ft_quote_open(&quotes, str[*i + len])
		|| !ft_is_in_str_quote(str[*i + len], charset)) && str[*i + len])
		len++;
	if (!(strnew = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (j < len)
	{
		strnew[j] = str[*i];
		j++;
		*i += 1;
	}
	strnew[j] = '\0';
	return (strnew);
}

char			**ft_split_quote(char *str, char *charset)
{
	int			i;
	char		**dest;
	int			j;
	int			dest_size;

	i = 0;
	j = 0;
	dest_size = ft_count_word_quote(str, charset);
	if (!(dest = malloc(sizeof(char *) * (dest_size + 1))))
		return (NULL);
	while (i < dest_size)
	{
		if (!(dest[i] = ft_cut_word_quote(str, charset, &j)))
		{
			ft_freestrarr(dest);
			return (NULL);
		}
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
