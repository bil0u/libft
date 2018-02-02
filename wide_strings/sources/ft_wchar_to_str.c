/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 05:37:19 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 13:50:00 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wide_strings.h"

static unsigned char	ft_firstmask(unsigned int nb_bytes)
{
	if (nb_bytes == 0)
		return (0);
	return ((1 << (8 - nb_bytes)) + ft_firstmask(nb_bytes - 1));
}

int						ft_wchar_to_str(wchar_t wc, char *dst)
{
	unsigned int	len;
	unsigned int	i;
	wchar_t			wc_tmp;

	len = ft_wcharlen(wc);
	if (len == 1 || (MB_CUR_MAX == 1 && wc <= 0xFF))
	{
		len = 1;
		dst[0] = (unsigned char)wc;
	}
	else
	{
		i = len;
		while (i)
		{
			wc_tmp = wc >> ((i - 1) * 6);
			wc_tmp = wc_tmp & 0x3F;
			dst[len - i] = (i == len ? ft_firstmask(len) : 0x80) | wc_tmp;
			i--;
		}
	}
	return (len);
}
