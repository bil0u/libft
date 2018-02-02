/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 19:01:48 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:27:53 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_structs.h"

int		flag_hash(t_env *e, va_list *args, t_conv *c)
{
	(void)args;
	c->alt = 1;
	e->format++;
	return (0);
}

int		flag_quote(t_env *e, va_list *args, t_conv *c)
{
	(void)args;
	c->group_thousand = 1;
	e->format++;
	return (0);
}
