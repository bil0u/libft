/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:29:43 by upopee            #+#    #+#             */
/*   Updated: 2018/03/16 05:16:59 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "strings.h"
#include "log.h"

t_logenv		*get_logenv(void)
{
	static t_logenv	env;

	return (&env);
}

t_logwin		*get_logwin(char *to_find)
{
	t_logenv	*env;
	uint8_t		i;

	if (to_find == NULL || to_find[0] == '\0')
		return (NULL);
	env = get_logenv();
	i = 0;
	while (i < env->nb_wins)
	{
		if (ft_strequ(env->windows[i].name, to_find))
			return (&(env->windows[i]));
		++i;
	}
	return (NULL);
}

int				get_winfd(char *to_find)
{
	t_logwin	*win;

	win = get_logwin(to_find);
	if (win)
		return (win->fd);
	return (-1);
}

int				create_logfile(char *fifo, char *path)
{
	char		file[MAXPATHLEN];
	char		*overwrite;
	char		*needed;
	int			out_fd;

	ft_strcpy(file, path);
	overwrite = ft_strrchr(file, '/') + 1;
	ft_strcpy(overwrite, LOG_DIR);
	overwrite += ft_strlen(LOG_DIR);
	mkdir(file, 0777);
	needed = ft_strrchr(fifo, '/') + 1;
	ft_strcpy(overwrite, needed);
	overwrite = ft_strchr(overwrite, '\0');
	ft_strcpy(overwrite, LOG_EXT);
	out_fd = open(file, O_WRONLY | O_CREAT | O_APPEND);
	fchmod(out_fd, 0777);
	return (out_fd);
}

int				close_fdfifo(int fd, char *fifo, int w_flags)
{
	int			ret;

	ret = 0;
	if (fd != -1)
		ret += close(fd);
	if (fifo)
		ret += remove(fifo);
	if (w_flags & WF_CLOSE)
		kill(getppid(), SIGKILL);
	return (ret);
}
