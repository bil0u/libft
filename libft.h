/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:44:25 by upopee            #+#    #+#             */
/*   Updated: 2018/02/08 06:26:24 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define TRUE 1
# define FALSE 0

# define BSET(x, bit) ((x) |= (bit))
# define BUNSET(x, bit) ((x) &= ~(bit))
# define BIS_SET(x, bit) (((x) & (bit)) != 0)

# include "./characters/includes/characters.h"
# include "./ft_printf/includes/ft_printf.h"
# include "./linked_lists/includes/linked_lists.h"
# include "./maths/includes/maths.h"
# include "./memory/includes/memory.h"
# include "./read_write/includes/read_write.h"
# include "./strings/includes/strings.h"
# include "./wide_strings/includes/wide_strings.h"

#endif
