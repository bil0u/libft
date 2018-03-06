/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:40:45 by upopee            #+#    #+#             */
/*   Updated: 2018/03/05 23:08:29 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "strings.h"
#include "memory.h"
#include "ft_printf.h"

int			open_window(char *name, uint8_t flags)
{
	uint8_t		len;
	t_winenv	*env;
	t_win		new_window;

	ft_bzero(&new_window, sizeof(new_window));
	if (!name || (len = ft_strlen(name)) >= WINDOW_NAME_MAX_SIZE || len == 0)
	{
		if (flags & VERBOSE)
			ft_dprintf(2, len ? ERR_NAME : ERR_NO_NAME, WINDOW_NAME_MAX_SIZE);
		return (-1);
	}
	env = get_winenv();
	if (mkfifo(name, 0666) == -1 && flags & VERBOSE)
		ft_dprintf(2, ERR_MKFIFO, name);
	else if ((new_window.fd = open(name, O_RDONLY)) == -1 && flags & VERBOSE)
		ft_dprintf(2, ERR_OPEN, name);
	else
	{
		ft_strncpy(new_window.name, name, len);
		new_window.flags = flags;
		ft_lstadd(&(env->windows), ft_lstnew(&new_window, sizeof(new_window)));
		if (flags & VERBOSE)
			ft_dprintf(1, OPEN_MSG, name, new_window.fd);
	}
	return (new_window.fd);
}

int			item_fd_cmp(t_win *item, void *fd_ref)
{
	return (item->fd == *((int *)fd_ref));
}

void		terminate_session(void *win_data, size_t size)
{
	t_win	*to_close;

	(void)size;
	to_close = (t_win *)win_data;
	if (close(to_close->fd) == -1 && to_close->flags & VERBOSE)
		ft_dprintf(2, ERR_CLOSE, to_close->name, to_close->fd);
	else if (to_close->flags & VERBOSE)
		ft_dprintf(1, CLOSE_MSG, to_close->name, to_close->fd);
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
	t_list		*curr;

	env = get_winenv();
	(void)curr;
}

int			print_to_window(int fd, char *msg)
{
	(void)fd;
	(void)msg;
	return (0);
}
