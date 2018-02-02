/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:01:36 by upopee            #+#    #+#             */
/*   Updated: 2018/01/31 19:58:25 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "characters.h"

char	*ft_strtoupper(char *str)
{
	unsigned int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != 0)
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
	return (str);
}
