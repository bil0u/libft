/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:40:45 by upopee            #+#    #+#             */
/*   Updated: 2018/03/07 09:52:43 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "strings.h"
#include "memory.h"
#include "ft_printf.h"
#include "log.h"

static void	generate_forkargs(int flags, t_logwin *win)
{
	int		i;

	ft_bzero(win, sizeof(*win));
	win->fifo = ft_strdup(SERV_FILE_TEMPLATE);
	win->fd = mkstemp(win->fifo);
	win->flags = flags;
//	ft_strcpy(win->process.term_name, "open");
//	ft_strcpy(win->process.term_arg1, "-b");
//	ft_strcpy(win->process.term_arg2, "com.googlecode.iterm2");
	ft_strcpy(win->process.serv_name, "./log_server");
	i = 0;
	if (flags && ++i)
	{
		win->process.serv_args[0] = '-';
		flags & LOG_VERBOSE ? win->process.serv_args[i] = 'v' : (void)i;
		flags & LOG_VERBOSE ? ++i : (void)i;
	}
//	win->process.exec_args[0] = win->process.term_name;
//	win->process.exec_args[1] = win->process.term_arg1;
//	win->process.exec_args[2] = win->process.term_arg2;
	win->process.exec_args[0] = win->process.serv_name;
	win->process.exec_args[1] = win->fifo;
	win->process.exec_args[2] = win->process.serv_args;
}

int			logwindow_new(int flags)
{
	pid_t		child_pid;
	t_logenv	*env;
	t_logwin	new_logwin;

	generate_forkargs(flags, &new_logwin);
	if ((child_pid = fork()) == 0)
	{
		ft_printf("> CHILD <\nExecuting the execve command: '%s %s %s %s %s'\n", new_logwin.process.exec_args[0], new_logwin.process.exec_args[1], new_logwin.process.exec_args[2], new_logwin.process.exec_args[3], new_logwin.process.exec_args[4]);
		//execve("/Applications/iTerm.app", new_logwin.process.exec_args, NULL);
		ft_printf("> CHILD EXITING <\n");
		exit (0);
	}
	new_logwin.process.pid = child_pid;
	env = get_logservice_env();
	ft_lstadd(&(env->log_windows), ft_lstnew(&new_logwin, sizeof(new_logwin)));
	if (flags & LOG_VERBOSE)
		ft_printf(CLIENT_RUN, new_logwin.fifo, new_logwin.fd);
	return (new_logwin.fd);
}

int			close_window(int fd)
{
	t_logenv	*env;

	if (fd == -1)
	{
		ft_dprintf(2, LOG_ERR_BADFD, fd);
		return (-1);
	}
	env = get_logservice_env();
	if (ft_lstdelif(&env->log_windows, &fd, &item_fd_cmp, &terminate_session))
	{
		ft_dprintf(2, LOG_ERR_NOFD, fd);
		return (-1);
	}
	return (0);
}

void		close_allwindows(void)
{
	t_logenv	*env;

	env = get_logservice_env();
	ft_lstdel(&env->log_windows, &terminate_session);
}

int			print_to_window(int fd, char *msg)
{
	t_logenv	*env;

	env = get_logservice_env();
	if (ft_lstfind(env->log_windows, &fd, &item_fd_cmp) == NULL)
	{
		ft_dprintf(2, LOG_ERR_NOFD, fd);
		return (-1);
	}
	else
	{
		ft_dprintf(fd, msg);
		return (0);
	}
}
