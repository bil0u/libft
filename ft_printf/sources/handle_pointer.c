/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 18:43:15 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:35:42 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"
#include "maths.h"
#include "linked_lists.h"
#include "ft_printf_structs.h"
#include "handle_utils.h"
#include "numbers_utils.h"

int		spec_pointer(t_env *e, va_list *args, t_conv *c)
{
	intptr_t	ptr;
	char		*str;
	t_mod		m;

	ptr = (intptr_t)va_arg(*args, void*);
	m.base = BASE_16_LOWER;
	c->prefix = "0x";
	init_mod_nbr(c, &m, ptr);
	apply_parsing_nbr(c, &m);
	str = utoa_base_prec(ptr, &m, m.a_len);
	str = add_prefix(str, c->prefix, m.a_len, m.p_len);
	str_to_lst(e, str, c, &m);
	ft_strdel(&str);
	return (0);
}

int		spec_toaddress(t_env *e, va_list *args, t_conv *c)
{
	intmax_t	*ptr;

	ptr = va_arg(*args, intmax_t*);
	if (ptr)
	{
		if (c->length == none)
			*ptr = (int)e->ret;
		else if (c->length == hh)
			*ptr = (signed char)e->ret;
		else if (c->length == h)
			*ptr = (short int)e->ret;
		else if (c->length == l)
			*ptr = (long int)e->ret;
		else if (c->length == ll)
			*ptr = (long long int)e->ret;
		else if (c->length == j)
			*ptr = (intmax_t)e->ret;
		else if (c->length == z)
			*ptr = (size_t)e->ret;
		else
			*ptr = (ptrdiff_t)e->ret;
	}
	return (0);
}
