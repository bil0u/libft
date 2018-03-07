/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:40:45 by upopee            #+#    #+#             */
/*   Updated: 2018/03/07 18:16:44 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "log.h"

int			print_to_window(int fd, char *msg)
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
