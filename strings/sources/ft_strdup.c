/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:56:50 by upopee            #+#    #+#             */
/*   Updated: 2018/03/09 00:00:14 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "strings.h"
#include "memory.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	if (s1)
	{
		len = ft_strlen((char *)s1);
		if ((s2 = ft_strnew(len)) == NULL)
			return (NULL);
		s2 = ft_memmove(s2, s1, len);
		return (s2);
	}
	return (NULL);
}
