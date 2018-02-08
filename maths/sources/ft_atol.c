/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:44:43 by upopee            #+#    #+#             */
/*   Updated: 2018/02/08 06:24:27 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "characters.h"

long int	ft_atol(const char *str)
{
	int			sign;
	long int	res;

	res = 0;
	while (ft_iswhitespace((int)*str))
		str++;
	sign = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit((int)*str))
	{
		res = res * 10 + (int)*str - '0';
		str++;
	}
	return (res * (long int)sign);
}
