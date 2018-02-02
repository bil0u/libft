/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:57:43 by upopee            #+#    #+#             */
/*   Updated: 2018/01/31 19:54:56 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "strings.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	left;
	char	*curr;
	char	*s;

	curr = dst;
	left = size;
	while (*curr && left--)
		curr++;
	len = (size_t)(curr - dst);
	left = size - len;
	s = (char *)src;
	if (!left)
		return (size + ft_strlen((char *)src));
	while (*s && left-- > 1)
		*curr++ = *s++;
	while (*s)
		s++;
	*curr = 0;
	return (len + (size_t)(s - src));
}
