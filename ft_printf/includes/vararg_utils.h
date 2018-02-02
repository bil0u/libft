/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vararg_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:30:15 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:33:25 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARARG_UTILS_H
# define VARARG_UTILS_H

# include <stdarg.h>
# include "maths.h"
# include "ft_printf_structs.h"

intmax_t		get_vararg_signed(t_conv *mod, va_list *args);
uintmax_t		get_vararg_unsigned(t_conv *mod, va_list *args);

#endif
