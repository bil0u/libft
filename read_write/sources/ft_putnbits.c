/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 21:34:19 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:44:00 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_write.h"

int		ft_putnbits(void *item, size_t len)
{
	return (ft_putnbits_fd(item, len, 1));
}
