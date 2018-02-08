/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:44:43 by upopee            #+#    #+#             */
/*   Updated: 2018/02/08 06:24:23 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"
#include "characters.h"

static int	is_inbase(char c, const char *base)
{
	unsigned int	index;

	index = 0;
	while (base[index] != '\0')
	{
		if (c == base[index])
			return ((int)index);
		index++;
	}
	return (-1);
}

int			ft_atoi_base(const char *str, const char *base)
{
	int				sign;
	int				res;
	unsigned int	base_n;
	int				value;

	res = 0;
	base_n = ft_strlen((char *)base);
	while (ft_iswhitespace((int)*str))
		str++;
	sign = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while ((value = is_inbase(*str, base)) != -1)
	{
		res = res * base_n + value;
		str++;
	}
	return (res * sign);
}
