/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 19:01:58 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:29:33 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_structs.h"

int		mod_size_t(t_env *e, va_list *args, t_conv *c)
{
	(void)args;
	c->length = z;
	e->format++;
	return (0);
}

int		mod_intmax_t(t_env *e, va_list *args, t_conv *c)
{
	(void)args;
	c->length = j;
	e->format++;
	return (0);
}

int		mod_ptrdiff_t(t_env *e, va_list *args, t_conv *c)
{
	(void)args;
	c->length = t;
	e->format++;
	return (0);
}
