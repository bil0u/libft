/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:25:09 by upopee            #+#    #+#             */
/*   Updated: 2018/05/03 12:33:46 by susivagn         ###   ########.fr       */
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
		nbr[len] = base[ft_abs(n % base_n)];
		n /= (int)base_n;
	}
	return (nbr);
}
