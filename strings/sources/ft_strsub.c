/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:01:11 by upopee            #+#    #+#             */
/*   Updated: 2018/02/08 06:22:09 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "strings.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*d;

	if (!(d = ft_strnew(len)))
		return (NULL);
	if (s && len)
		d = ft_strncpy(d, s + start, len);
	return (d);
}
