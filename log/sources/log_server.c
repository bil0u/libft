/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_server.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:53:45 by upopee            #+#    #+#             */
/*   Updated: 2018/03/15 15:59:30 by upopee           ###   ########.fr       */
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

static void		main_loop(int in_fd, int out_fd)
{
	char		buff[LOG_BUFF_SIZE + 1];
	int			bytes_read;

	while ((bytes_read = read(in_fd, buff, LOG_BUFF_SIZE)) != 0)
	{
		buff[bytes_read] = '\0';
		write(STDIN_FILENO, buff, bytes_read);
		if (out_fd != -1)
			write(out_fd, buff, bytes_read);
	}
	if (out_fd != -1)
		close(out_fd);
	write(STDIN_FILENO, "\n", 1);
}

static int		create_logfile(char *fifo, char *path)
{
	char		file[MAXPATHLEN];
	char		*overwrite;
	char		*needed;
	int			out_fd;

	ft_strcpy(file, path);
	overwrite = ft_strrchr(file, '/') + 1;
	ft_strcpy(overwrite, LOG_DIR);
	overwrite += ft_strlen(LOG_DIR);
	mkdir(file, 0777);
	needed = ft_strrchr(fifo, '/') + 1;
	ft_strcpy(overwrite, needed);
	out_fd = open(file, O_WRONLY | O_CREAT | O_APPEND);
	fchmod(out_fd, 0777);
	return (out_fd);
}

int				main(int argc, char **argv)
{
	int			in_fd;
	int			out_fd;
	char		*fifo;
	int			s_flags;

	if (check_args(argc, argv, &fifo, &s_flags) == -1)
		return (-1);
	if (s_flags & WF_VERBOSE)
		ft_printf(SERV_INIT);
	if (access(fifo, F_OK) < 0)
		mkfifo(fifo, 0777);
	if ((in_fd = open(fifo, O_RDONLY | O_NONBLOCK)) == -1)
	{
		ft_dprintf(STDERR_FILENO, LOG_ERR_OPEN, argv[1]);
		close_fdfifo(in_fd, fifo, s_flags);
		return (-1);
	}
	if (s_flags & WF_VERBOSE)
		ft_printf(SERV_WELCOME, fifo);
	out_fd = (s_flags & WF_SAVE) ? create_logfile(fifo, argv[0]) : -1;
	main_loop(in_fd, out_fd);
	if (s_flags & WF_VERBOSE)
		ft_printf(SERV_GOODBYE, fifo);
	close_fdfifo(in_fd, fifo, s_flags);
	return (0);
}
