/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:59:45 by upopee            #+#    #+#             */
/*   Updated: 2018/03/09 00:14:15 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*tmp;

	if (dst)
	{
		if (len == 0)
			return (dst);
		if (src)
		{
			tmp = dst;
			while (*src && (len > 0))
			{
				*tmp++ = *src++;
				len--;
			}
			while (len > 0)
			{
				*tmp++ = '\0';
				len--;
			}
		}
		return (dst);
	}
	return (NULL);
}
