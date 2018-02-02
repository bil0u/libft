/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:22:42 by upopee            #+#    #+#             */
/*   Updated: 2018/01/31 20:05:49 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "maths.h"

intmax_t		ft_sqrt_next(intmax_t nb)
{
	intmax_t	ret;

	while ((ret = ft_sqrt(nb)) == 0)
		nb++;
	return (ret);
}
