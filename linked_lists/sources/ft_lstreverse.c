/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 04:55:18 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:42:34 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

void	ft_lstreverse(t_list **lst)
{
	t_list *tmp_next;
	t_list *tmp_prev;
	t_list *curr;

	if (*lst == 0)
		return ;
	tmp_prev = 0;
	tmp_next = *lst;
	curr = *lst;
	while (curr)
	{
		tmp_next = curr->next;
		curr->next = tmp_prev;
		tmp_prev = curr;
		curr = tmp_next;
	}
	*lst = tmp_prev;
}
