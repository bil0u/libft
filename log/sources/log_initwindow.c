/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_initwindow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:08:53 by upopee            #+#    #+#             */
/*   Updated: 2018/03/09 04:30:07 by upopee           ###   ########.fr       */
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

	ft_strcpy(win->fifo, SERV_FILE_TEMPLATE);
	overwrite = ft_strchr(win->fifo, 'X');
	ft_sprintf(overwrite, "%3.3hhu", env->nb_inst + 1);
}

static int		open_fifotmp(t_logenv *env, t_logwin *win, int flags)
{
	win->flags = flags;
	if (access(win->fifo, F_OK) < 0)
		mkfifo(win->fifo, 0777);
	if ((win->fd = open(win->fifo, O_WRONLY)) == -1)
	{
		ft_dprintf(2, LOG_ERR_OPEN, win->fifo);
		return (-1);
	}
	++env->nb_inst;
	return (win->fd);
}

static void		get_serv_ap(char *buff)
{
	char		*overwrite;

	getcwd(buff, MAXPATHLEN);
	if ((overwrite = ft_strstr(buff, "/libft")) == NULL
	&& (overwrite = ft_strstr(buff, "/Libft")) == NULL
	&& (overwrite = ft_strchr(buff, '\0')) != NULL)
		overwrite[0] = '/';
	++overwrite;
	ft_strcpy(overwrite, SCRIPT_RPATH);
}

static char		**gen_execve_args(char *fifo, int flags)
{
	char		to_split[MAXPATHLEN];
	char		serv_path[MAXPATHLEN];
	char		*overwrite;
	int			i;

	ft_bzero(to_split, LOG_ARGS_MAXSIZE);
	ft_bzero(serv_path, LOG_ARGS_MAXSIZE);
	get_serv_ap(serv_path);
	ft_sprintf(to_split, "/bin/bash %s -f %s", serv_path, fifo);
	overwrite = ft_strchr(to_split, '\0');
	if (flags)
	{
		ft_strcpy(overwrite, " -o -");
		i = 5;
		flags & LOG_F_VERBOSE ? overwrite[i++] = 'v' : (void)i;
		flags & LOG_F_NONEWLINE ? overwrite[i++] = 'n' : (void)i;
		flags & LOG_F_SAVE ? overwrite[i++] = 's' : (void)i;
	}
	return (ft_strsplit(to_split, ' '));
}

int				init_logwindow(int flags)
{
	extern char	**environ;
	t_execve	child;
	t_logenv	*env;
	t_logwin	new_logwin;

	ft_bzero(&new_logwin, sizeof(new_logwin));
	env = get_logservice_env();
	gen_fifotmp(env, &new_logwin);
	if ((child.fork_pid = fork()) == 0)
	{
		child.args = gen_execve_args(new_logwin.fifo, flags);
		execve((char *)child.args[0], (char **)child.args, environ);
		ft_tabstrdel(&(child.args));
		exit (0);
	}
	new_logwin.pid = child.fork_pid;
	if (open_fifotmp(env, &new_logwin, flags) == -1)
		return (-1);
	ft_lstadd(&(env->log_windows), ft_lstnew(&new_logwin, sizeof(new_logwin)));
	if (flags & LOG_F_VERBOSE)
		ft_printf(CLIENT_CONNECTED, new_logwin.fifo);
	return (new_logwin.fd);
}
