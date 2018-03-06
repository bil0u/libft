/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelthis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 23:31:28 by upopee            #+#    #+#             */
/*   Updated: 2018/03/06 17:06:45 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"
#include "memory.h"

void	ft_lstdelthis(t_list **alst, t_list *ref, void (*del)(void*, size_t))
{
	t_list	*item;
	t_list	*prev;

	prev = NULL;
	if (alst && *alst && ref)
	{
		item = *alst;
		while (item != NULL)
		{
			if (item == ref)
			{
				if (prev)
					prev->next = ref->next;
				else
					*alst = ref->next;
				if (del)
					(*del)(item->content, item->content_size);
				ft_memdel((void **)&item);
				return ;
			}
			prev = item;
			item = item->next;
		}
	}
}
