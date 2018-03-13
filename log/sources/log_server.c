/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_server.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:53:45 by upopee            #+#    #+#             */
/*   Updated: 2018/03/13 14:18:56 by upopee           ###   ########.fr       */
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

static int		get_tokens(int argc, char **argv, char **fifo, int *s_flags)
{
	int		i;

	*fifo = argv[1];
	while (--argc > 1)
	{
		i = (argv[argc][0] == '-') ? 0 : -1;
		while (argv[argc][++i])
		{
			if (argv[argc][i] == 'v')
				*s_flags |= LOG_F_VERBOSE;
			else if (argv[argc][i] == 'n')
				*s_flags |= LOG_F_NONEWLINE;
			else if (argv[argc][i] == 's')
				*s_flags |= LOG_F_SAVE;
			else if (argv[argc][i] == 'c')
				*s_flags |= LOG_F_CLOSE;
			else
				return (-1);
		}
	}
	return (0);
}

static int		decode_params(int argc, char **argv, char **fifo, int *s_flags)
{
	*s_flags = LOG_F_NONE;
	if (argc == 1 || ft_strequ(argv[1], ""))
	{
		ft_dprintf(STDERR_FILENO, SERV_NOPARAM);
		return (-1);
	}
	if (get_tokens(argc, argv, fifo, s_flags) == -1)
	{
		ft_dprintf(STDERR_FILENO, SERV_BADPARAM, argc - 1);
		return (-1);
	}
	return (0);
}

static int		create_logfile(char *fifo, char *path)
{
	char	file[MAXPATHLEN];
	char	*overwrite;
	char	*needed;
	int		out_fd;

	ft_strcpy(file, path);
	overwrite = ft_strrchr(file, '/') + 1;
	ft_strcpy(overwrite, "log_files/");
	overwrite += 10;
	mkdir(file, 0777);
	needed = ft_strrchr(fifo, '/') + 1;
	ft_strcpy(overwrite, needed);
	out_fd = open(file, O_WRONLY | O_CREAT | O_APPEND);
	fchmod(out_fd, 0777);
	return (out_fd);
}

static void		main_loop(int in_fd, int out_fd, int s_flags)
{
	char	buff[LOG_BUFF_SIZE];

	while (42)
	{
		ft_bzero(buff, LOG_BUFF_SIZE);
		if (!read(in_fd, buff, LOG_BUFF_SIZE))
			break ;
		else if (ft_strcmp("", buff) != 0)
		{
			if (s_flags & LOG_F_NONEWLINE)
			{
				ft_putstr(buff);
				s_flags & LOG_F_SAVE ? ft_putstr_fd(buff, out_fd) : (void)buff;
			}
			else
			{
				ft_putendl(buff);
				s_flags & LOG_F_SAVE ? ft_putendl_fd(buff, out_fd) : (void)buff;
			}
		}
	}
	if (s_flags & LOG_F_SAVE)
		close(out_fd);
}

int				main(int argc, char **argv)
{
	int			in_fd;
	int			out_fd;
	char		*fifo;
	int			s_flags;

	ft_printf(SERV_INIT);
	if (decode_params(argc, argv, &fifo, &s_flags) == -1)
		return (-1);
	if (access(fifo, F_OK) < 0)
		mkfifo(fifo, 0777);
	if ((in_fd = open(fifo, O_RDONLY | O_NONBLOCK)) == -1)
	{
		ft_dprintf(2, LOG_ERR_OPEN, argv[1]);
		close_fifo(in_fd, fifo, s_flags);
		return (-1);
	}
	if (s_flags & LOG_F_VERBOSE)
		ft_printf(SERV_WELCOME, fifo);
	out_fd = (s_flags & LOG_F_SAVE) ? create_logfile(fifo, argv[0]) : -1;
	main_loop(in_fd, out_fd, s_flags);
	if (s_flags & LOG_F_VERBOSE)
		ft_printf(SERV_GOODBYE, fifo);
	close_fifo(in_fd, fifo, s_flags);
	return (0);
}
