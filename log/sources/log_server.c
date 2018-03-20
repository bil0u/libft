/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_server.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:53:45 by upopee            #+#    #+#             */
/*   Updated: 2018/03/20 15:53:16 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "ft_printf.h"
#include "memory.h"
#include "strings.h"
#include "read_write.h"
#include "log.h"
#include "log_globals.h"

static int		fetch_tokens(int argc, char **argv, char **fifo, int *s_flags)
{
	int			i;

	*fifo = argv[1];
	while (--argc > 1)
	{
		i = (argv[argc][0] == '-') ? 0 : -1;
		while (argv[argc][++i])
		{
			if (argv[argc][i] == 'v')
				*s_flags |= WF_VERBOSE;
			else if (argv[argc][i] == 's')
				*s_flags |= WF_SAVE;
			else if (argv[argc][i] == 'c')
				*s_flags |= WF_CLOSE;
			else if (argv[argc][i] == 'l')
				*s_flags |= WF_KEEP;
			else
				return (-1);
		}
	}
	return (0);
}

static int		check_args(int argc, char **argv, char **fifo, int *s_flags)
{
	*s_flags = 0;
	if (argc == 1 || ft_strequ(argv[1], ""))
	{
		ft_dprintf(STDERR_FILENO, SERV_NOPARAM);
		return (-1);
	}
	if (fetch_tokens(argc, argv, fifo, s_flags) == -1)
	{
		ft_dprintf(STDERR_FILENO, SERV_BADPARAM, argc - 1);
		return (-1);
	}
	return (0);
}

void			sigint_handler(int sig)
{
	g_break = 1;
	signal(sig, SIG_DFL);
}

static void		main_loop(int s_flags, int in_fd, int out_fd)
{
	char		buff[LOG_BUFF_SIZE + 1];
	int			bytes_read;

	g_break = 0;
	signal(SIGINT, &sigint_handler);
	while ((bytes_read = read(in_fd, buff, LOG_BUFF_SIZE)) != 0
		|| (s_flags & WF_KEEP))
	{
		if (g_break)
			break ;
		else if (bytes_read > 0)
		{
			write(STDOUT_FILENO, buff, bytes_read);
			if (out_fd != -1)
				write(out_fd, buff, bytes_read);
		}
		else
			sleep(1);
	}
	if (out_fd != -1)
		close(out_fd);
	write(STDOUT_FILENO, "\n", 1);
}

int				main(int argc, char **argv)
{
	int			in_fd;
	int			out_fd;
	char		*fifo;
	int			s_flags;

	ft_putstr(CLEAR_SCR);
	if (check_args(argc, argv, &fifo, &s_flags) == -1)
		return (-1);
	if (s_flags & WF_VERBOSE)
		ft_printf(SERV_INIT);
	if ((in_fd = open(fifo, O_RDONLY)) == -1)
	{
		ft_dprintf(STDERR_FILENO, LOG_ERR_OPEN, argv[1]);
		close_fdfifo(in_fd, fifo, s_flags);
		return (-1);
	}
	if (s_flags & WF_VERBOSE)
		ft_printf(SERV_WELCOME, fifo);
	out_fd = (s_flags & WF_SAVE) ? create_logfile(fifo, argv[0]) : -1;
	main_loop(s_flags, in_fd, out_fd);
	if (s_flags & WF_VERBOSE)
		ft_printf(SERV_GOODBYE, fifo);
	close_fdfifo(in_fd, fifo, s_flags);
	return (0);
}
