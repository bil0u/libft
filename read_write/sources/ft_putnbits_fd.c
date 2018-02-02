/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbits_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 21:34:19 by upopee            #+#    #+#             */
/*   Updated: 2017/03/24 21:02:03 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putnbits_fd(void *item, size_t len, int fd)
{
	char			buff[len];
	char			*byte;
	unsigned int	i;

	if (len == 0)
		return (0);
	byte = (char *)item;
	i = 0;
	if (len > 8)
		len = 8;
	while (i < len)
	{
		buff[len - i - 1] = ((byte[0] >> i) & 1) + '0';
		i++;
	}
	write(fd, buff, len);
	return (len);
}
