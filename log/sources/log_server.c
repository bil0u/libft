/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_server.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:53:45 by upopee            #+#    #+#             */
/*   Updated: 2018/03/07 10:45:22 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#include "memory.h"
#include "strings.h"
#include "read_write.h"
#include "log.h"

static int		get_tokens(int argc, char **argv, char **fifo, int *s_flags)
{
	int		i;

	i = -1;
	while (++i < argc)
		ft_printf("argv[%d] = '{cyan}%s{eoc}'\n", i, argv[i]);
	*fifo = argv[1];
	while (--argc > 1)
	{
		i = (argv[argc][0] == '-') ? 0 : -1;
		while (argv[argc][++i])
		{
			if (argv[argc][i] == 'v')
				*s_flags |= LOG_VERBOSE;
			else if (argv[argc][i] == 'n')
				*s_flags &= ~(LOG_PRINT_NEWLINE);
			else
				return (-1);
		}
	}
	return (0);
}

static int		decode_params(int argc, char **argv, char **fifo, int *s_flags)
{
	if (argc == 1 || ft_strcmp(argv[1], "") == 0)
	{
		ft_dprintf(2, SERV_NOPARAM);
		return (-1);
	}
	if (get_tokens(argc, argv, fifo, s_flags) == -1)
	{
		ft_dprintf(2, SERV_BADPARAM, argc - 1);
		return (-1);
	}
	return (0);
}

static void		main_loop(int in_fd, int s_flags)
{
	char	buff[LOG_BUFF_SIZE];

	while (1)
	{
		ft_bzero(buff, LOG_BUFF_SIZE);
		read(in_fd, buff, LOG_BUFF_SIZE);
		if (ft_strcmp("exit", buff) == 0)
			break ;
		else if (ft_strcmp("", buff) != 0)
		{
			if (s_flags & LOG_PRINT_NEWLINE)
				ft_putendl(buff);
			else
				ft_putstr(buff);
		}
	}
}

int		main(int argc, char **argv)
{
	int			in_fd;
	char		*fifo;
	int		 	s_flags;
	int			o_flags;

	s_flags = LOG_NONE | LOG_PRINT_NEWLINE;
	fifo = NULL;
	if (decode_params(argc, argv, &fifo, &s_flags) == -1)
		return (-1);
	o_flags = O_RDONLY | O_NONBLOCK;
	if (access(fifo, F_OK) < 0)
		mkfifo(fifo, 0777);
	if ((in_fd = open(fifo, o_flags)) == -1)
	{
		ft_dprintf(2, LOG_ERR_OPEN, argv[1]);
		close_pipe(in_fd, fifo, s_flags);
		return (-1);
	}
	if (s_flags & LOG_VERBOSE)
	{
		ft_printf(SERV_WELCOME1);
		ft_printf(SERV_WELCOME2, fifo, in_fd);
	}
	main_loop(in_fd, s_flags);
	return (close_pipe(in_fd, fifo, s_flags));
}
