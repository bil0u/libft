/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:01:03 by upopee            #+#    #+#             */
/*   Updated: 2018/03/09 00:21:02 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*str;
	char	*find;

	if (haystack)
	{
		if (!needle || *needle == '\0')
			return ((char *)haystack);
		while (*haystack)
		{
			str = (char *)haystack++;
			find = (char *)needle;
			while (*str++ == *find++)
				if (!*find)
					return ((char *)(haystack - 1));
		}
	}
	return (NULL);
}
