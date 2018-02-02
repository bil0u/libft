/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoimax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:44:43 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:00:12 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "characters.h"

intmax_t	ft_atoimax(const char *str)
{
	int			sign;
	intmax_t	res;

	res = 0;
	while (ft_iswhitespace((int)*str))
		str++;
	sign = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit((int)str))
	{
		res = res * 10 + (int)*str - '0';
		str++;
	}
	return (res * (intmax_t)sign);
}
