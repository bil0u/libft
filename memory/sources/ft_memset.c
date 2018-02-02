/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:51:06 by upopee            #+#    #+#             */
/*   Updated: 2016/11/28 11:51:07 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	void *tmp;

	if (len)
	{
		tmp = b;
		while (len-- > 0)
			*(unsigned char *)tmp++ = c;
	}
	return (b);
}
