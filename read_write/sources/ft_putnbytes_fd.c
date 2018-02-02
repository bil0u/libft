/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbytes_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 21:30:35 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:59:42 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "read_write.h"

int		ft_putnbytes_fd(void *item, size_t byte_size, int fd, int mod)
{
	const char	*curr_byte;
	const char	*last_byte;
	int			ret;

	if ((item == NULL) || (byte_size == 0))
		return (-1);
	last_byte = (const char *)item;
	curr_byte = last_byte + (byte_size - 1);
	ret = 0;
	while (curr_byte >= last_byte)
	{
		ret += ft_putnbits_fd((void *)curr_byte, 8, fd);
		if (mod == 1 && curr_byte > last_byte)
		{
			ft_putchar_fd(' ', 1);
			ret++;
		}
		curr_byte--;
	}
	return (ret);
}
