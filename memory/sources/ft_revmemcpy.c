/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revmemcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:55:01 by upopee            #+#    #+#             */
/*   Updated: 2016/11/28 11:55:11 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_revmemcpy(void *dst, const void *src, size_t n)
{
	if (src == NULL || dst == NULL)
		return (dst);
	while ((int)--n >= 0)
		*((char *)dst + n) = *((char *)src + n);
	return (dst);
}
