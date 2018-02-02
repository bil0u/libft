/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:50:00 by upopee            #+#    #+#             */
/*   Updated: 2016/11/28 11:50:35 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n)
		while (n-- > 0)
			if (*(unsigned char *)s1++ != *(unsigned char *)s2++)
				return (*(unsigned char *)--s1 - *(unsigned char *)--s2);
	return (0);
}
