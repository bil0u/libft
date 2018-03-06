/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:40:45 by upopee            #+#    #+#             */
/*   Updated: 2018/03/06 19:28:44 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "debug.h"
#include "strings.h"
#include "memory.h"
#include "ft_printf.h"

static void	clean_fd(int fd, char *fifo)
{
	if (fd != -1)
	{
		if (close(fd) == -1)
			ft_dprintf(2, ERR_CLOSE, fifo, fd);
		else
			ft_printf(SERV_GOODBYE1);
	}
	if (fifo)
	{
		unlink(fifo);
		remove(fifo);
	}
}

int			open_window(char *fifo)
{
	t_winenv	*env;
	t_win		new_window;

	ft_bzero(&new_window, sizeof(new_window));
	if (!fifo || ft_strlen(fifo) == 0)
	{
		ft_dprintf(2, ERR_NAME);
		return (-1);
	}
	if (mkfifo(fifo, 0666) == -1
		|| (new_window.fd = open(fifo, O_RDONLY|O_NONBLOCK)) == -1)
	{
		ft_dprintf(2, SERV_OPEN_ERR, fifo);
		clean_fd(new_window.fd, fifo);
		return (-1);
	}
	new_window.fifo = ft_strdup(fifo);
	env = get_winenv();
	ft_lstadd(&(env->windows), ft_lstnew(&new_window, sizeof(new_window)));
	ft_printf(CLIENT_OPEN_SUCCESS, new_window.fifo, new_window.fd);
	return (new_window.fd);
}

int			item_fd_cmp(t_win *item, void *fd_ref)
{
	return ((item->fd == *((int *)fd_ref)) == 0);
}

void		terminate_session(void *win_data, size_t size)
{
	t_win	*to_close;

	(void)size;
	to_close = (t_win *)win_data;
	clean_fd(to_close->fd, to_close->fifo);
	ft_strdel(&to_close->fifo);
	ft_memdel((void **)&to_close);
}

int			close_window(int fd)
{
	t_winenv	*env;

	if (fd < 3)
	{
		ft_dprintf(2, ERR_BADFD, fd);
		return (-1);
	}
	env = get_winenv();
	if (ft_lstdelif(&env->windows, &fd, &item_fd_cmp, &terminate_session) != 0)
	{
		ft_dprintf(2, ERR_NOTFOUND, fd);
		return (-1);
	}
	return (0);
}

void		close_allwindows(void)
{
	t_winenv	*env;

	env = get_winenv();
	ft_lstdel(&env->windows, &terminate_session);
}

int			print_to_window(int fd, char *msg)
{
	(void)fd;
	(void)msg;
	return (0);
}
