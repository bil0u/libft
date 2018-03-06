/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:53:45 by upopee            #+#    #+#             */
/*   Updated: 2018/03/06 18:32:55 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"

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
	char	*buff;

	buff = NULL;
	while (1)
	{
		ft_printf(CLIENT_PROMPT);
		if (get_next_line(STDIN_FILENO, &buff) == 0
			|| ft_strcmp("exit", buff) == 0)
		{
			ft_dprintf(input_fd, "exit");
			break ;
		}
		ft_dprintf(input_fd, buff);
		ft_strdel(&buff);
	}
}

int		main(int argc, char *argv[])
{
	int		input_fd;
	char	*fifo;

	if (check_params(argc) == -1)
		return (-1);
	fifo = argv[1];
    if ((input_fd = open(fifo, O_WRONLY|O_CREAT|O_NONBLOCK)) == -1)
	{
        ft_dprintf(2, CLIENT_OPEN_ERR, argv[1]);
        return (-1);
    }
	ft_printf(CLIENT_OPEN_SUCCESS, argv[1], input_fd);
	main_loop(input_fd);
	close(input_fd);
    return (0);
}
