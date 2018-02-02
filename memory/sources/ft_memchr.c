/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:49:52 by upopee            #+#    #+#             */
/*   Updated: 2016/11/28 11:49:53 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (n)
		while (n-- > 0)
			if (*((unsigned char *)s++) == (unsigned char)c)
				return ((void *)(s - 1));
	return (NULL);
}
