/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:29:43 by upopee            #+#    #+#             */
/*   Updated: 2018/03/15 15:45:09 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <signal.h>
#include "ft_printf.h"
#include "read_write.h"
#include "memory.h"
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

int				log_this(char *win_name, char *msg, int l_flags)
{
	size_t		msg_len;
	t_logwin	*target;
	char		tmp[LOG_BUFF_SIZE + 1];

	if (!win_name || !(*win_name))
		return (-1);
	if ((target = get_logwin(win_name)) == NULL ||
		(msg_len = ft_strlen(msg)) > LOG_BUFF_SIZE)
	{
		if (!target)
			ft_dprintf(STDERR_FILENO, LOG_ERR_WINDEXIST, win_name);
		else
			ft_dprintf(STDERR_FILENO, LOG_ERR_MSGLONG, msg);
		return (-1);
	}
	if (l_flags == LF_ERR)
		ft_sprintf(tmp, "%s%s", LOG_ERR, msg);
	else if (l_flags == LF_WARN)
		ft_sprintf(tmp, "%s%s", LOG_WARN, msg);
	else if (l_flags == LF_INFO)
		ft_sprintf(tmp, "%s%s", LOG_INFO, msg);
	else
		ft_strcpy(tmp, msg);
	ft_dprintf(target->fd, tmp);
	return (0);
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
