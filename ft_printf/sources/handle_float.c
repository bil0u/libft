/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 18:39:58 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:36:16 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"
#include "memory.h"
#include "ft_printf_structs.h"
#include "float_utils.h"
#include "handle_utils.h"
#include "numbers_utils.h"

static char		*frac_to_base10(t_fraction *frac, t_conv *c, t_mod *m)
{
	char		*dst;
	char		*buff;
	size_t		d_len;
	uintmax_t	nbr;

	init_mod_float(frac, c, m);
	nbr = (frac->num / frac->den);
	buff = utoa_base_prec(nbr, m, 0);
	d_len = c->precision == 0 ? 0 : c->precision + 1;
	m->a_len = ft_strlen(buff) + d_len;
	dst = ft_strnew(m->a_len);
	ft_memmove(dst, buff, (m->a_len - d_len));
	ft_strdel(&buff);
	if (d_len)
	{
		dst[m->a_len - d_len] = DECIMAL_SEPARATOR;
		buff = get_decimal_base10(frac, m, c->precision);
		ft_memmove((dst + m->a_len - d_len + 1), buff, (d_len - 1));
		ft_strdel(&buff);
	}
	return (dst);
}

int				spec_float(t_env *e, va_list *args, t_conv *c)
{
	t_rawfloat	f_raw;
	char		*str;
	t_mod		m;

	ft_bzero(&m, sizeof(m));
	f_raw = rawfloat_fromarg(c, args);
	str = check_particular_values(e->format[0], &f_raw);
	if (str == NULL)
	{
		str = frac_to_base10(&(f_raw.frac), c, &m);
		str = add_prefix(str, c->prefix, m.a_len, m.p_len);
	}
	str_to_lst(e, str, c, &m);
	ft_strdel(&str);
	return (0);
}
