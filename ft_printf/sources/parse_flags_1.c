/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 19:01:45 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:27:23 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_structs.h"

int		flag_zero(t_env *e, va_list *args, t_conv *c)
{
	(void)args;
	if (c->left_justify == 0)
		c->pad_zeroes = 1;
	e->format++;
	return (0);
}

int		flag_minus(t_env *e, va_list *args, t_conv *c)
{
	(void)args;
	c->pad_zeroes = 0;
	c->left_justify = 1;
	e->format++;
	return (0);
}

int		flag_space(t_env *e, va_list *args, t_conv *c)
{
	(void)args;
	if (c->prefix[0] == '\0')
		c->prefix = " ";
	e->format++;
	return (0);
}

int		flag_plus(t_env *e, va_list *args, t_conv *c)
{
	(void)args;
	c->prefix = "+";
	e->format++;
	return (0);
}
