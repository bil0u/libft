/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revmemset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:55:23 by upopee            #+#    #+#             */
/*   Updated: 2016/11/28 11:55:24 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_revmemset(void *b, int c, size_t len)
{
	if (b == NULL)
		return (NULL);
	while ((int)--len >= 0)
		*((char *)b + len) = c;
	return (b);
}
