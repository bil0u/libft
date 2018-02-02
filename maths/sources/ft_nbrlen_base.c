/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 04:18:42 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:01:28 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "maths.h"

size_t		ft_nbrlen_base(uint128_t n, unsigned int base_n)
{
	size_t len;

	len = 0;
	while (n != 0)
	{
		n /= base_n;
		len++;
	}
	return (len ? len : 1);
}
