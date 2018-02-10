/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextws.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 22:49:08 by upopee            #+#    #+#             */
/*   Updated: 2018/02/10 23:43:40 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "characters.h"

char	*ft_nextws(char *str, unsigned int skip_first)
{
	int		i;

	if (str)
	{
		i = skip_first ? 1 : 0;
		while (str[i] != '\0' && !ft_iswhitespace(str[i]))
			i++;
		return (str[i] ? str + i : NULL);
	}
	return (NULL);
}
