/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:01:50 by upopee            #+#    #+#             */
/*   Updated: 2018/01/31 19:58:44 by Bilou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_wordlen(char const *s, char c)
{
	size_t len;

	len = 0;
	if (!s)
		return (0);
	while (*s && *s++ != c)
		len++;
	return (len);
}
