/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_tools2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:42:25 by upopee            #+#    #+#             */
/*   Updated: 2018/03/20 13:48:32 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"
#include "read_write.h"

void	clear_window(char *win_name)
{
	t_logwin	*win;

	if ((win = get_logwin(win_name)) != NULL)
		ft_putstr_fd(CLEAR_SCR, win->fd);
}
