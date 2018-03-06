/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:53:45 by upopee            #+#    #+#             */
/*   Updated: 2018/03/06 18:45:25 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include "libft.h"

static void		close_session(int fd, char *fifo)
{
	if (fd != -1)
		close(fd);
	unlink(fifo);
	remove(fifo);
}

static int		check_params(int argc)
{
	argc == 1 ? ft_dprintf(2, NOPARAM_ERR) : (void)argc;
	argc > 2 ? ft_dprintf(2, MOREPARAM_ERR, argc - 1) : (void)argc;
	if (argc != 2)
		return (-1);
	return (0);
}

static void		main_loop(int input_fd)
{
	char	buff[DEBUG_INPUT_MAX_SIZE];

	while (1)
	{
		ft_bzero(buff, DEBUG_INPUT_MAX_SIZE);
		read(input_fd, buff, DEBUG_INPUT_MAX_SIZE);
		if (ft_strcmp("exit", buff) == 0)
		{
			ft_printf(SERV_GOODBYE1);
			break ;
		}
		else if (ft_strcmp("", buff) != 0)
			ft_printf(SERV_INPUT, buff);
	}
}

int		main(int argc, char *argv[])
{
	int		input_fd;
	char	*fifo;

	if (check_params(argc) == -1)
		return (-1);
	fifo = argv[1];
    if (mkfifo(fifo, 0666) == -1
		|| (input_fd = open(fifo, O_RDONLY|O_NONBLOCK)) == -1)
	{
        ft_dprintf(2, SERV_OPEN_ERR, argv[1]);
		close_session(input_fd, fifo);
        return (-1);
    }
	ft_printf(SERV_WELCOME1);
    ft_printf(SERV_WELCOME2, argv[1], input_fd);
	main_loop(input_fd);
	close_session(input_fd, fifo);
    return (0);
}
