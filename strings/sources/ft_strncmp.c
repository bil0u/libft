/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:59:16 by upopee            #+#    #+#             */
/*   Updated: 2018/03/09 00:10:54 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strncmp(char *s1, char *s2, size_t n)
{
	if (!s1 || !s2)
		return (-1);
	if (n == 0 || s1 == s2)
		return (0);
	while ((n-- > 0) && (*s1 || *s2))
	{
		if (*s1++ != *s2++)
			return ((int)(*(unsigned char *)--s1 - *(unsigned char *)--s2));
	}
	return (0);
}
