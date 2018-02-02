/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:25:46 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:24:26 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"
#include "characters.h"
#include "float_utils.h"

char		*check_particular_values(char current, t_rawfloat *f)
{
	char			*str;

	str = NULL;
	if (f->raw_exponent == E_OVERFLOW((*f)))
	{
		if (f->raw_mantissa == 0)
			str = ft_strdup(f->raw_isneg ? "-inf" : "inf");
		else
			str = ft_strdup("nan");
		if (ft_isupper(current))
			ft_strtoupper(str);
	}
	return (str);
}

void		init_mod_float(t_fraction *frac, t_conv *c, t_mod *m)
{
	if (frac->sign < 0)
		c->prefix = "-";
	m->base = BASE_10;
	m->b_len = ft_strlen(m->base);
	m->p_len = ft_strlen(c->prefix);
	if (c->have_precision == 0)
		c->precision = 6;
}
