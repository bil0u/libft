/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:56:50 by upopee            #+#    #+#             */
/*   Updated: 2018/02/08 06:22:42 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "strings.h"
#include "memory.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen((char *)s1);
	if ((s2 = ft_strnew(len)) == NULL)
		return (NULL);
	s2 = ft_memmove(s2, s1, len);
	return (s2);
}
