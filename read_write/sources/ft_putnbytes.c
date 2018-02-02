/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 21:30:35 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:44:16 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "read_write.h"

int		ft_putnbytes(void *item, size_t byte_size, int mod)
{
	return (ft_putnbytes_fd(item, byte_size, 1, mod));
}
