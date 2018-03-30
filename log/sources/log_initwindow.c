/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_initwindow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:08:53 by upopee            #+#    #+#             */
/*   Updated: 2018/03/30 19:16:30 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/param.h>
#include "strings.h"
#include "memory.h"
#include "read_write.h"
#include "ft_printf.h"
#include "log.h"

static void		get_serv_path(char *buff)
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

static char		**gen_execve_args(char *fifo, int w_flags)
{
	char		to_split[MAXPATHLEN];
	char		serv_path[MAXPATHLEN];
	char		*overwrite;
	int			i;

	ft_bzero(to_split, MAXPATHLEN);
	ft_bzero(serv_path, MAXPATHLEN);
	get_serv_path(serv_path);
	ft_sprintf(to_split, "/bin/bash %s -f %s", serv_path, fifo);
	overwrite = ft_strchr(to_split, '\0');
	if (w_flags)
	{
		ft_strcpy(overwrite, " -o -");
		i = 5;
		w_flags & WF_VERBOSE ? overwrite[i++] = 'v' : (void)i;
		w_flags & WF_SAVE ? overwrite[i++] = 's' : (void)i;
		w_flags & WF_CLOSE ? overwrite[i++] = 'c' : (void)i;
		w_flags & WF_KEEP ? overwrite[i++] = 'l' : (void)i;
	}
	return (ft_strsplit(to_split, ' '));
}

static int		init_logwindow(char *win_name, int w_flags)
{
	char		fifo[MAXPATHLEN];
	char		**args;
	int			fd;

	ft_strcpy(fifo, LOG_FILE_TEMPLATE);
	ft_sprintf(ft_strchr(fifo, 'X'), "%s", win_name);
	if (fork() == 0)
	{
		if (access(fifo, F_OK) < 0 && mkfifo(fifo, 0777) == 0)
		{
			args = gen_execve_args(fifo, w_flags);
			execv(args[0], args);
			ft_tabstrdel(&args);
		}
		else
		{
			fd = open(fifo, O_WRONLY);
			ft_putstr_fd(CLEAR_SCR, fd);
			w_flags & WF_VERBOSE ? ft_dprintf(fd, SERV_RESTORING) : (void)0;
			close(fd);
		}
		exit(0);
	}
	wait(NULL);
	return (open(fifo, O_WRONLY));
}

int				new_logwindow(char *win_name, int w_flags)
{
	t_logenv	*env;
	t_logwin	*win;

	if (!win_name || !(*win_name))
		return (-1);
	env = get_logenv();
	if ((win = get_logwin(win_name)) != NULL || env->nb_wins == NB_MAXWIN)
	{
		ft_dprintf(STDERR_FILENO, (win ? LOG_ERR_WINEXIST : LOG_ERR_MAXWINS),
					win_name);
		return (-1);
	}
	win = &(env->windows[env->nb_wins]);
	if ((win->fd = init_logwindow(win_name, w_flags)) == -1)
	{
		ft_dprintf(STDERR_FILENO, LOG_ERR_WINCRASH, win_name);
		return (-1);
	}
	ft_strncpy(win->name, win_name, NAME_MAXLEN);
	env->nb_wins++;
	if (w_flags & WF_VERBOSE)
		ft_printf(CLIENT_CONNECTED, win_name);
	return (win->fd);
}
