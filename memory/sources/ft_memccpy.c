/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:49:46 by upopee            #+#    #+#             */
/*   Updated: 2016/11/28 11:49:47 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	if (n)
	{
		while (n-- > 0)
		{
			*(unsigned char *)dst++ = *(unsigned char *)src++;
			if (*(unsigned char *)(src - 1) == (unsigned char)c)
				return (dst);
		}
	}
	return (NULL);
}
