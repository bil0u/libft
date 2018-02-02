/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:58:39 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:11:41 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_FUNCTIONS_H
# define PROCESS_FUNCTIONS_H

# include <stdarg.h>
# include "ft_printf_structs.h"

int		process_format(t_env *e, va_list *args);

#endif
