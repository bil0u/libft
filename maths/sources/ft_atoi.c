/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:44:43 by upopee            #+#    #+#             */
/*   Updated: 2018/01/31 20:00:17 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "characters.h"

int		ft_atoi(const char *str)
{
	int			sign;
	int			res;

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
	return (res * sign);
}
