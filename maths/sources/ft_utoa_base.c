/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:25:09 by upopee            #+#    #+#             */
/*   Updated: 2018/01/31 20:05:43 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "strings.h"
#include "maths.h"

char			*ft_utoa_base(uintmax_t n, const char *base)
{
	char			*nbr;
	size_t			len;
	unsigned int	base_n;

	base_n = ft_strlen((char *)base);
	len = ft_nbrlen_base(n, base_n);
	if (!(nbr = ft_strnew(len)))
		return (NULL);
	while (len-- > 0)
	{
		nbr[len] = base[ABS(n % base_n)];
		n /= (int)base_n;
	}
	return (nbr);
}
