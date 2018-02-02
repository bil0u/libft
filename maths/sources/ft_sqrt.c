/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:27:28 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:02:00 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

intmax_t		ft_sqrt(intmax_t nb)
{
	intmax_t i;

	i = 2;
	if (nb > 1)
	{
		while (i * i < nb)
			i++;
		if (i * i == nb)
			return (i);
		else
			return (0);
	}
	else if (nb == 1)
		return (1);
	return (0);
}
