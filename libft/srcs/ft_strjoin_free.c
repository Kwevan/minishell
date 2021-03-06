/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:17:05 by kgouacid          #+#    #+#             */
/*   Updated: 2020/11/26 15:56:39 by kwe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*fill_dest(char *dest, char const *s1, char const *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

static void		ft_free(char *s1, char *s2, int to_free)
{
	if (to_free == 1)
		free(s1);
	else if (to_free == 2)
	{
		free(s1);
		free(s2);
	}
	else if (to_free == 3)
		free(s2);
}

char			*ft_strjoin_free(char const *s1, char const *s2, int to_free)
{
	char	*dest;
	size_t	dest_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	dest_len = ft_strlen(s1) + ft_strlen(s2);
	if (dest_len == 0)
		return (ft_strdup(""));
	if (!(dest = (char *)malloc(sizeof(char) * (dest_len + 1))))
	{
		ft_free((char *)s1, (char *)s2, to_free);
		return (NULL);
	}
	if (!s1 || !s2)
		return (NULL);
	dest = fill_dest(dest, s1, s2);
	ft_free((char *)s1, (char *)s2, to_free);
	return (dest);
}
