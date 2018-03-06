/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:53:45 by upopee            #+#    #+#             */
/*   Updated: 2018/03/06 00:59:41 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int main_bis(int argc, char *argv[])
{
    char in[DEBUG_INPUT_MAX_SIZE];
	int in_fd;

    mkfifo(File_name, 0666);

    printf("Welcome to server.\n");
    printf("channel for sending messages to server is %s\n", INGOING);

    ;

    if ((in_fd = open(INGOING, O_RDONLY)) == -1)
	{
        perror("open error");
        return (-1);
    }

    while (read(in_fd, in, DEBUG_INPUT_MAX_SIZE)>0)
        printf("You sent %s to server.\n", in);

    return (0);
}
*/

int		main(int argc, char **argv)
{
	int		fd;

	if (argc == 2)
	{
		if ((fd = open_window(argv[1], VERBOSE)) >= 0)
		{
			print_to_window(fd, "Coucou\n");
			close_window(fd);
		}
	}
	return (0);
}
