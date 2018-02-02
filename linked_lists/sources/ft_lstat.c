/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 03:19:04 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:41:27 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

t_list	*ft_lstat(t_list *lst, unsigned int nbr)
{
	while (nbr > 0 && lst->next)
	{
		lst = lst->next;
		nbr--;
	}
	return (lst);
}
