/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:53:43 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:53:56 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "read_write.h"

int		ft_putwstr_fd(wchar_t const *s, int fd)
{
	unsigned int	i;
	int				ret;

	if (s)
	{
		i = 0;
		ret = 0;
		while (s[i])
		{
			ret += ft_putwchart_fd(s[i], fd);
			i++;
		}
		return (ret);
	}
	else
		return (-1);
}
