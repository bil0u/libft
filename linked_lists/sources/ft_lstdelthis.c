/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelthis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 23:31:28 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:41:39 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"
#include "memory.h"

void	ft_lstdelthis(t_list **alst, t_list *item)
{
	t_list	*leak;
	t_list	*prev;

	prev = NULL;
	if (alst && *alst && item)
	{
		leak = *alst;
		while (leak != NULL)
		{
			if (leak == item)
			{
				if (prev)
					prev->next = item->next;
				else
					*alst = item->next;
				ft_memdel((void **)&leak->content);
				ft_memdel((void **)&leak);
				return ;
			}
			prev = leak;
			leak = leak->next;
		}
	}
}
