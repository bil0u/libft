/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_initwindow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:08:53 by upopee            #+#    #+#             */
/*   Updated: 2018/03/13 19:31:52 by upopee           ###   ########.fr       */
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

static int		open_fifotmp(char *fifo)
{
	int		fd;

	if (access(fifo, F_OK) < 0)
		mkfifo(fifo, 0777);
	if ((fd = open(fifo, O_WRONLY)) == -1)
	{
		ft_dprintf(2, LOG_ERR_OPEN, fifo);
		return (-1);
	}
	return (fd);
}

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

static char		**gen_execve_args(char *fifo, int flags)
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
	if (flags)
	{
		ft_strcpy(overwrite, " -o -");
		i = 5;
		flags & LOG_F_VERBOSE ? overwrite[i++] = 'v' : (void)i;
		flags & LOG_F_SAVE ? overwrite[i++] = 's' : (void)i;
		flags & LOG_F_CLOSE ? overwrite[i++] = 'c' : (void)i;
	}
	return (ft_strsplit(to_split, ' '));
}

static int		init_logwindow(int flags, uint8_t win_no)
{
	char		fifo[MAXPATHLEN];
	char		**args;
	int			fd;

	ft_strcpy(fifo, LOG_FILE_TEMPLATE);
	ft_sprintf(ft_strchr(fifo, 'X'), "%3.3hhu", win_no);
	if (fork() == 0)
	{
		args = gen_execve_args(fifo, flags);
		execv(args[0], args);
		ft_tabstrdel(&args);
		exit(0);
	}
	wait(NULL);
	if ((fd = open_fifotmp(fifo)) == -1)
		return (-1);
	ft_printf(CLIENT_CONNECTED, fifo);
	return (fd);
}

int				new_logwindow(char *name, int flags)
{
	t_logenv	*env;
	t_logwin	*win;

	if (get_logwin(name) != NULL)
	{
		ft_dprintf(2, LOG_ERR_WINEXIST, name);
		return (-1);
	}
	env = get_logenv();
	win = &(env->windows[env->nb_inst]);
	if ((win->fd = init_logwindow(flags, env->nb_inst + 1)) == -1)
		ft_dprintf(2, LOG_ERR_WINCRASH, name);
	else
	{
		env->nb_inst++;
		ft_strncpy(win->name, name, NAME_MAXLEN);
	}
	return (win->fd);
}
