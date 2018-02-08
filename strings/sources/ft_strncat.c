/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:59:04 by upopee            #+#    #+#             */
/*   Updated: 2018/02/08 06:22:23 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "strings.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*dst;

	if (n)
	{
		dst = s1 + ft_strlen(s1);
		while (*s2 && n-- > 0)
			*dst++ = *s2++;
		*dst = 0;
	}
	return (s1);
}
