/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:12:11 by upopee            #+#    #+#             */
/*   Updated: 2018/03/09 05:04:57 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include <unistd.h>
# include <fcntl.h>
# include <inttypes.h>
# include <sys/param.h>
# include "../../linked_lists/includes/linked_lists.h"

# define LOG_BUFF_SIZE		4096
# define LOG_ARGS_MAXSIZE	256
# define LOG_EXEC_BSIZE		32

# define LOG_NB_FLAGS		2
# define LOG_F_NONE			(0)
# define LOG_F_NONEWLINE	(1)
# define LOG_F_VERBOSE		(1 << 1)
# define LOG_F_SAVE			(1 << 2)


typedef struct	s_execve
{
	pid_t		fork_pid;
	char		**args;
}				t_execve;


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
** -- CLIENT SIDE FUNCTIONS --
*/

int			init_logwindow(int flags);
int			ft_logthis(int fd, char *msg);
int			close_window(int fd);
void		close_allwindows(void);

/*
** -- TOOLS --
*/

t_logenv	*get_logservice_env(void);
t_logwin	*find_logwin(void *data_ref, int (*cmp)());
int			item_fd_cmp(t_logwin *item, void *fd_ref);
int			close_pipe(int fd, char *fifo, int s_flags);
void		terminate_session(void *win_data, size_t size);


/*
** -- SERVER STYLE --
*/

# define SCRIPT_RPATH		"libft/log/scripts/launch_server.sh"

# define SERV_FILE_TEMPLATE "/tmp/libft.log.XXX"
# define SERV_EXIT_STR		"exit"

# define SERV_PROMPT		"{yellow} >{eoc} "

# define SERV_INIT			"{blue}Connection started by client\nServer initialisation...\n{eoc}"
# define SERV_WELCOME		"{yellow}[ Awesome logging tool v0.1 by {cyan}upopee{yellow} ]{eoc}\n{green}[ Listening on --> '{cyan}%s{green}' ]{eoc}\n"
# define SERV_GOODBYE		"\n{red}[ Closing connection with '{cyan}%s{red}' ]{eoc}\n{magenta}[ {blue}#   {cyan}G {green}O {yellow}O {red}D   {magenta}B {blue}Y {cyan}E   {green}# {yellow} ]{eoc}\n"

# define SERV_NOPARAM		"{red}Error:{eoc} no parameter given\n"
# define SERV_BADPARAM		"{red}Error:{eoc} {yellow}%d{eoc} parameters given, only 1 needed\n"
# define SERV_OPENERR		"{red}Error:{eoc} Impossible to open '%s'\n"
# define SERV_READERR		"{red}Error:{eoc} impossible to read from fd {yellow}%d{eoc}\n"


/*
** -- CLIENT STYLE --
*/

# define CLIENT_PROMPT		"{magenta}Your message here >{eoc} "
# define CLIENT_CONNECTED	"{green}[ Log window created, listening on '{cyan}%s{green}' ]{eoc}\n"
# define CLIENT_CLOSING		"{red}[ Connexion with '{cyan}%s{red}' closed ]{eoc}\n"

/*
** -- SYSTEM ACTIONS INFOS --
*/

# define LOG_ERR_NONAME		"{red}Error:{eoc} no name provided\n"
# define LOG_ERR_MKFIFO		"{red}Error:{eoc} Couldnt create fifo '%s'\n"
# define LOG_ERR_OPEN		"{red}Error:{eoc} Couldnt open fifo '%s'\n"

# define LOG_MSG_OPEN		"{cyan}'%s'{eoc} opened (fd {yellow}%d{eoc})\n"

# define LOG_MSG_CLOSE		"{cyan}'%s'{eoc} closed (fd {yellow}%d{eoc})\n"
# define LOG_ERR_CLOSE		"{red}Error:{eoc} Couldnt close '%s' window (fd {yellow}%d{eoc})\n"

# define LOG_ERR_BADFD		"{red}Error:{eoc} {yellow}%d{eoc} -> bad fd\n"
# define LOG_ERR_NOFD		"{red}Error:{eoc} fd {yellow}%d{eoc} not found\n"

#endif
