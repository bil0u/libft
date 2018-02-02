/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 16:36:15 by upopee            #+#    #+#             */
/*   Updated: 2018/01/31 19:53:46 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "characters.h"

int		ft_strisnumber(char *str, char stop)
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
		while (ft_isdigit(str[0]) && str[0] != stop)
		{
			have_digits++;
			str++;
		}
		if (str[0] && str[0] != stop)
			return (0);
	}
	return (have_digits ? have_digits + sign : 0);
}
