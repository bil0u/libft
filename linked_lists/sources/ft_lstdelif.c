/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 23:31:28 by upopee            #+#    #+#             */
/*   Updated: 2018/03/06 17:07:05 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"
#include "memory.h"

int		ft_lstdelif(t_list **alst, void *ref,
					int (*cmp)(), void (*del)(void*, size_t))
{
	t_list	*item;
	t_list	*prev;

	prev = NULL;
	if (alst && *alst && ref && cmp)
	{
		item = *alst;
		while (item != NULL)
		{
			if ((*cmp)(item->content, ref) == 0)
			{
				if (prev)
					prev->next = item->next;
				else
					*alst = item->next;
				if (del)
					(*del)(item->content, item->content_size);
				ft_memdel((void **)&item);
				return (0);
			}
			prev = item;
			item = item->next;
		}
	}
	return (-1);
}
