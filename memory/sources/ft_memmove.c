/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:50:58 by upopee            #+#    #+#             */
/*   Updated: 2018/04/28 22:38:49 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *tmp;

	tmp = dst;
	if (dst == src || !len)
		return (dst);
	else if (dst < src)
		while (len-- > 0)
			*(unsigned char *)tmp++ = *(unsigned char *)src++;
	else
		while (len-- > 0)
			*((unsigned char *)tmp + len) = *((unsigned char *)src + len);
	return (dst);
}
