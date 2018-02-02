/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 05:38:08 by upopee            #+#    #+#             */
/*   Updated: 2017/03/03 05:40:55 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>

wchar_t		*ft_wstrncpy(wchar_t *dst, const wchar_t *src, size_t len)
{
	unsigned int	i;

	if (src && dst && len)
	{
		i = 0;
		while (len > 0)
		{
			dst[i] = src[i];
			len--;
			i++;
		}
	}
	return (dst);
}
