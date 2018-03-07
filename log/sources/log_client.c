/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:53:45 by upopee            #+#    #+#             */
/*   Updated: 2018/03/07 10:38:45 by upopee           ###   ########.fr       */
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

/*
static int		check_params(int argc)
{
	argc == 1 ? ft_dprintf(2, SERV_NOPARAM) : (void)argc;
	argc > 2 ? ft_dprintf(2, SERV_BADPARAM, argc - 1) : (void)argc;
	if (argc != 2)
		return (-1);
	return (0);
}

static void		main_loop(int in_fd)
{
	char	*buff;

	buff = NULL;
	while (1)
	{
		ft_printf(CLIENT_PROMPT);
		if (get_next_line(STDIN_FILENO, &buff) == 0
			|| ft_strcmp("exit", buff) == 0)
		{
			ft_dprintf(in_fd, "exit");
			break ;
		}
		ft_dprintf(in_fd, buff);
		ft_strdel(&buff);
	}
}

int		main(int argc, char **argv)
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
	ft_printf(CLIENT_RUN, fifo, in_fd);
	main_loop(in_fd);
	close(in_fd);
	return (0);
}
*/

int		main(void)
{
	char	*argv[] = {"./log/scripts/open_in_tab.sh", "-e", "../../log_server", "-f", "/tmp/test.log", "-o", "v"};

	//logwindow_new(LOG_VERBOSE);
	ft_printf("{magenta}> CHILD <{eoc}\nExecuting the execve command: {cyan}%s %s %s %s{eoc}\n", argv[0], argv[1], argv[2], argv[3]);
	execve("/bin/bash", argv, NULL);
//	while (1)
//		continue ;
//	close_allwindows();
	return (0);
}
