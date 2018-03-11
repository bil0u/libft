/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:53:28 by upopee            #+#    #+#             */
/*   Updated: 2018/03/10 23:13:50 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putnbr_fd(int n, int fd)
{
	char			buff[12];
	unsigned int	range;
	size_t			len;

	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	len = (n < 0) ? 1 : 0;
	if (n < 0)
	{
		buff[0] = '-';
		n = -n;
	}
	range = 1;
	while (n / range > 9)
		range *= 10;
	while (range > 0)
	{
		buff[len++] = '0' + n / range;
		n %= range;
		range /= 10;
	}
	buff[len] = '\0';
	write(fd, buff, len);
	return (len);
}
