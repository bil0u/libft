/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstforeachif.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 07:28:45 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:41:57 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

void	ft_lstforeachif(t_list *lst, void (*f)(void *), void *d, int (*cmp)())
{
	while (lst)
	{
		if ((*cmp)(lst->content, d) == 0)
			(*f)(lst->content);
		lst = lst->next;
	}
}
