/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:53:43 by upopee            #+#    #+#             */
/*   Updated: 2018/03/11 02:30:14 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "strings.h"

int		ft_putstr_fd(char const *s, int fd)
{
	if (s != NULL)
		return (write(fd, s, ft_strlen((char *)s)));
	else
		return (-1);
}
