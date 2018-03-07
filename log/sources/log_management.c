/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:40:45 by upopee            #+#    #+#             */
/*   Updated: 2018/03/07 04:57:55 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>
#include "strings.h"
#include "memory.h"
#include "ft_printf.h"
#include "log.h"

int		open_window_new(char *fifo)
{
//	t_winenv	*env;
	t_win		new_window;

	ft_bzero(&new_window, sizeof(new_window));
	if (!fifo || ft_strlen(fifo) == 0)
	{
		ft_dprintf(2, LOG_ERR_NONAME);
		return (-1);
	}
//	system();
	return (0);
}

int		open_window(char *fifo, int s_flags)
{
	t_winenv	*env;
	t_win		new_window;
	int			o_flags;

	ft_bzero(&new_window, sizeof(new_window));
	if (!fifo || ft_strlen(fifo) == 0)
	{
		ft_dprintf(2, LOG_ERR_NONAME);
		return (-1);
	}
	o_flags = O_RDONLY|O_NONBLOCK;
	if ((new_window.fd = open(fifo, o_flags)) == -1)
	{
		ft_dprintf(2, SERV_OPENERR, fifo);
		close_pipe(new_window.fd, fifo, s_flags);
		return (-1);
	}
	new_window.fifo = ft_strdup(fifo);
	env = get_winenv();
	ft_lstadd(&(env->windows), ft_lstnew(&new_window, sizeof(new_window)));
	ft_printf(CLIENT_RUN, new_window.fifo, new_window.fd);
	return (new_window.fd);
}


int		close_window(int fd)
{
	t_winenv	*env;

	if (fd == -1)
	{
		ft_dprintf(2, LOG_ERR_BADFD, fd);
		return (-1);
	}
	env = get_winenv();
	if (ft_lstdelif(&env->windows, &fd, &item_fd_cmp, &terminate_session) != 0)
	{
		ft_dprintf(2, LOG_ERR_NOFD, fd);
		return (-1);
	}
	return (0);
}

void	close_allwindows(void)
{
	t_winenv	*env;

	env = get_winenv();
	ft_lstdel(&env->windows, &terminate_session);
}

int		print_to_window(int fd, char *msg)
{
	t_winenv	*env;

	env = get_winenv();
	if (ft_lstfind(env->windows, &fd, &item_fd_cmp) == NULL)
	{
		ft_dprintf(2, LOG_ERR_NOFD, fd);
		return (-1);
	}
	else
	{
		ft_dprintf(fd, msg);
		ft_printf("Printed '{cyan}%s{eoc}' on fd %d\n", msg, fd);
		return (0);
	}
}
