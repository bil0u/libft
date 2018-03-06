/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:12:11 by upopee            #+#    #+#             */
/*   Updated: 2018/03/06 18:56:13 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <inttypes.h>
# include "../../linked_lists/includes/linked_lists.h"

# define ERR_NAME "{red}Error:{eoc} no name provided\n"

# define ERR_MKFIFO "{red}Error:{eoc} mkfifo: Couldnt open '%s'\n"

# define OPEN_MSG "{cyan}'%s'{eoc} opened (fd {yellow}%d{eoc})\n"
# define ERR_OPEN "{red}Error:{eoc} Couldnt open '%s' window\n"

# define CLOSE_MSG "{cyan}'%s'{eoc} closed (fd {yellow}%d{eoc})\n"
# define ERR_CLOSE "{red}Error:{eoc} Couldnt close '%s' window (fd {yellow}%d{eoc})\n"

# define ERR_BADFD "{red}Error:{eoc} {yellow}%d{eoc} -> bad fd\n"
# define ERR_NOTFOUND "{red}Error:{eoc} fd {yellow}%d{eoc} not found\n"

# define NOPARAM_ERR "{red}Error:{eoc} no parameter given\n"
# define MOREPARAM_ERR "{red}Error:{eoc} {yellow}%d{eoc} parameters given, only 1 needed\n"



# define SERV_WELCOME1 "{yellow}[Welcome to the debug server]{eoc}\n"
# define SERV_WELCOME2 "--> Channel: {cyan}%s{eoc} (fd {yellow}%d{eoc})\n"
# define SERV_OPEN_ERR "{red}Error:{eoc} Impossible to open '%s'\n"
# define SERV_READ_ERR "{red}Error:{eoc} impossible to read from fd {yellow}%d{eoc}\n"
# define SERV_GOODBYE1 "{yellow}[Session closed by the client]{eoc}\n"

# define CLIENT_PROMPT "{yellow}Input >{eoc} "
# define CLIENT_OPEN_ERR "{red}Error:{eoc} Impossible to open '%s'\n"
# define CLIENT_OPEN_SUCCESS "{green}[Connection etablished on {cyan}%s{green} on fd {yellow}%d{green}]{eoc}\n"

# define SERV_PROMPT "{yellow} >{eoc} "
# define SERV_INPUT "%s\n"

# define DEBUG_INPUT_MAX_SIZE 8192

# define NONE (0)
# define VERBOSE (1)
# define KILL_PROGRAM (1 << 1)

typedef struct	s_win
{
	int			fd;
	char		*fifo;
}				t_win;

typedef struct	s_winenv
{
	size_t		nb_windows;
	t_list		*windows;
}				t_winenv;

t_winenv	*get_winenv(void);

int			open_window(char *fifo);
int			close_window(int fd);
void		close_allwindows(void);

int			print_to_window(int fd, char *msg);

#endif
