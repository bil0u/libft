/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 22:43:01 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:12:29 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_UTILS_H
# define CHAR_UTILS_H

# include <stddef.h>
# include "ft_printf_structs.h"

void		apply_parsing_char(t_env *e, t_conv *c, t_mod *m);
size_t		wcharlen_locale(wchar_t wc);
size_t		wstrbyteslen_locale(wchar_t const *s);

#endif
