/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revmemccpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:53:51 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 13:43:38 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "strings.h"

void	*ft_revmemccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (n && src && dst)
	{
		s = (unsigned char *)src + ft_strlen((char *)src);
		d = (unsigned char *)dst + ft_strlen((char *)dst);
		while (n-- > 0 && (void *)s > src && (void *)d > dst)
		{
			*--d = *--s;
			if (*s == c)
				return ((void *)--d);
		}
	}
	return (NULL);
}
