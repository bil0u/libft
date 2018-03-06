/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelthis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 23:31:28 by upopee            #+#    #+#             */
/*   Updated: 2018/03/05 22:55:36 by upopee           ###   ########.fr       */
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
				prev == NULL ? prev->next = *alst : (void)ref;
				prev->next = ref->next;
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
