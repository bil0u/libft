/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:53:43 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:44:45 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "strings.h"

int		ft_putstr_fd(char const *s, int fd)
{
	int		len;

	if (s != NULL)
	{
		len = ft_strlen((char *)s);
		write(fd, s, len);
		return (len);
	}
	else
		return (-1);
}
