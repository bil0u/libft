/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:56:50 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 13:51:54 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wide_strings.h"

wchar_t		*ft_wstrdup(wchar_t const *ws)
{
	wchar_t	*dst;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_wstrlen(ws);
	if ((dst = ft_wstrnew(len)) == NULL)
		return (NULL);
	if (dst > ws)
	{
		while (i < len)
		{
			dst[i] = ws[i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
			dst[len] = ws[len];
	}
	return (dst);
}
