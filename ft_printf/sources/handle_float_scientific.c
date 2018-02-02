/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float_scientific.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 18:40:07 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:36:51 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"
#include "maths.h"
#include "characters.h"
#include "memory.h"
#include "ft_printf_structs.h"
#include "float_utils.h"
#include "handle_utils.h"
#include "numbers_utils.h"

static int		power_pos_b10(char **dst, t_fraction *frac, t_conv *c, t_mod *m)
{
	char		*buff;
	int			power;
	int			len;

	(*dst) = ft_strnew(1 + (c->precision ? c->precision + 1 : 0));
	buff = utoa_base_prec((frac->num / frac->den), m, 0);
	if (buff[c->precision + 1] >= '5')
		buff[c->precision] += 1;
	power = ft_strlen(buff) - 1;
	(*dst)[0] = buff[0];
	if (c->precision > 0)
	{
		(*dst)[1] = DECIMAL_SEPARATOR;
		len = c->precision < power ? c->precision : power;
		ft_memmove(((*dst) + 2), (buff + 1), len);
		if (c->precision > len)
		{
			ft_strdel(&buff);
			buff = get_decimal_base10(frac, m, (c->precision - len));
			ft_memmove(((*dst) + 2 + len), buff, (c->precision - len));
		}
	}
	ft_strdel(&buff);
	return (power);
}

static int		power_neg_b10(char **dst, t_fraction *frac, t_conv *c, t_mod *m)
{
	char		*buff;
	int			power;

	(*dst) = ft_strnew(1 + (c->precision ? c->precision + 1 : 0));
	power = 0;
	if (frac->num == 0 || frac->den == 0)
		power = 0;
	else
	{
		while (frac->num / frac->den == 0)
		{
			frac->num *= 10;
			power++;
		}
		frac->num /= 10;
	}
	buff = get_decimal_base10(frac, m, c->precision + 1);
	(*dst)[0] = buff[0];
	if (c->precision > 0)
	{
		(*dst)[1] = DECIMAL_SEPARATOR;
		ft_memmove(((*dst) + 2), (buff + 1), c->precision);
	}
	ft_strdel(&buff);
	return (-power);
}

static char		*frac_to_sci(t_fraction *frac, t_conv *c, t_mod *m, char curr)
{
	char		*dst;
	char		*nbr;
	char		*exponent;
	size_t		nbr_len;
	int			p;

	init_mod_float(frac, c, m);
	if (frac->num / frac->den > 0)
		p = power_pos_b10(&nbr, frac, c, m);
	else
		p = power_neg_b10(&nbr, frac, c, m);
	exponent = utoa_base_prec(ABS(p), m, 2);
	nbr_len = ft_strlen(nbr);
	m->a_len = nbr_len + 2 + ft_strlen(exponent);
	dst = ft_strnew(m->a_len);
	ft_memmove(dst, nbr, nbr_len);
	dst[nbr_len] = ft_isupper(curr) ? 'E' : 'e';
	dst[nbr_len + 1] = p < 0 ? '-' : '+';
	ft_memmove((dst + nbr_len + 2), exponent, (m->a_len - nbr_len - 2));
	ft_strdel(&nbr);
	ft_strdel(&exponent);
	return (dst);
}

int				spec_float_scientific(t_env *e, va_list *args, t_conv *c)
{
	t_rawfloat	f_raw;
	char		*str;
	t_mod		m;

	ft_bzero(&m, sizeof(m));
	f_raw = rawfloat_fromarg(c, args);
	str = check_particular_values(e->format[0], &f_raw);
	if (str == NULL)
	{
		str = frac_to_sci(&(f_raw.frac), c, &m, e->format[0]);
		str = add_prefix(str, c->prefix, m.a_len, m.p_len);
	}
	str_to_lst(e, str, c, &m);
	ft_strdel(&str);
	return (0);
}
