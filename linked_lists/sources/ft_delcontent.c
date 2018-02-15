/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delcontent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:38:50 by upopee            #+#    #+#             */
/*   Updated: 2018/02/15 16:48:16 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"
#include "memory.h"

void	ft_delcontent(void *content, size_t size)
{
	if (content)
		ft_memdel(&content);
	(void)size;
}
