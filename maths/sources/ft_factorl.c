/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 00:08:09 by upopee            #+#    #+#             */
/*   Updated: 2018/02/15 12:15:05 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_factorl(unsigned int nbr)
{
	unsigned int	res;

	if (nbr == 0)
		return (1);
	res = nbr;
	while (--nbr)
		res *= nbr;
	return (res);
}
