/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revmemcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:54:47 by upopee            #+#    #+#             */
/*   Updated: 2016/11/28 11:54:49 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_revmemcmp(const void *s1, const void *s2, size_t n)
{
	while ((int)--n >= 0)
	{
		if (*((unsigned char *)s1 + n) != *((unsigned char *)s2 + n))
			return (*((unsigned char *)s1 + n) - *((unsigned char *)s2 + n));
	}
	return (0);
}
