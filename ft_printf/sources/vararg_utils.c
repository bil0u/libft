/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vararg_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:27:03 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:17:26 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include "maths.h"
#include "ft_printf_structs.h"

intmax_t	get_vararg_signed(t_conv *c, va_list *args)
{
	intmax_t	tmp;

	if (c->length < l)
	{
		tmp = va_arg(*args, int);
		if (c->length == none)
			tmp = (int)tmp;
		else if (c->length == hh)
			tmp = (signed char)tmp;
		else if (c->length == h)
			tmp = (short int)tmp;
		return (tmp);
	}
	else if (c->length == l)
		return (va_arg(*args, long int));
	else if (c->length == ll)
		return (va_arg(*args, long long int));
	else if (c->length == j)
		return (va_arg(*args, intmax_t));
	else if (c->length == z)
		return (va_arg(*args, size_t));
	else
		return (va_arg(*args, ptrdiff_t));
}

uintmax_t	get_vararg_unsigned(t_conv *c, va_list *args)
{
	intmax_t	tmp;

	if (c->length < l)
	{
		tmp = va_arg(*args, unsigned int);
		if (c->length == none)
			tmp = (unsigned int)tmp;
		if (c->length == hh)
			tmp = (unsigned char)tmp;
		else if (c->length == h)
			tmp = (unsigned short int)tmp;
		tmp = (unsigned int)tmp;
	}
	else if (c->length == l)
		tmp = va_arg(*args, unsigned long int);
	else if (c->length == ll)
		tmp = va_arg(*args, unsigned long long int);
	else if (c->length == j)
		tmp = va_arg(*args, uintmax_t);
	else if (c->length == z)
		tmp = va_arg(*args, size_t);
	else
		tmp = va_arg(*args, ptrdiff_t);
	return ((uintmax_t)tmp);
}
