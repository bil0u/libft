/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_others.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 18:56:39 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:37:10 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "ft_printf_structs.h"
#include "handle_utils.h"
#include "char_utils.h"

int		spec_unknown(t_env *e, va_list *args, t_conv *c)
{
	char		str[2];
	t_mod		m;

	(void)args;
	str[0] = e->format[0];
	str[1] = '\0';
	ft_bzero(&m, sizeof(m));
	m.a_len = 1;
	apply_parsing_char(e, c, &m);
	str_to_lst(e, str, c, &m);
	return (0);
}

int		spec_percent(t_env *e, va_list *args, t_conv *c)
{
	char		str[2];
	t_mod		m;

	(void)args;
	str[0] = '%';
	str[1] = '\0';
	ft_bzero(&m, sizeof(m));
	m.a_len = 1;
	apply_parsing_char(e, c, &m);
	str_to_lst(e, str, c, &m);
	return (0);
}
