/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:53:28 by upopee            #+#    #+#             */
/*   Updated: 2018/02/15 18:00:40 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_write.h"
#include "maths.h"

int		ft_putnbr_fd(int n, int fd)
{
	unsigned int	range;
	size_t			len;

	range = 1;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	len = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = ft_abs(n);
		len++;
	}
	while (n / range > 9)
		range *= 10;
	while (range > 0)
	{
		ft_putchar_fd('0' + n / range, fd);
		n %= range;
		range /= 10;
		len++;
	}
	return (len);
}
