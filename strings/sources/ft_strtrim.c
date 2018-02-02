/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:01:21 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 13:46:25 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "strings.h"
#include "characters.h"

char	*ft_strtrim(char const *s)
{
	char	*start;
	char	*end;
	char	*new;
	char	*tmp;

	if (s)
	{
		start = (char *)s;
		end = start + ft_strlen((char *)s) - 1;
		while (start < end && ft_iswhitespace((int)*start))
			start++;
		while (end > start && ft_iswhitespace((int)*end))
			end--;
		if (!(new = ft_strnew(start != end ? end - start + 1 : 0)))
			return (NULL);
		tmp = new;
		if (start < end)
			while (start <= end)
				*tmp++ = *start++;
		*tmp = 0;
		return (new);
	}
	return (NULL);
}
