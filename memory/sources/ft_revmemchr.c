/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revmemchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:54:39 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 13:43:42 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "memory.h"

void	*ft_revmemchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;

	if (n && s)
	{
		tmp = (unsigned char *)ft_memchr(s, 0, n);
		while (n-- > 0 && (void *)tmp > s)
			if (*--tmp == c)
				return ((void *)tmp);
	}
	return (NULL);
}
