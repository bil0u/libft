/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:01:11 by upopee            #+#    #+#             */
/*   Updated: 2018/01/31 19:58:08 by Bilou            ###   ########.fr       */
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
