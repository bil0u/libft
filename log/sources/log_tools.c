/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:29:43 by upopee            #+#    #+#             */
/*   Updated: 2018/03/07 04:32:01 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "ft_printf.h"
#include "memory.h"
#include "strings.h"
#include "log.h"

t_winenv	*get_winenv(void)
{
	static t_winenv	env = {0, 0};

	return (&env);
}

int			item_fd_cmp(t_win *item, void *fd_ref)
{
	return (item->fd - *((int *)fd_ref));
}

int			close_pipe(int fd, char *fifo, int s_flags)
{
	int		ret;

	ret = 0;
	if (fd != -1)
	{
		ret += close(fd);
		if (s_flags & LOG_VERBOSE)
		{
			if (ret)
				ft_dprintf(2, LOG_ERR_CLOSE, fifo, fd);		// ERROR Closing
			else
				ft_printf(SERV_GOODBYE1);					// INFO Closing
		}
	}
	if (fifo)
		ret += unlink(fifo);
	return (ret);
}

void		terminate_session(void *win_data, size_t size)
{
	t_win	*to_close;

	(void)size;
	to_close = (t_win *)win_data;
	if (close_pipe(to_close->fd, to_close->fifo, to_close->flags) == 0)
	{
		ft_strdel(&to_close->fifo);
		ft_memdel((void **)&to_close);
	}
	else
		ft_dprintf(2, LOG_ERR_CLOSE, to_close->fifo, to_close->fd);
}
