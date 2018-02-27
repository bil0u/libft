/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 22:59:25 by upopee            #+#    #+#             */
/*   Updated: 2018/02/26 23:24:06 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_write.h"
#include "strings.h"

int		gnl_end(const int fd)
{
	int		ret;
	char	*tmp;

	ret = -1;
	if (fd >= 0)
	{
		tmp = NULL;
		while ((ret = get_next_line(fd, &tmp)) > 0 && tmp != NULL)
			ft_strdel(&tmp);
	}
	return (ret);
}
