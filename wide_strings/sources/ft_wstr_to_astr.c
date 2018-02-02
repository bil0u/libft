/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_to_astr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 05:39:56 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 13:55:26 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"
#include "wide_strings.h"

int		ft_wstr_to_astr(wchar_t const *ws, char **dst)
{
	unsigned int	i;
	int				len;
	int				ret;

	if (ws == NULL)
		return (-1);
	i = 0;
	len = 0;
	*dst = ft_strnew(ft_wstrbyteslen(ws));
	while (ws[i])
	{
		ret = ft_wchar_to_str(ws[i], ((*dst) + len));
		len += ret;
		i++;
	}
	return (len);
}
