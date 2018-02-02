/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:25:46 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:23:51 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float_utils.h"
#include "numbers_utils.h"
#include "memory.h"
#include "maths.h"

static t_rawfloat	float_to_raw(t_conv *c, va_list *args)
{
	double			tmp64;
	long double		tmp128;
	uint128_t		raw128;
	t_rawfloat		f;

	ft_bzero(&f, sizeof(f));
	if (c->length != L)
	{
		tmp64 = va_arg(*args, double);
		tmp128 = (long double)tmp64;
	}
	else
		tmp128 = va_arg(*args, long double);
	ft_memcpy(&raw128, &tmp128, sizeof(raw128));
	f.exp_size = 15;
	f.man_size = 63;
	f.raw_isneg = (raw128 >> (f.exp_size + f.man_size + 1)) & 1;
	f.raw_exponent = (raw128 >> (f.man_size + 1)) & E_OVERFLOW(f);
	f.raw_intpart = (raw128 >> f.man_size) & 1;
	f.raw_mantissa = raw128 & M_OVERFLOW(f);
	return (f);
}

static void			reduce_frac(t_fraction *frac)
{
	intmax_t		pgcd;

	pgcd = ft_pgcd(frac->num, frac->den);
	if (pgcd > 1)
	{
		frac->num /= pgcd;
		frac->den /= pgcd;
	}
}

t_rawfloat			rawfloat_fromarg(t_conv *c, va_list *args)
{
	uint128_t		power;
	t_rawfloat		f;

	f = float_to_raw(c, args);
	power = 1;
	while (power <= f.man_size)
	{
		if (((f.raw_mantissa >> (f.man_size - power)) & 1) == 1)
		{
			f.frac.num = 1 + (f.frac.num * TWO_EXP(power - f.frac.den));
			f.frac.den = power;
		}
		power++;
	}
	f.frac.den = TWO_EXP(f.frac.den);
	reduce_frac(&(f.frac));
	if (f.raw_intpart == 1)
		f.frac.num += f.frac.den;
	if (EXP_VAL(f) < 0)
		f.frac.den *= TWO_EXP(ABS(EXP_VAL(f)));
	else
		f.frac.num *= TWO_EXP(EXP_VAL(f));
	f.frac.sign = (f.raw_isneg ? -1 : 1);
	return (f);
}

char				*get_decimal_base10(t_fraction *frac, t_mod *m, int prec)
{
	uint128_t	nbr;
	int			i;
	char		*buff;

	nbr = 0;
	i = 0;
	while (i < prec)
	{
		frac->num -= ((frac->num / frac->den) * frac->den);
		frac->num *= 10;
		nbr = (nbr * 10) + (frac->num / frac->den);
		i++;
	}
	nbr += (frac->num / frac->den) < 5 ? 0 : 1;
	buff = utoa_base_prec(nbr, m, prec);
	return (buff);
}
