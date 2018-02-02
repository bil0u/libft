/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:49:41 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 13:43:21 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "memory.h"

void	*ft_memalloc(size_t size)
{
	void	*new;

	if (!size || !(new = malloc(size)))
		return (NULL);
	ft_bzero(new, size);
	return (new);
}
