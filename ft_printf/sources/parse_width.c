/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 18:57:53 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:28:45 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include "characters.h"
#include "ft_printf_structs.h"

int		width_asterisk(t_env *e, va_list *args, t_conv *mod)
{
	int		width;

	mod->have_width = 1;
	width = va_arg(*args, int);
	if (width < 0)
	{
		mod->left_justify = 1;
		mod->pad_zeroes = 0;
	}
	mod->width = ABS(width);
	e->format++;
	return (0);
}

int		width(t_env *e, va_list *args, t_conv *mod)
{
	int		width;

	(void)args;
	width = 0;
	mod->have_width = 1;
	while (ft_isdigit((int)e->format[0]))
	{
		width = width * 10 + (e->format[0] - '0');
		e->format++;
	}
	mod->width = width;
	return (0);
}
