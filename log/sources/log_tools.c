/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:29:43 by upopee            #+#    #+#             */
/*   Updated: 2018/03/07 09:03:42 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "ft_printf.h"
#include "memory.h"
#include "strings.h"
#include "log.h"

t_logenv	*get_logservice_env(void)
{
	static t_logenv	env = {0, 0};

	return (&env);
}

int			item_fd_cmp(t_logwin *item, void *fd_ref)
{
	return (item->fd - *((int *)fd_ref));
}

int			item_fifo_cmp(t_logwin *item, void *fifo_ref)
{
	return (ft_strcmp(item->fifo, (char *)fifo_ref));
}

t_logwin	*find_logwin(void *data_ref, int (*cmp)())
{
	t_logenv	*env;
	t_list		*log_win;

	env = get_logservice_env();
	log_win = ft_lstfind(env->log_windows, data_ref, cmp);
	if (log_win)
		return (log_win->content);
	return (NULL);
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
				ft_printf(SERV_GOODBYE1, fifo);				// INFO Closing
		}
	}
	if (fifo)
		ret += remove(fifo);
	return (ret);
}

void		terminate_session(void *win_data, size_t size)
{
	t_logwin	*to_close;

	(void)size;
	to_close = (t_logwin *)win_data;
	if (close_pipe(to_close->fd, to_close->fifo, to_close->flags) > 0)
		ft_dprintf(2, LOG_ERR_CLOSE, to_close->fifo, to_close->fd);
	ft_strdel(&to_close->fifo);
	ft_memdel((void **)&to_close);
}
