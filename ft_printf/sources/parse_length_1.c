/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 19:01:55 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:29:21 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_structs.h"

int		mod_half(t_env *e, va_list *args, t_conv *c)
{
	t_length	tmp;

	(void)args;
	tmp = (e->format[1] == 'h' ? hh : h);
	if (c->length <= tmp)
		c->length = tmp;
	e->format += (tmp == hh ? 2 : 1);
	return (0);
}

int		mod_long(t_env *e, va_list *args, t_conv *c)
{
	t_length	tmp;

	(void)args;
	tmp = (e->format[1] == 'l' ? ll : l);
	if (c->length <= tmp)
		c->length = tmp;
	e->format += (tmp == ll ? 2 : 1);
	return (0);
}

int		mod_longdouble(t_env *e, va_list *args, t_conv *c)
{
	(void)args;
	c->length = L;
	e->format++;
	return (0);
}
