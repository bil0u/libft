/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 04:49:59 by upopee            #+#    #+#             */
/*   Updated: 2018/04/09 08:26:33 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../../libft.h"
#include "ft_printf.h"
#include "strings.h"
#include "log.h"

int				vlog_this(char *win_name, int l_flags, char *msg, va_list ap)
{
	t_logwin	*target;
	int			fd;
	char		tmp[LOG_BUFF_SIZE + 1];
	va_list		args;

	if (!(l_flags & LF_NONE))
	{
		target = NULL;
		if ((win_name && (!(*win_name) || !(target = get_logwin(win_name))))
		|| (ft_strlen(msg) > LOG_BUFF_SIZE))
			return (-1);
		fd = (target == NULL || l_flags & LF_STDO) ? STDOUT_FILENO : target->fd;
		l_flags & LF_INFO ? ft_sprintf(tmp, "%s%s", LOG_ERR, msg) : (void)0;
		l_flags & LF_WARN ? ft_sprintf(tmp, "%s%s", LOG_ERR, msg) : (void)0;
		l_flags & LF_ERR ? ft_sprintf(tmp, "%s%s", LOG_ERR, msg) : (void)0;
		!(l_flags & ~(LF_STDO | LF_BOTH)) ? ft_strcpy(tmp, msg) : (void)0;
		va_copy(args, ap);
		ft_vdprintf(fd, tmp, args);
		if (l_flags & (LF_STDO | LF_BOTH) && fd != STDOUT_FILENO)
			ft_vdprintf(STDOUT_FILENO, tmp, args);
		va_end(args);
	}
	return (l_flags & LF_ERR ? FAILURE : SUCCESS);
}

int				log_this(char *win_name, int l_flags, char *msg, ...)
{
	va_list		args;

	va_start(args, msg);
	log_this(win_name, l_flags, msg, args);
	va_end(args);
	return (l_flags & LF_ERR ? FAILURE : SUCCESS);
}
