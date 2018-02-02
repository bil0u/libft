/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 01:22:20 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:44:35 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>
#include "read_write.h"

int		ft_putnwstr_fd(wchar_t const *s, size_t len, int fd)
{
	unsigned int	i;
	int				ret;

	if (s)
	{
		i = 0;
		ret = 0;
		while (s[i] && len > 0)
		{
			ret += ft_putwchart_fd(s[i], fd);
			i++;
			len--;
		}
		return (ret);
	}
	else
		return (-1);
}
