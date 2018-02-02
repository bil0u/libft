/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:48:10 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:41:23 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	if (!new || !alst)
		return ;
	if (!(*alst))
		*alst = new;
	else
		ft_lstappend(&((*alst)->next), new);
}
