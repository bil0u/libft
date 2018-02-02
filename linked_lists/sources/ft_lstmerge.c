/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 01:05:55 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:42:23 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

void	ft_lstmerge(t_list **lst1, t_list *lst2)
{
	t_list *curr;

	if (!lst1 && !lst2)
		return ;
	if (*lst1)
	{
		curr = *lst1;
		while (curr->next)
			curr = curr->next;
		curr->next = lst2;
	}
	else
		*lst1 = lst2;
}
