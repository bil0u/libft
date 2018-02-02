/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 01:12:17 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:44:32 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "memory.h"

void	ft_putnchar_fd(char pad, size_t len, int fd)
{
	char	tmp[len];

	if (len > 0)
	{
		ft_memset(tmp, (int)pad, len);
		write(fd, tmp, len);
	}
}
