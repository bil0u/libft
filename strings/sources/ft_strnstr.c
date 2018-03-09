/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:00:23 by upopee            #+#    #+#             */
/*   Updated: 2018/03/09 00:17:08 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*str;
	char		*find;
	const char	*limit;

	if (haystack)
	{
		if (!needle || *needle == '\0')
			return ((char *)haystack);
		limit = haystack + len;
		while (*haystack && (haystack <= limit))
		{
			str = (char *)haystack;
			find = (char *)needle;
			while ((*str++ == *find++) && (str <= limit))
			{
				if (*find == '\0')
					return ((char *)haystack);
			}
			haystack++;
		}
	}
	return (NULL);
}
