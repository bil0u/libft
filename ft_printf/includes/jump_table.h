/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:58:06 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:25:36 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JUMP_TABLE_H
# define JUMP_TABLE_H

# include <stdarg.h>
# include "ft_printf_structs.h"
# include "handle_functions.h"

# define GET_ASSOCIATE(x) (g_jump_table[x - 32])
# define EXEC_ASSOCIATE(x) (g_funct_table[GET_ASSOCIATE(x)])

# define IS_FLAG_CHAR(x) (GET_ASSOCIATE(x) >= 1) && GET_ASSOCIATE(x) <= 6)
# define IS_WIDTH_CHAR(x) (GET_ASSOCIATE(x) >= 7) && GET_ASSOCIATE(x) <= 8)
# define IS_PRECISION_CHAR(x) (GET_ASSOCIATE(x) == 9)
# define IS_LENGHT_CHAR(x) (GET_ASSOCIATE(x) >= 10 && GET_ASSOCIATE(x) <= 15)
# define IS_PARSE_CHAR(x) (GET_ASSOCIATE(x) >= 1 && GET_ASSOCIATE(x) <= 15)
# define IS_CONVERT_CHAR(x) (GET_ASSOCIATE(x) >= 16 && GET_ASSOCIATE(x) <= 30)
# define IS_IN_RANGE(x) (GET_ASSOCIATE(x) >= 1) && GET_ASSOCIATE(x) <= 30)

typedef int	(*t_handler)(t_env *e, va_list *args, t_conv *mod);

t_handler g_funct_table[] =
{
	&spec_unknown,
	&flag_hash,
	&flag_zero,
	&flag_minus,
	&flag_space,
	&flag_plus,
	&flag_quote,
	&width_asterisk,
	&width,
	&precision,
	&mod_half,
	&mod_long,
	&mod_size_t,
	&mod_intmax_t,
	&mod_ptrdiff_t,
	&mod_longdouble,
	&spec_percent,
	&spec_digit,
	&spec_unsigned,
	&spec_octal,
	&spec_hexa,
	&spec_binary,
	&spec_float,
	&spec_float_scientific,
	&spec_float_auto,
	&spec_float_hex,
	&spec_character,
	&spec_wcharacter,
	&spec_string,
	&spec_wstring,
	&spec_pointer,
	&spec_toaddress,
};

/*
**   - Jump table -
**
**   ---------------------------------------------------------------|
**   | <sp> |       |       |   #   |       |   %   |       |   '   |
**   ---------------------------------------------------------------|
**   |      |       |   *   |   +   |       |   -   |   .   |       |
**   ---------------------------------------------------------------|
**   |  0   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |
**   ---------------------------------------------------------------|
**   |  8   |   9   |       |       |       |       |       |       |
**   ---------------------------------------------------------------|
**   |      |   A   |   B   |   C   |   D   |   E   |   F   |   G   |
**   ---------------------------------------------------------------|
**   |      |   I   |       |       |   L   |       |       |   O   |
**   ---------------------------------------------------------------|
**   |  P   |       |       |   S   |       |   U   |       |       |
**   ---------------------------------------------------------------|
**   |  X   |       |       |       |       |       |       |       |
**   ---------------------------------------------------------------|
**   |      |   a   |   b   |   c   |   d   |   e   |   f   |   g   |
**   ---------------------------------------------------------------|
**   |  h   |   i   |   j   |       |   l   |       |   n   |   o   |
**   ---------------------------------------------------------------|
**   |  p   |       |       |   s   |   t   |   u   |       |       |
**   ---------------------------------------------------------------|
**   |  x   |       |   z   |  ///  |  ///  |  ///  |  ///  |  ///  |
**   ---------------------------------------------------------------|
*/

unsigned char	g_jump_table[] =
{
	4,
	0,
	0,
	1,
	0,
	16,
	0,
	6,
	0,
	0,
	7,
	5,
	0,
	3,
	9,
	0,
	2,
	8,
	8,
	8,
	8,
	8,
	8,
	8,
	8,
	8,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	25,
	21,
	27,
	17,
	23,
	22,
	24,
	0,
	17,
	0,
	0,
	15,
	0,
	0,
	19,
	30,
	0,
	0,
	29,
	0,
	18,
	0,
	0,
	20,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	25,
	21,
	26,
	17,
	23,
	22,
	24,
	10,
	17,
	13,
	0,
	11,
	0,
	31,
	19,
	30,
	0,
	0,
	28,
	14,
	18,
	0,
	0,
	20,
	0,
	12
};

#endif
