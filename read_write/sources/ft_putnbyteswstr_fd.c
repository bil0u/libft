/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbyteswstr_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 01:22:20 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:59:28 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "read_write.h"
#include "wide_strings.h"

int		ft_putnbyteswstr_fd(wchar_t const *s, size_t nb_bytes, int fd)
{
	unsigned int	i;
	size_t			remaining;
	int				ret;

	if (s && nb_bytes > 0)
	{
		i = 0;
		remaining = nb_bytes;
		while (s[i] && remaining > ft_wcharlen(s[i]))
		{
			ret = ft_putwchart_fd(s[i], fd);
			remaining -= ret;
			i++;
		}
		if ((remaining) && (MB_CUR_MAX > 1))
			ft_putwchart_fd(s[i], fd);
		else if ((remaining) && (s[i] <= 0xFF))
			ft_putchar_fd(s[i], fd);
		return (nb_bytes);
	}
	else
		return (0);
}
