/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 04:49:59 by upopee            #+#    #+#             */
/*   Updated: 2018/04/21 22:33:26 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../../libft.h"
#include "ft_printf.h"
#include "strings.h"
#include "log.h"

static void		prep_logbuffer(char *buff, int l_flags, char *msg)
{
	if (l_flags & LF_INFO)
		ft_sprintf(buff, "%s%s", LOG_ERR, msg);
	else if (l_flags & LF_WARN)
		ft_sprintf(buff, "%s%s", LOG_ERR, msg);
	else if (l_flags & LF_ERR)
		ft_sprintf(buff, "%s%s", LOG_ERR, msg);
	else
		ft_strcpy(buff, msg);
}

int				vlog_this(char *win_name, int l_flags, char *msg, va_list ap)
{
	t_logwin	*target;
	char		buff[LOG_BUFF_SIZE + 1];
	va_list		args;

	if (ft_strlen(msg) > LOG_BUFF_SIZE)
		return (-1);
	prep_logbuffer(buff, l_flags, msg);
	va_copy(args, ap);
	if ((!(target = get_logwin(win_name)) && !win_name)
	|| (l_flags & (LF_STDO | LF_BOTH)))
		ft_vdprintf(STDOUT_FILENO, buff, args);
	if (target && !((l_flags & LF_STDO) && !(l_flags & LF_BOTH)))
		ft_vdprintf(target->fd, buff, args);
	va_end(args);
	return (l_flags & LF_ERR ? FAILURE : SUCCESS);
}

int				log_this(char *win_name, int l_flags, char *msg, ...)
{
	t_logwin	*target;
	char		buff[LOG_BUFF_SIZE + 1];
	va_list		args;

	if (ft_strlen(msg) > LOG_BUFF_SIZE)
		return (-1);
	prep_logbuffer(buff, l_flags, msg);
	va_start(args, msg);
	if ((!(target = get_logwin(win_name)) && !win_name)
	|| (l_flags & (LF_STDO | LF_BOTH)))
		ft_vdprintf(STDOUT_FILENO, buff, args);
	if (target && !((l_flags & LF_STDO) && !(l_flags & LF_BOTH)))
		ft_vdprintf(target->fd, buff, args);
	va_end(args);
	return (l_flags & LF_ERR ? FAILURE : SUCCESS);
}
