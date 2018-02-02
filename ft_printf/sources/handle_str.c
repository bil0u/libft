/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 18:42:34 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:32:49 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "strings.h"
#include "wide_strings.h"
#include "memory.h"
#include "ft_printf_structs.h"
#include "char_utils.h"
#include "handle_utils.h"

static	int		check_wstr(wchar_t *ws, int len)
{
	unsigned int	i;

	i = 0;
	if (MB_CUR_MAX > 1)
		return (1);
	while (ws[i] && len-- > 0)
	{
		if (ws[i] > 255)
			return (-1);
		i++;
	}
	return (1);
}

static size_t	trim_wstr(wchar_t *ws, int max_len)
{
	int		i;
	int		curr_len;
	int		ret;

	ret = 0;
	i = 0;
	curr_len = wcharlen_locale(ws[i]);
	while (ws[i] && (max_len - curr_len) >= 0)
	{
		max_len -= curr_len;
		ret += curr_len;
		i++;
		curr_len = wcharlen_locale(ws[i]);
	}
	ws[i] = L'\0';
	return ((size_t)ret);
}

int				spec_wstring(t_env *e, va_list *args, t_conv *c)
{
	wchar_t			*tmp;
	wchar_t			*wstr;
	unsigned char	*str;
	t_mod			m;
	int				ret;

	ft_bzero(&m, sizeof(m));
	c->prefix = "";
	if ((tmp = va_arg(*args, wchar_t*)) == NULL)
		tmp = L"(null)";
	wstr = ft_wstrdup(tmp);
	m.a_len = ft_wstrbyteslen(wstr);
	if (c->have_precision && m.a_len > (size_t)c->precision)
		m.a_len = trim_wstr(wstr, c->precision);
	ret = check_wstr(wstr, m.a_len);
	if (ret)
	{
		ft_wstr_to_astr(wstr, (char **)&str);
		apply_parsing_char(e, c, &m);
		str_to_lst(e, (char *)str, c, &m);
		ft_strdel((char **)&str);
	}
	ft_wstrdel(&wstr);
	return (ret);
}

int				spec_string(t_env *e, va_list *args, t_conv *c)
{
	char	*str;
	t_mod	m;

	ft_bzero(&m, sizeof(m));
	c->prefix = "";
	if (c->length == l)
		return (spec_wstring(e, args, c));
	if ((str = va_arg(*args, char*)) == NULL)
		str = "(null)";
	str = ft_strdup(str);
	m.a_len = ft_strlen(str);
	if (c->have_precision && m.a_len > (size_t)c->precision)
	{
		str[c->precision] = '\0';
		m.a_len = (size_t)c->precision;
	}
	apply_parsing_char(e, c, &m);
	str_to_lst(e, str, c, &m);
	ft_strdel(&str);
	return (0);
}
