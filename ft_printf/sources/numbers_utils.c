/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 03:55:42 by upopee            #+#    #+#             */
/*   Updated: 2018/02/15 12:11:59 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf_structs.h"
#include "maths.h"
#include "memory.h"
#include "strings.h"

char	*utoa_base_prec(uintmax_t n, t_mod *m, size_t sz)
{
	size_t	nbr_len;
	char	*dst;

	nbr_len = ft_nbrlen_base(n, m->b_len);
	if (sz > nbr_len)
		nbr_len = sz;
	dst = ft_strnew(nbr_len);
	while (nbr_len-- > 0)
	{
		dst[nbr_len] = m->base[n % m->b_len];
		n /= m->b_len;
	}
	return (dst);
}

void	init_mod_nbr(t_conv *c, t_mod *m, uintmax_t nbr)
{
	m->b_len = ft_strlen(m->base);
	m->p_len = ft_strlen(c->prefix);
	if ((nbr == 0) && c->have_precision && (c->precision == 0))
		m->a_len = 0;
	else
		m->a_len = ft_nbrlen_base(nbr, m->b_len);
	m->delta = 0;
}

void	apply_parsing_nbr(t_conv *c, t_mod *m)
{
	if (c->have_precision)
		c->pad_zeroes = 0;
	if (c->pad_zeroes && c->have_width)
	{
		c->have_precision = 1;
		c->precision = c->width - (int)m->p_len;
	}
	if (c->have_precision && (size_t)c->precision > m->a_len)
		m->a_len = (size_t)c->precision;
	if (c->have_width)
		m->delta = c->width - (int)m->a_len - (int)m->p_len;
}

char	*add_prefix(char *s, char *p, size_t s_len, size_t p_len)
{
	char	*leak;

	leak = s;
	s = ft_strnew(p_len + s_len);
	ft_memmove(s, p, p_len);
	ft_memmove((s + p_len), leak, s_len);
	ft_strdel(&leak);
	return (s);
}
