/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:58:36 by upopee            #+#    #+#             */
/*   Updated: 2018/01/31 19:56:14 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "strings.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*tmp;

	if (s)
	{
		if (!(new = ft_strdup(s)))
			return (NULL);
		tmp = new;
		if (f)
			while (*tmp)
				*tmp++ = (*f)(*s++);
		return (new);
	}
	return (NULL);
}
