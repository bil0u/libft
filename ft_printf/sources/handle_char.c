/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 18:42:28 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:31:44 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>
#include "memory.h"
#include "strings.h"
#include "wide_strings.h"
#include "ft_printf_structs.h"
#include "char_utils.h"
#include "handle_utils.h"

int		spec_wcharacter(t_env *e, va_list *args, t_conv *c)
{
	wchar_t		wc;
	char		*str;
	t_mod		m;

	wc = (wchar_t)va_arg(*args, wint_t);
	if (MB_CUR_MAX == 1 && wc > 0xFF)
		return (-1);
	ft_bzero(&m, sizeof(m));
	m.a_len = (MB_CUR_MAX == 1 ? 1 : ft_wcharlen(wc));
	apply_parsing_char(e, c, &m);
	ft_wchar_to_astr(wc, &str);
	str_to_lst(e, str, c, &m);
	ft_strdel(&str);
	return (0);
}

int		spec_character(t_env *e, va_list *args, t_conv *c)
{
	char		str[2];
	t_mod		m;

	if (c->length == l)
		return (spec_wcharacter(e, args, c));
	str[0] = (char)va_arg(*args, int);
	str[1] = '\0';
	ft_bzero(&m, sizeof(m));
	m.a_len = 1;
	apply_parsing_char(e, c, &m);
	str_to_lst(e, str, c, &m);
	return (0);
}
