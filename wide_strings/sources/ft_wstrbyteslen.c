/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrbyteslen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 01:12:46 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 13:51:17 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "wide_strings.h"

size_t		ft_wstrbyteslen(wchar_t const *ws)
{
	unsigned int	i;
	size_t			len;

	if (ws == NULL)
		return (0);
	i = 0;
	len = 0;
	while (ws[i])
	{
		len += ft_wcharlen((wchar_t)ws[i]);
		i++;
	}
	return (len);
}
