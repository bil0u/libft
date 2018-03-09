/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:00:49 by upopee            #+#    #+#             */
/*   Updated: 2018/03/09 00:18:48 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "strings.h"
#include "memory.h"

char				**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	int				words;
	char			**t;

	if (!s)
		return (NULL);
	words = ft_nbwords(s, c);
	if (!(t = (char **)ft_memalloc(sizeof(*t) * (words + 1))))
		return (NULL);
	i = 0;
	while (words--)
	{
		while (*s == c && *s)
			s++;
		if (!(t[i++] = ft_strsub(s, 0, ft_wordlen(s, c))))
			return (NULL);
		s += ft_wordlen(s, c);
	}
	t[i] = NULL;
	return (t);
}
