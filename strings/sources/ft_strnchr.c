/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:55:49 by upopee            #+#    #+#             */
/*   Updated: 2018/03/09 00:09:31 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnchr(const char *s, int c, size_t len)
{
	if (s)
	{
		while (*s && len)
		{
			if (*s == (char)c)
				return ((char *)s);
			s++;
			len--;
		}
	}
	return (c == '\0' && len > 0 ? (char *)s : NULL);
}
