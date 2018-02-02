/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 07:39:07 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:41:47 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

t_list	*ft_lstfind(t_list *lst, void *data_ref, int (*cmp)())
{
	while (lst)
	{
		if ((*cmp)(lst->content, data_ref) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
