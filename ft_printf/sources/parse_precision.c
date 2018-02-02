/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 18:57:59 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:29:10 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "characters.h"
#include "ft_printf_structs.h"

static int		precision_asterisk(t_env *e, va_list *args, t_conv *c)
{
	int		precision;

	e->format++;
	precision = va_arg(*args, int);
	if (precision < 0)
		return (0);
	c->have_precision = 1;
	c->precision = precision;
	return (0);
}

int				precision(t_env *e, va_list *args, t_conv *c)
{
	int		precision;

	e->format++;
	if (e->format[0] == '*')
		return (precision_asterisk(e, args, c));
	c->have_precision = 1;
	precision = 0;
	while (ft_isdigit((int)e->format[0]))
	{
		precision = precision * 10 + (e->format[0] - '0');
		e->format++;
	}
	c->precision = precision;
	return (0);
}
