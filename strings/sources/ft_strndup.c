/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:56:50 by upopee            #+#    #+#             */
/*   Updated: 2018/02/08 06:22:19 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "strings.h"
#include "memory.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char	*s2;
	size_t	sz;

	sz = ft_strlen((char *)s1);
	if (len < sz)
		sz = len;
	if ((s2 = ft_strnew(sz)) == NULL)
		return (NULL);
	s2 = ft_memmove(s2, s1, sz);
	return (s2);
}
