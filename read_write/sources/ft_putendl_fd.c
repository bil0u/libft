/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:03:46 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:43:49 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_write.h"

int		ft_putendl_fd(char const *s, int fd)
{
	int		ret;

	ret = ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	return (ret + 1);
}
