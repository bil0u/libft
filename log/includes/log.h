/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:12:11 by upopee            #+#    #+#             */
/*   Updated: 2018/03/13 19:30:45 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include <unistd.h>
# include <fcntl.h>
# include <inttypes.h>
# include <sys/param.h>
# include "../../linked_lists/includes/linked_lists.h"

# define SCRIPT_RPATH		"libft/log/scripts/launch_server.sh"
# define LOG_FILE_TEMPLATE	"/tmp/libft.log.XXX"

# define LOG_BUFF_SIZE	4096
# define LOG_F_VERBOSE	(1 << 0)
# define LOG_F_SAVE		(1 << 1)
# define LOG_F_CLOSE	(1 << 2)

# define NB_MAXWIN		5
# define NAME_MAXLEN	32

typedef struct	s_logwin
{
	int			fd;
	char		name[NAME_MAXLEN + 1];
}				t_logwin;

typedef struct	s_logenv
{
	uint8_t		nb_inst;
	t_logwin	windows[NB_MAXWIN];
}				t_logenv;

/*
** -- FUNCTIONS --
*/

int				new_logwindow(char *name, int flags);
int				ft_logthis(int fd, int flags, char *msg);

t_logenv		*get_logenv(void);
t_logwin		*get_logwin(char *to_find);
int				create_logfile(char *fifo, char *path);

/*
** -- GLOBAL STYLE --
*/

# define LOG_F_ERR	(1)
# define LOG_F_WARN	(2)
# define LOG_F_INFO	(3)

# define LOG_ERR		"{red}[ ERROR ]{eoc} "
# define LOG_WARN		"{yellow}[ WARNING ]{eoc} "
# define LOG_INFO		"{cyan}[ INFO ]{eoc} "

/*
** -- SERVER STYLE --
*/

# define SERV_INIT1		"{blue}Connection started by client\n"
# define SERV_INIT2		"Server initialisation...\n{eoc}"
# define SERV_INIT		SERV_INIT1 SERV_INIT2

# define SERV_WELCOME1	"{yellow}[ Awesome logging tool v0.1 by"
# define SERV_WELCOME2	" {cyan}upopee{yellow} ]{eoc}\n{green}"
# define SERV_WELCOME3	"[ Listening on --> '{cyan}%s{green}' ]{eoc}\n"
# define SERV_WELCOME	SERV_WELCOME1 SERV_WELCOME2 SERV_WELCOME3

# define SERV_GDBYE1	"\n{red}[ Closing connection with '{cyan}%s{red}' ]"
# define SERV_GDBYE2	"{eoc}\n{magenta}[ {blue}#   {cyan}G {green}O "
# define SERV_GDBYE3	"{yellow}O {red}D   {magenta}B {blue}Y {cyan}E   "
# define SERV_GDBYE4	"{green}# {yellow} ]{eoc}\n"
# define SERV_GOODBYE	SERV_GDBYE1 SERV_GDBYE2 SERV_GDBYE3 SERV_GDBYE4

# define SERV_NOPARAM	LOG_ERR "no parameter given\n"
# define SERV_BADPARAM	LOG_ERR "{yellow}%d{eoc} parameters given\n"

/*
** -- CLIENT STYLE --
*/

# define CLIENT_PROMPT		"{magenta}Your message here >{eoc} "

# define CLIENT_CONNECTED1	"{green}[ Log window created, listening on"
# define CLIENT_CONNECTED2	" '{cyan}%s{green}' ]{eoc}\n"
# define CLIENT_CONNECTED	CLIENT_CONNECTED1 CLIENT_CONNECTED2

/*
** -- TOOLS STYLE --
*/

# define LOG_ERR_OPEN		LOG_ERR "Couldnt open fifo '%s'\n"
# define LOG_ERR_WINEXIST	LOG_ERR "Window '%s' already exists\n"
# define LOG_ERR_WINCRASH	LOG_ERR "Could not create window '%s'\n"

#endif
