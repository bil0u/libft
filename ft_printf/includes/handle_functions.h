/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 22:56:45 by upopee            #+#    #+#             */
/*   Updated: 2017/07/26 20:14:33 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_FUNCTIONS_H
# define HANDLE_FUNCTIONS_H

# include "ft_printf.h"

int		spec_unknown(t_env *e, va_list *args, t_conv *mod);
int		flag_hash(t_env *e, va_list *args, t_conv *mod);
int		flag_zero(t_env *e, va_list *args, t_conv *mod);
int		flag_minus(t_env *e, va_list *args, t_conv *mod);
int		flag_space(t_env *e, va_list *args, t_conv *mod);
int		flag_plus(t_env *e, va_list *args, t_conv *mod);
int		flag_quote(t_env *e, va_list *args, t_conv *mod);
int		width_asterisk(t_env *e, va_list *args, t_conv *mod);
int		width(t_env *e, va_list *args, t_conv *mod);
int		precision(t_env *e, va_list *args, t_conv *mod);
int		mod_half(t_env *e, va_list *args, t_conv *mod);
int		mod_long(t_env *e, va_list *args, t_conv *mod);
int		mod_size_t(t_env *e, va_list *args, t_conv *mod);
int		mod_intmax_t(t_env *e, va_list *args, t_conv *mod);
int		mod_ptrdiff_t(t_env *e, va_list *args, t_conv *mod);
int		mod_longdouble(t_env *e, va_list *args, t_conv *mod);
int		spec_percent(t_env *e, va_list *args, t_conv *mod);
int		spec_digit(t_env *e, va_list *args, t_conv *mod);
int		spec_unsigned(t_env *e, va_list *args, t_conv *mod);
int		spec_octal(t_env *e, va_list *args, t_conv *mod);
int		spec_hexa(t_env *e, va_list *args, t_conv *mod);
int		spec_binary(t_env *e, va_list *args, t_conv *c);
int		spec_float(t_env *e, va_list *args, t_conv *mod);
int		spec_float_hex(t_env *e, va_list *args, t_conv *mod);
int		spec_float_scientific(t_env *e, va_list *args, t_conv *mod);
int		spec_float_auto(t_env *e, va_list *args, t_conv *mod);
int		spec_character(t_env *e, va_list *args, t_conv *mod);
int		spec_wcharacter(t_env *e, va_list *args, t_conv *mod);
int		spec_string(t_env *e, va_list *args, t_conv *mod);
int		spec_wstring(t_env *e, va_list *args, t_conv *mod);
int		spec_pointer(t_env *e, va_list *args, t_conv *mod);
int		spec_toaddress(t_env *e, va_list *args, t_conv *mod);

#endif
