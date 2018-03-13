/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_initwindow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:08:53 by upopee            #+#    #+#             */
/*   Updated: 2018/03/13 14:23:55 by upopee           ###   ########.fr       */
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

static void		gen_fifotmp(t_logwin *win, int nb_inst)
{
	char		*overwrite;

	ft_strcpy(win->fifo, LOG_FILE_TEMPLATE);
	overwrite = ft_strchr(win->fifo, 'X');
	ft_sprintf(overwrite, "%3.3hhu", nb_inst);
}

static int		open_fifotmp(t_logwin *win, int flags)
{
	win->flags = flags;
	if (access(win->fifo, F_OK) < 0)
		mkfifo(win->fifo, 0777);
	if ((win->fd = open(win->fifo, O_WRONLY)) == -1)
	{
		ft_dprintf(2, LOG_ERR_OPEN, win->fifo);
		return (-1);
	}
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

	ft_bzero(to_split, MAXPATHLEN);
	ft_bzero(serv_path, MAXPATHLEN);
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
		flags & LOG_F_CLOSE ? overwrite[i++] = 'c' : (void)i;
	}
	return (ft_strsplit(to_split, ' '));
}

int				init_logwindow(int flags)
{
	static int	nb_inst = 0;
	t_execve	child;
	t_logwin	new_logwin;

	ft_bzero(&new_logwin, sizeof(new_logwin));
	gen_fifotmp(&new_logwin, nb_inst + 1);
	if ((child.fork_pid = fork()) == 0)
	{
		child.args = gen_execve_args(new_logwin.fifo, flags);
		execv((char *)child.args[0], (char **)child.args);
		ft_tabstrdel(&(child.args));
		exit(0);
	}
	wait(NULL);
	if (open_fifotmp(&new_logwin, flags) == -1)
		return (-1);
	++nb_inst;
	if (flags & LOG_F_VERBOSE)
		ft_printf(CLIENT_CONNECTED, new_logwin.fifo);
	return (new_logwin.fd);
}
