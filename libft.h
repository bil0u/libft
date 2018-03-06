/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:44:25 by upopee            #+#    #+#             */
/*   Updated: 2018/03/05 20:55:05 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define TRUE 1
# define FALSE 0

# define BSET(x, bit) ((x) |= (bit))
# define BUNSET(x, bit) ((x) &= ~(bit))
# define BCOPY(x, y, bit) ((y) = ((y) & ~(bit)) | ((x) & (bit)))
# define BIS_SET(x, bit) (((x) & (bit)) != 0)

# define SWAP_UINT16(x) (((x) >> 8) | ((x) << 8))
# define SWAP_UINT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | \
 						(((x) & 0x0000FF00) << 8) | ((x) << 24))

# include "./characters/includes/characters.h"
# include "./ft_printf/includes/ft_printf.h"
# include "./linked_lists/includes/linked_lists.h"
# include "./maths/includes/maths.h"
# include "./memory/includes/memory.h"
# include "./read_write/includes/read_write.h"
# include "./strings/includes/strings.h"
# include "./wide_strings/includes/wide_strings.h"
# include "./debug/includes/debug.h"

#endif
