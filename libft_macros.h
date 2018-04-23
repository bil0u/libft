/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_macros.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:44:25 by upopee            #+#    #+#             */
/*   Updated: 2018/04/20 22:08:38 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MACROS_H
# define LIBFT_MACROS_H

# define TRUE		1
# define FALSE		0
# define SUCCESS	0
# define FAILURE	-1

/*
** -- BIT OPERATIONS
*/

# define BSET(x, bit)			((x) |= (bit))
# define BUNSET(x, bit)			((x) &= ~(bit))
# define BCOPY(x, y, bit)		((y) = ((y) & ~(bit)) | ((x) & (bit)))
# define BIS_SET(x, bit)		(((x) & (bit)) != 0)

# define SWAP_UINT16(x)			(((x) >> 8) | ((x) << 8))
# define SWAP_UINT32LEFT(x)		(((x) >> 24) | (((x) & 0x00FF0000) >> 8))
# define SWAP_UINT32RIGHT(x)	((((x) & 0x0000FF00) << 8) | ((x) << 24))
# define SWAP_UINT32(x)			(SWAP_UINT32LEFT(x) | SWAP_UINT32RIGHT(x))

/*
** - STRING COLORING FOR FT_PRINTF
*/

# define COLD(str)				"{default}" str "{eoc}"
# define COLBK(str)				"{black}" str "{eoc}"
# define COLW(str)				"{white}" str "{eoc}"
# define COLR(str)				"{red}" str "{eoc}"
# define COLG(str)				"{green}" str "{eoc}"
# define COLY(str)				"{yellow}" str "{eoc}"
# define COLB(str)				"{blue}" str "{eoc}"
# define COLM(str)				"{magenta}" str "{eoc}"
# define COLC(str)				"{cyan}" str "{eoc}"

# define COLBD(str)				"{b_default}" str "{eoc}"
# define COLBBK(str)			"{b_black}" str "{eoc}"
# define COLBW(str)				"{b_white}" str "{eoc}"
# define COLBR(str)				"{b_red}" str "{eoc}"
# define COLBG(str)				"{b_green}" str "{eoc}"
# define COLBY(str)				"{b_yellow}" str "{eoc}"
# define COLBB(str)				"{b_blue}" str "{eoc}"
# define COLBM(str)				"{b_magenta}" str "{eoc}"
# define COLBC(str)				"{b_cyan}" str "{eoc}"

#endif
