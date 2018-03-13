/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:53:45 by upopee            #+#    #+#             */
/*   Updated: 2018/03/13 17:24:44 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "ft_printf.h"
#include "memory.h"
#include "strings.h"
#include "read_write.h"
#include "log.h"

static int		check_params(int argc)
{
	if (argc == 1)
		ft_putstr_fd(SERV_NOPARAM, 2);
	else if (argc > 2)
		ft_dprintf(2, SERV_BADPARAM, argc - 1);
	return (argc == 2 ? 0 : -1);
}

static void		main_loop(int fd)
{
	char	*buff;

	buff = NULL;
	while (1)
	{
		ft_putstr(CLIENT_PROMPT);
		if (!get_next_line(STDIN_FILENO, &buff)
			|| ft_strequ("exit", buff))
			break ;
		ft_putstr_fd(buff, fd);
		ft_strdel(&buff);
	}
}

int				main(int argc, char **argv)
{
	int		in_fd;
	char	*fifo;
	int		o_flags;

	if (check_params(argc) == -1)
		return (-1);
	fifo = argv[1];
	o_flags = O_WRONLY;
	if (access(fifo, F_OK) < 0)
		mkfifo(fifo, 0777);
	if ((in_fd = open(fifo, o_flags)) == -1)
	{
		ft_dprintf(2, LOG_ERR_OPEN, fifo);
		return (-1);
	}
	ft_printf(CLIENT_CONNECTED, fifo, in_fd);
	main_loop(in_fd);
	close(in_fd);
	return (0);
}
