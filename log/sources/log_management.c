/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:40:45 by upopee            #+#    #+#             */
/*   Updated: 2018/03/09 07:29:33 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "log.h"

t_logwin	*find_logwin(void *data_ref, int (*cmp)())
{
	t_logenv	*env;
	t_list		*log_win;

	env = get_logservice_env();
	log_win = ft_lstfind(env->log_windows, data_ref, cmp);
	if (log_win)
		return (log_win->content);
	return (NULL);
}

int			ft_logthis(int fd, char *msg)
{
	t_logenv	*env;

	env = get_logservice_env();
	if (ft_lstfind(env->log_windows, &fd, &item_fd_cmp) == NULL)
	{
		ft_dprintf(2, LOG_ERR_NOFD, fd);
		return (-1);
	}
	else
	{
		ft_dprintf(fd, msg);
		return (0);
	}
}

int			close_window(int fd)
{
	t_logenv	*env;

	if (fd == -1)
	{
		ft_dprintf(2, LOG_ERR_BADFD, fd);
		return (-1);
	}
	env = get_logservice_env();
	if (ft_lstdelif(&env->log_windows, &fd, &item_fd_cmp, &terminate_session))
	{
		ft_dprintf(2, LOG_ERR_NOFD, fd);
		return (-1);
	}
	return (0);
}

void		close_allwindows(void)
{
	t_logenv	*env;

	env = get_logservice_env();
	ft_lstdel(&env->log_windows, &terminate_session);
}
