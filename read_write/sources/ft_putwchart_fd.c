/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchart_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:51:54 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:53:41 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include "read_write.h"
#include "wide_strings.h"

static unsigned char	ft_firstmask(unsigned int nb_bytes)
{
	if (nb_bytes == 0)
		return (0);
	return ((1 << (8 - nb_bytes)) + ft_firstmask(nb_bytes - 1));
}

int						ft_putwchart_fd(wchar_t wc, int fd)
{
	unsigned int	nb_bytes;
	unsigned int	remaining;
	unsigned char	c;
	wchar_t			tmp;

	nb_bytes = 0;
	nb_bytes = ft_wcharlen(wc);
	if (nb_bytes == 1 || (MB_CUR_MAX == 1 && wc <= 255))
	{
		ft_putchar_fd((char)wc, fd);
		return (1);
	}
	remaining = nb_bytes;
	while (remaining > 0)
	{
		tmp = wc >> ((remaining - 1) * 6);
		tmp = tmp & 0x3F;
		c = (remaining == nb_bytes ? ft_firstmask(nb_bytes) : 0x80) | tmp;
		write(fd, &c, 1);
		remaining--;
	}
	return ((int)nb_bytes);
}
