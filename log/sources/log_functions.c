/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 04:49:59 by upopee            #+#    #+#             */
/*   Updated: 2018/03/16 04:52:41 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "strings.h"
#include "log.h"

int				log_this(char *win_name, int l_flags, char *msg, ...)
{
	size_t		msg_len;
	t_logwin	*target;
	char		tmp[LOG_BUFF_SIZE + 1];
	va_list		args;

	if (!win_name || !(*win_name) || (target = get_logwin(win_name)) == NULL
		|| (msg_len = ft_strlen(msg)) > LOG_BUFF_SIZE)
		return (-1);
	if (l_flags == LF_ERR)
		ft_sprintf(tmp, "%s%s", LOG_ERR, msg);
	else if (l_flags == LF_WARN)
		ft_sprintf(tmp, "%s%s", LOG_WARN, msg);
	else if (l_flags == LF_INFO)
		ft_sprintf(tmp, "%s%s", LOG_INFO, msg);
	else
		ft_strcpy(tmp, msg);
	va_start(args, msg);
	ft_vdprintf(target->fd, tmp, args);
	va_end(args);
	return (0);
}
