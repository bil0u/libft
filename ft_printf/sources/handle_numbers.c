/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 18:39:10 by upopee            #+#    #+#             */
/*   Updated: 2018/03/30 21:44:52 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"
#include "wide_strings.h"
#include "characters.h"
#include "memory.h"
#include "ft_printf_structs.h"
#include "handle_utils.h"
#include "vararg_utils.h"
#include "numbers_utils.h"

int		spec_digit(t_env *e, va_list *args, t_conv *c)
{
	intmax_t	tmp;
	uintmax_t	nbr;
	char		*str;
	t_mod		m;

	ft_bzero(&m, sizeof(m));
	m.base = BASE_10;
	if (ft_isupper(e->format[0]))
		c->length = l;
	tmp = get_vararg_signed(c, args);
	if (tmp < 0)
		c->prefix = "-";
	nbr = ft_abs(tmp);
	init_mod_nbr(c, &m, nbr);
	apply_parsing_nbr(c, &m);
	str = utoa_base_prec(nbr, &m, m.a_len);
	str = add_prefix(str, c->prefix, m.a_len, m.p_len);
	str_to_lst(e, str, c, &m);
	ft_strdel(&str);
	return (0);
}

int		spec_unsigned(t_env *e, va_list *args, t_conv *c)
{
	uintmax_t	nbr;
	char		*str;
	t_mod		m;

	ft_bzero(&m, sizeof(m));
	c->prefix = "";
	m.base = BASE_10;
	if (ft_isupper(e->format[0]))
		c->length = l;
	nbr = get_vararg_unsigned(c, args);
	init_mod_nbr(c, &m, nbr);
	apply_parsing_nbr(c, &m);
	str = utoa_base_prec(nbr, &m, m.a_len);
	str_to_lst(e, str, c, &m);
	ft_strdel(&str);
	return (0);
}

int		spec_octal(t_env *e, va_list *args, t_conv *c)
{
	uintmax_t	nbr;
	char		*str;
	t_mod		m;

	ft_bzero(&m, sizeof(m));
	c->prefix = "";
	m.base = BASE_8;
	if (ft_isupper(e->format[0]))
		c->length = l;
	nbr = get_vararg_unsigned(c, args);
	init_mod_nbr(c, &m, nbr);
	if (c->alt)
	{
		if (nbr == 0)
			m.a_len = 1;
		else
			m.a_len++;
	}
	apply_parsing_nbr(c, &m);
	str = utoa_base_prec(nbr, &m, m.a_len);
	str_to_lst(e, str, c, &m);
	ft_strdel(&str);
	return (0);
}

int		spec_hexa(t_env *e, va_list *args, t_conv *c)
{
	uintmax_t	nbr;
	char		*str;
	t_mod		m;

	ft_bzero(&m, sizeof(m));
	c->prefix = "";
	m.base = e->format[0] == 'x' ? BASE_16_LOWER : BASE_16_UPPER;
	nbr = get_vararg_unsigned(c, args);
	if (nbr > 0 && c->alt)
		c->prefix = e->format[0] == 'x' ? "0x" : "0X";
	init_mod_nbr(c, &m, nbr);
	apply_parsing_nbr(c, &m);
	str = utoa_base_prec(nbr, &m, m.a_len);
	str = add_prefix(str, c->prefix, m.a_len, m.p_len);
	str_to_lst(e, str, c, &m);
	ft_strdel(&str);
	return (0);
}

int		spec_binary(t_env *e, va_list *args, t_conv *c)
{
	intmax_t	tmp;
	uintmax_t	nbr;
	char		*str;
	t_mod		m;

	ft_bzero(&m, sizeof(m));
	m.base = BASE_2;
	tmp = get_vararg_unsigned(c, args);
	if (c->alt)
		c->prefix = "0b";
	nbr = ft_abs(tmp);
	init_mod_nbr(c, &m, nbr);
	apply_parsing_nbr(c, &m);
	str = utoa_base_prec(nbr, &m, m.a_len);
	str = add_prefix(str, c->prefix, ft_strlen(str), m.p_len);
	str_to_lst(e, str, c, &m);
	ft_strdel(&str);
	return (0);
}
