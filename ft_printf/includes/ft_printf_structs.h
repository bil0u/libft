/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:46:47 by upopee            #+#    #+#             */
/*   Updated: 2018/02/08 06:25:23 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCTS_H
# define FT_PRINTF_STRUCTS_H

# include <stdarg.h>
# include <stddef.h>
# include "linked_lists.h"

typedef struct		s_env
{
	char			*format;
	t_list			*list;
	int				ret;
}					t_env;

typedef enum		e_length
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z,
	t,
	L
}					t_length;

typedef struct		s_conv
{
	char			*prefix;
	int				pad_zeroes;
	int				left_justify;
	int				alt;
	int				group_thousand;
	int				have_width;
	int				width;
	int				have_precision;
	int				precision;
	t_length		length;
}					t_conv;

typedef struct		s_mod
{
	char			*base;
	size_t			b_len;
	size_t			a_len;
	size_t			p_len;
	int				delta;
}					t_mod;

#endif
