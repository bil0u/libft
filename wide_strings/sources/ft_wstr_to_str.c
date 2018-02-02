/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 05:39:40 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 13:55:02 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wide_strings.h"

int		ft_wstr_to_str(wchar_t const *ws, char *dst)
{
	unsigned int	i;
	int				len;

	if (ws == NULL)
		return (-1);
	i = 0;
	len = 0;
	while (ws[i])
	{
		len += ft_wchar_to_str(ws[i], (dst + len));
		i++;
	}
	return (len);
}
