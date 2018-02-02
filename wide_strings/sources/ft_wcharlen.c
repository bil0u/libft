/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 01:12:52 by upopee            #+#    #+#             */
/*   Updated: 2017/03/19 13:34:23 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>

size_t		ft_wcharlen(wchar_t wc)
{
	size_t	len;
	int		shift;

	if (wc <= 0x7F)
		return (1);
	len = 2;
	shift = 11;
	while (wc > ((1 << shift) - 1))
	{
		len++;
		shift = (shift - 1) + 6;
	}
	return (len);
}
