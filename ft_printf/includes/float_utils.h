/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:30:22 by upopee            #+#    #+#             */
/*   Updated: 2018/02/15 17:59:09 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_UTILS_H
# define FLOAT_UTILS_H

# include <stdarg.h>
# include "maths.h"
# include "ft_printf_structs.h"

# define E_OFFSET(f) ( (1 << (f.exp_size - 1)) - 1 )
# define E_OVERFLOW(f) ( (1ULL << f.exp_size) - 1 )
# define M_OVERFLOW(f) ( (1ULL << f.man_size) - 1 )

# define EXP_VAL(f) ((f.raw_exponent ? (int)f.raw_exponent : 1) - E_OFFSET(f))
# define TWO_EXP(x) ( 1ULL << (x) )

typedef struct		s_fraction
{
	int				sign;
	t_uint128_t		num;
	t_uint128_t		den;
}					t_fraction;

typedef struct		s_rawfloat
{
	size_t			exp_size;
	size_t			man_size;
	t_uint128_t		raw_isneg;
	t_uint128_t		raw_exponent;
	t_uint128_t		raw_intpart;
	t_uint128_t		raw_mantissa;
	t_fraction		frac;
}					t_rawfloat;

char				*check_particular_values(char current, t_rawfloat *f);
t_rawfloat			rawfloat_fromarg(t_conv *mod, va_list *args);
void				init_mod_float(t_fraction *frac, t_conv *c, t_mod *m);
char				*get_decimal_base10(t_fraction *frac,
										t_mod *m, int precision);

#endif
