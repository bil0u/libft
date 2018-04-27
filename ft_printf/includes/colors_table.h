/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_table.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 15:51:29 by upopee            #+#    #+#             */
/*   Updated: 2018/04/27 17:32:19 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_TABLE_H
# define COLORS_TABLE_H

# define C_EOC 			"\e[0m"
# define C_BOLD			"\e[1m"
# define C_LIGHT		"\e[2m"
# define C_UNDERL		"\e[4m"
# define C_BLINK		"\e[5m"
# define C_REVERS		"\e[7m"
# define C_HIDDEN		"\e[8m"

# define CF_DEFAULT		"\e[39m"
# define CF_BLACK		"\e[30m"
# define CF_WHITE		"\e[97m"
# define CF_RED			"\e[31m"
# define CF_GREEN		"\e[32m"
# define CF_YELLOW		"\e[33m"
# define CF_BLUE		"\e[34m"
# define CF_MAGENTA		"\e[35m"
# define CF_CYAN		"\e[36m"

# define CB_DEFAULT		"\e[49m"
# define CB_BLACK		"\e[40m"
# define CB_WHITE		"\e[47m"
# define CB_RED			"\e[41m"
# define CB_GREEN		"\e[42m"
# define CB_YELLOW		"\e[43m"
# define CB_BLUE		"\e[44m"
# define CB_MAGENTA		"\e[45m"
# define CB_CYAN		"\e[46m"

# define NB_COLORS 		25
# define COLOR_MAX_LEN 	10

char	g_colors_table[NB_COLORS][COLOR_MAX_LEN] =
{
	C_EOC,
	C_BOLD,
	C_LIGHT,
	C_UNDERL,
	C_BLINK,
	C_REVERS,
	C_HIDDEN,
	CF_DEFAULT,
	CF_BLACK,
	CF_WHITE,
	CF_RED,
	CF_GREEN,
	CF_YELLOW,
	CF_BLUE,
	CF_MAGENTA,
	CF_CYAN,
	CB_DEFAULT,
	CB_BLACK,
	CB_WHITE,
	CB_RED,
	CB_GREEN,
	CB_YELLOW,
	CB_BLUE,
	CB_MAGENTA,
	CB_CYAN
};

char	g_colors_ref_table[NB_COLORS][COLOR_MAX_LEN] =
{
	"EOC}",
	"BOLD}",
	"LIGHT}",
	"UNDERL}",
	"BLINK}",
	"REVERS}",
	"HIDDEN}",
	"DEFAULT}",
	"BLACK}",
	"WHITE}",
	"RED}",
	"GREEN}",
	"YELLOW}",
	"BLUE}",
	"MAGENTA}",
	"CYAN}",
	"B_DEFAULT}",
	"B_BLACK}",
	"B_WHITE}",
	"B_RED}",
	"B_GREEN}",
	"B_YELLOW}",
	"B_BLUE}",
	"B_MAGENTA}",
	"B_CYAN}"
};

#endif
