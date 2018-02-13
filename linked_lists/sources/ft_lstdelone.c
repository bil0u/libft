/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:48:38 by upopee            #+#    #+#             */
/*   Updated: 2018/02/12 16:41:50 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "linked_lists.h"
#include "memory.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (alst)
	{
		if (*alst)
		{
			if (del)
				(*del)((*alst)->content, (*alst)->content_size);
			ft_memdel((void **)&(*alst));
		}
		*alst = NULL;
	}
}
