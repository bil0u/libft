/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:30:24 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:21:34 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "handle_utils.h"

void		apply_parsing_char(t_env *e, t_conv *c, t_mod *m)
{
	if (c->have_width)
		m->delta = c->width - (int)m->a_len;
	if (!c->left_justify && m->delta && c->pad_zeroes)
	{
		pad_to_lst(e, '0', m->delta);
		m->delta = 0;
	}
}

size_t		wcharlen_locale(wchar_t wc)
{
	size_t	len;
	int		shift;

	if (MB_CUR_MAX == 1 || wc <= 0x7F)
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
