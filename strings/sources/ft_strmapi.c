/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:58:46 by upopee            #+#    #+#             */
/*   Updated: 2018/01/31 19:56:20 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "strings.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	char			*tmp;
	unsigned int	i;

	i = 0;
	if (s)
	{
		if (!(new = ft_strdup(s)))
			return (NULL);
		tmp = new;
		if (f)
			while (*tmp)
				*tmp++ = (*f)(i++, *s++);
		return (new);
	}
	return (NULL);
}
