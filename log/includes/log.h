/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:12:11 by upopee            #+#    #+#             */
/*   Updated: 2018/03/09 07:48:30 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include <unistd.h>
# include <fcntl.h>
# include <inttypes.h>
# include <sys/param.h>
# include "linked_lists.h"

# define LOG_BUFF_SIZE 4096
# define SCRIPT_RPATH "libft/log/scripts/launch_server.sh"
# define LOG_FILE_TEMPLATE "/tmp/libft.log.XXX"

typedef struct	s_execve
{
	pid_t		fork_pid;
	char		**args;
}				t_execve;

# define LOG_F_NONE (0)
# define LOG_F_NONEWLINE (1)
# define LOG_F_VERBOSE (1 << 1)
# define LOG_F_SAVE (1 << 2)

typedef struct	s_logwin
{
	pid_t		pid;
	int			fd;
	int			flags;
	char		fifo[MAXPATHLEN];
}				t_logwin;

typedef struct	s_logenv
{
	uint8_t		nb_inst;
	t_list		*log_windows;
}				t_logenv;

/*
** -- CLIENT FUNCTIONS --
*/

int				init_logwindow(int flags);
int				ft_logthis(int fd, int flags, char *msg);
int				close_window(int fd);
void			close_allwindows(void);

/*
** -- TOOLS --
*/

t_logenv		*get_logservice_env(void);
t_logwin		*find_logwin(void *data_ref, int (*cmp)());
int				item_fd_cmp(t_logwin *item, void *fd_ref);
int				close_pipe(int fd, char *fifo, int s_flags);
void			terminate_session(void *win_data, size_t size);

/*
** -- GLOBAL STYLE --
*/

# define LOG_F_ERR (1)
# define LOG_F_WARN (2)
# define LOG_F_INFO (3)

# define LOG_ERR "{red}[ ERROR ]{eoc} "
# define LOG_WARN "{yellow}[ WARNING ]{eoc} "
# define LOG_INFO "{cyan}[ INFO ]{eoc} "

/*
** -- SERVER STYLE --
*/

# define SERV_PROMPT "{yellow} >{eoc} "

# define SERV_INIT1 "{blue}Connection started by client\n"
# define SERV_INIT2 "Server initialisation...\n{eoc}"
# define SERV_INIT SERV_INIT1 SERV_INIT2

# define SERV_WELCOME1 "{yellow}[ Awesome logging tool v0.1 by"
# define SERV_WELCOME2 " {cyan}upopee{yellow} ]{eoc}\n{green}"
# define SERV_WELCOME3 "[ Listening on --> '{cyan}%s{green}' ]{eoc}\n"
# define SERV_WELCOME SERV_WELCOME1 SERV_WELCOME2 SERV_WELCOME3

# define SERV_GDBYE1 "\n{red}[ Closing connection with '{cyan}%s{red}' ]"
# define SERV_GDBYE2 "{eoc}\n{magenta}[ {blue}#   {cyan}G {green}O "
# define SERV_GDBYE3 "{yellow}O {red}D   {magenta}B {blue}Y {cyan}E   "
# define SERV_GDBYE4 "{green}# {yellow} ]{eoc}\n"
# define SERV_GOODBYE SERV_GDBYE1 SERV_GDBYE2 SERV_GDBYE3 SERV_GDBYE4

# define SERV_NOPARAM LOG_ERR "no parameter given\n"
# define SERV_BADPARAM LOG_ERR "{yellow}%d{eoc} parameters given\n"
# define SERV_OPENERR LOG_ERR "Impossible to open '%s'\n"
# define SERV_READERR LOG_ERR "Impossible to read fd {yellow}%d{eoc}\n"

/*
** -- CLIENT STYLE --
*/

# define CLIENT_PROMPT "{magenta}Your message here >{eoc} "

# define CLIENT_CONNECTED1 "{green}[ Log window created, listening on"
# define CLIENT_CONNECTED2 " '{cyan}%s{green}' ]{eoc}\n"
# define CLIENT_CONNECTED CLIENT_CONNECTED1 CLIENT_CONNECTED2

# define CLIENT_CLOSING "{red}[ Connexion with '{cyan}%s{red}' closed ]{eoc}\n"

/*
** -- SYSTEM ACTIONS INFOS --
*/

# define LOG_ERR_NONAME LOG_ERR "no name provided\n"
# define LOG_ERR_MKFIFO LOG_ERR "Couldnt create fifo '%s'\n"
# define LOG_ERR_OPEN LOG_ERR "Couldnt open fifo '%s'\n"

# define LOG_MSG_OPEN "{cyan}'%s'{eoc} opened (fd {yellow}%d{eoc})\n"

# define LOG_MSG_CLOSE "{cyan}'%s'{eoc} closed (fd {yellow}%d{eoc})\n"
# define LOG_ERR_CLOSE LOG_ERR "Couldnt close '%s' (fd {yellow}%d{eoc})\n"

# define LOG_ERR_BADFD LOG_ERR "{yellow}%d{eoc} -> bad fd\n"
# define LOG_ERR_NOFD LOG_ERR "fd {yellow}%d{eoc} not found\n"

#endif
