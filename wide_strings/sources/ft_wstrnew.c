/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 05:26:23 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 13:51:33 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

wchar_t		*ft_wstrnew(size_t size)
{
	wchar_t		*new;

	new = (wchar_t *)ft_memalloc(sizeof(wchar_t) * (size + 1));
	return (new);
}
