/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:23:05 by upopee            #+#    #+#             */
/*   Updated: 2018/01/31 20:05:50 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "strings.h"
#include "maths.h"

char			*ft_ltoa_base(long int n, const char *base)
{
	char			*nbr;
	size_t			len;
	unsigned int	neg;
	unsigned int	base_n;

	neg = (n < 0) ? 1 : 0;
	base_n = ft_strlen((char *)base);
	len = ft_nbrlen_base(ABS(n), base_n);
	if (!(nbr = ft_strnew(len + neg)))
		return (NULL);
	if (neg)
		nbr[0] = '-';
	while (len-- > 0)
	{
		nbr[len + neg] = base[ABS(n % base_n)];
		n /= (int)base_n;
	}
	return (nbr);
}
