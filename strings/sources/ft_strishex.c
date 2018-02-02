/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strishex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 16:36:15 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 13:47:06 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "characters.h"

int		ft_strishex(char *str, char stop)
{
	int		have_digits;
	int		sign;

	have_digits = 0;
	sign = 0;
	if (str)
	{
		if (str[0] == '-' || str[0] == '+')
		{
			sign++;
			str++;
		}
		if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		{
			have_digits += 2;
			str += 2;
		}
		while (ft_ishexdigit(str[0]) && str[0] != stop)
		{
			have_digits++;
			str++;
		}
		have_digits = (str[0] && str[0] != stop) ? 0 : have_digits;
	}
	return (have_digits ? have_digits + sign : 0);
}
