/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_initwindow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:08:53 by upopee            #+#    #+#             */
/*   Updated: 2018/03/07 19:17:36 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/param.h>
#include "strings.h"
#include "memory.h"
#include "ft_printf.h"
#include "log.h"

static void		gen_fifotmp(t_logenv *env, t_logwin *win)
{
	char		*overwrite;

	ft_printf("{magenta}> START gen_fifo_temp <{eoc}\n");
	ft_strcpy(win->fifo, SERV_FILE_TEMPLATE);
	overwrite = ft_strchr(win->fifo, 'X');
	ft_sprintf(overwrite, "%3.3hhu", env->nb_inst + 1);
	ft_printf("{magenta}> END gen_fifo_temp <{eoc}\n");
}

static int		open_fifotmp(t_logenv *env, t_logwin *win, int flags)
{
	ft_printf("{magenta}> START open_tempfile <{eoc}\n");
	win->flags = flags;
	if (access(win->fifo, F_OK) < 0)
		mkfifo(win->fifo, 0777);
	if ((win->fd = open(win->fifo, O_WRONLY)) == -1)
	{
		ft_dprintf(2, LOG_ERR_OPEN, win->fifo);
		return (-1);
	}
	++env->nb_inst;
	ft_printf("{magenta}> END open_tempfile <{eoc}\n");
	return (win->fd);
}

static void		get_serv_ap(char *buff)
{
	char		tmp[LOG_ARGS_MAXSIZE];
	char		*overwrite;

	ft_printf("{magenta}> START get_serv_ap <{eoc}\n");
	ft_bzero(tmp, sizeof(tmp));
	getcwd(tmp, LOG_ARGS_MAXSIZE);
	ft_printf("{magenta}> YO <{eoc}\t%s\n", tmp);
	//ft_strdel(&tmp);
//	ft_printf("{magenta}> YO <{eoc}\n");
	if ((overwrite = ft_strstr(tmp, "/libft")) == NULL
	&& (overwrite = ft_strstr(tmp, "/Libft")) == NULL
	&& (overwrite = ft_strchr(tmp, '\0')) != NULL)
		overwrite[0] = '/';
	++overwrite;
	ft_printf("{magenta}> YO <{eoc}\t%s\n", overwrite);
	ft_printf("{magenta}> YO <{eoc}\t%s\n", tmp);
	ft_strcpy(overwrite, SCRIPT_RPATH);
	ft_printf("{magenta}> YO <{eoc}\t%s\n", overwrite);
	ft_printf("{magenta}> YO <{eoc}\t%p %p\n", buff, tmp);
	ft_strcpy(buff, tmp);
	ft_printf("{magenta}> YO <{eoc}\t%s\n", buff);
	ft_printf("{magenta}> END get_serv_ap <{eoc}\n");
}

static void		gen_execve_args(int flags, char *fifo, t_execve *process)
{
	int			i;

	ft_printf("{magenta}> START gen_execve_args <{eoc}\n");
	ft_bzero(process->args, sizeof(char **));
	get_serv_ap(process->args[0]);
	ft_strcpy(process->args[1], "-f");
	ft_strcpy(process->args[2], fifo);
	i = 0;
	if (flags)
	{
		ft_strcpy(process->args[3], "-o");
		process->args[4][i++] = '-';
		flags & LOG_F_VERBOSE ? process->args[4][i++] = 'v' : (void)i;
		flags & LOG_F_NONEWLINE ? process->args[4][i++] = 'n' : (void)i;
	}
	ft_printf("{magenta}> END gen_execve_args <{eoc}\n");
}

int				init_logwindow(int flags)
{
	t_execve	child;
	t_logenv	*env;
	t_logwin	new_logwin;

	ft_bzero(&new_logwin, sizeof(new_logwin));
	env = get_logservice_env();
	gen_fifotmp(env, &new_logwin);
	child.fork_pid = fork();
	if (child.fork_pid == 0)
	{
		ft_printf("{magenta}> CHILD <{eoc}\n");

		gen_execve_args(flags, new_logwin.fifo, &child);

		ft_printf("execve ({yellow}%s %s %s %s %s{eoc})\n",
			child.args[0], child.args[1], child.args[2], child.args[3], child.args[4]);

		execve((char *)child.args[0], (char **)child.args, NULL);

		ft_printf("{magenta}> CHILD EXITING <{eoc}\n");
		exit (0);
	}
	ft_printf("{red}> FATHER <{eoc}\n");
	new_logwin.pid = child.fork_pid;
	if (open_fifotmp(env, &new_logwin, flags) == -1)
		return (-1);
	ft_lstadd(&(env->log_windows), ft_lstnew(&new_logwin, sizeof(new_logwin)));
	if (flags & LOG_F_VERBOSE)
		ft_printf(CLIENT_CONNECTING, new_logwin.fifo, new_logwin.fd);
	return (new_logwin.fd);
}
