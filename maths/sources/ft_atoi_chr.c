/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 22:31:57 by upopee            #+#    #+#             */
/*   Updated: 2018/02/26 22:36:04 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "characters.h"

int		ft_atoi_chr(char **str)
{
	int			sign;
	int			res;

	res = 0;
	while (ft_iswhitespace((int)**str))
		(*str)++;
	sign = (**str == '-' ? -1 : 1);
	if (**str == '-' || **str == '+')
		(*str)++;
	while (ft_isdigit((int)**str))
	{
		res = res * 10 + (int)**str - '0';
		(*str)++;
	}
	return (res * sign);
}
