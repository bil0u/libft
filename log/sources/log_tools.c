/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:29:43 by upopee            #+#    #+#             */
/*   Updated: 2018/03/13 19:30:40 by upopee           ###   ########.fr       */
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

t_logenv	*get_logenv(void)
{
	static t_logenv		env;

	return (&env);
}

t_logwin	*get_logwin(char *to_find)
{
	t_logenv	*env;
	uint8_t		i;

	env = get_logenv();
	i = 0;
	while (i < env->nb_inst)
	{
		if (ft_strequ(env->windows[i].name, to_find))
			return (&(env->windows[i]));
		++i;
	}
	return (NULL);
}

int			ft_logthis(int fd, int flags, char *s)
{
	char		tmp[LOG_BUFF_SIZE];

	if (flags == LOG_F_ERR)
		ft_sprintf(tmp, "%s%s", LOG_ERR, s);
	else if (flags == LOG_F_WARN)
		ft_sprintf(tmp, "%s%s", LOG_WARN, s);
	else if (flags == LOG_F_INFO)
		ft_sprintf(tmp, "%s%s", LOG_INFO, s);
	else if (flags == 0)
		ft_sprintf(tmp, "%s", s);
	ft_putstr_fd(tmp, fd);
	return (0);
}

int			create_logfile(char *fifo, char *path)
{
	char	file[MAXPATHLEN];
	char	*overwrite;
	char	*needed;
	int		out_fd;

	ft_strcpy(file, path);
	overwrite = ft_strrchr(file, '/') + 1;
	ft_strcpy(overwrite, "log_files/");
	overwrite += 10;
	mkdir(file, 0777);
	needed = ft_strrchr(fifo, '/') + 1;
	ft_strcpy(overwrite, needed);
	out_fd = open(file, O_WRONLY | O_CREAT | O_APPEND);
	fchmod(out_fd, 0777);
	return (out_fd);
}
