/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:57:28 by upopee            #+#    #+#             */
/*   Updated: 2018/02/08 06:22:31 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "strings.h"
#include "memory.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else if (s2 && !s1)
		return (ft_strdup(s2));
	else
	{
		len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
		if (!(new = (char *)ft_memalloc(len + 1)))
			return (NULL);
		new = ft_strcat(new, s1);
		new = ft_strcat(new, s2);
		return (new);
	}
}
