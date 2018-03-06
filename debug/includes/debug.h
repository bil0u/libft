/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:12:11 by upopee            #+#    #+#             */
/*   Updated: 2018/03/05 23:00:17 by upopee           ###   ########.fr       */
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

# define ERR_NO_NAME "{red}Error:{eoc} name must be\n"
# define ERR_NAME "{red}Error:{eoc} name too long (%u bytes max)\n"

# define ERR_MKFIFO "{red}Error:{eoc} mkfifo: Couldnt open '%s'\n"

# define OPEN_MSG "{cyan}'%s'{eoc} opened (fd {yellow}%d{eoc})\n"
# define ERR_OPEN "{red}Error:{eoc} Couldnt open '%s' window\n"

# define CLOSE_MSG "{cyan}'%s'{eoc} closed (fd {yellow}%d{eoc})\n"
# define ERR_CLOSE "{red}Error:{eoc} Couldnt close '%s' window \
					(fd {yellow}%d{eoc})\n"

# define ERR_BADFD "{red}Error:{eoc} {yellow}%d{eoc} -> bad fd\n"
# define ERR_NOTFOUND "{red}Error:{eoc} fd {yellow}%d{eoc} not found\n"

# define DEBUG_INPUT_MAX_SIZE 8192
# define WINDOW_NAME_MAX_SIZE 64

# define VERBOSE (1)

typedef struct	s_win
{
	char		name[WINDOW_NAME_MAX_SIZE];
	int			fd;
	uint8_t		flags;
}				t_win;

typedef struct	s_winenv
{
	size_t		nb_windows;
	t_list		*windows;
}				t_winenv;

t_winenv	*get_winenv(void);

int			open_window(char *name, uint8_t flags);
int			close_window(int fd);
void		close_allwindows(void);

int			print_to_window(int fd, char *msg);

#endif
