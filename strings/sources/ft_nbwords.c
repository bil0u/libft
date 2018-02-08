/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbwords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:51:17 by upopee            #+#    #+#             */
/*   Updated: 2018/02/08 06:22:50 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_nbwords(char const *s, int c)
{
	size_t	nb;

	nb = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			nb++;
			while (*s && *s != c)
				s++;
		}
	}
	return (nb);
}
