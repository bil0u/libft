/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:00:36 by upopee            #+#    #+#             */
/*   Updated: 2018/02/08 06:22:13 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "strings.h"

char	*ft_strrchr(const char *s, int c)
{
	char *tmp;

	tmp = (char *)s + ft_strlen((char *)s);
	while (tmp >= s)
		if (*tmp-- == c)
			return ((char *)(tmp + 1));
	return (NULL);
}
