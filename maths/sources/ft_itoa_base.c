/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:23:05 by upopee            #+#    #+#             */
/*   Updated: 2018/03/10 23:17:21 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "strings.h"
#include "maths.h"

char			*ft_itoa_base(int n, const char *base)
{
	char			*nbr;
	size_t			len;
	int				neg;
	int				base_n;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = (n < 0) ? 1 : 0;
	base_n = ft_strlen((char *)base);
	len = ft_nbrlen_base(ft_abs(n), base_n);
	if (!(nbr = ft_strnew(len + neg)))
		return (NULL);
	if (neg)
	{
		nbr[0] = '-';
		n *= -1;
	}
	while (len-- > 0)
	{
		nbr[len + neg] = base[n % base_n];
		n /= base_n;
	}
	return (nbr);
}
