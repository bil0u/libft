/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:53:45 by upopee            #+#    #+#             */
/*   Updated: 2018/03/07 17:41:46 by upopee           ###   ########.fr       */
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
*/

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

/*
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
	int			fd = init_logwindow(LOG_F_VERBOSE);
//	t_logwin	*win = find_logwin(&fd, &item_fd_cmp);

	ft_printf("{red}> STARTING LOOP <{eoc}\n");
	main_loop(fd);
	close_allwindows();
	ft_printf("{red}> TERMINATING FATHER -- END OF PROGRAM <{eoc}\n");
	return (0);
}
