/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:29:43 by upopee            #+#    #+#             */
/*   Updated: 2018/03/13 14:24:42 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <signal.h>
#include "ft_printf.h"
#include "read_write.h"
#include "memory.h"
#include "strings.h"
#include "log.h"

int			ft_logthis(int fd, int flags, char *s)
{
	char		tmp[LOG_BUFF_SIZE];

	if (flags == LOG_F_ERR)
		ft_sprintf(tmp, "%s%s", LOG_ERR, s);
	else if (flags == LOG_F_WARN)
		ft_sprintf(tmp, "%s%s", LOG_WARN, s);
	else if (flags == LOG_F_INFO)
		ft_sprintf(tmp, "%s%s", LOG_INFO, s);
	else if (flags == 0)
		ft_sprintf(tmp, "%s", s);
	ft_dprintf(fd, tmp);
	return (0);
}

int			close_fifo(int fd, char *fifo, int flags)
{
	int		ret;

	ret = 0;
	if (fd != -1)
	{
		ret += close(fd);
		if (flags & LOG_F_VERBOSE)
		{
			if (ret)
				ft_dprintf(2, LOG_ERR_CLOSE, fifo, fd);
			else
				ft_printf(CLIENT_CLOSING, fifo);
		}
	}
	if (fifo)
		ret += remove(fifo);
	if (flags & LOG_F_CLOSE)
		kill(getppid(), SIGKILL);
	return (ret);
}
