/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:56:19 by upopee            #+#    #+#             */
/*   Updated: 2018/02/15 18:01:54 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "strings.h"
#include "memory.h"
#include "jump_table.h"
#include "handle_utils.h"
#include "colors_table.h"

static char		*get_color(t_env *e)
{
	char	*stop;
	char	*color;
	size_t	len;
	int		i;

	if (e->format[1] != '\0' && (stop = ft_strchr(e->format, '}')) != NULL)
	{
		len = stop - e->format;
		color = ft_strtoupper(ft_strndup(e->format + 1, len));
		i = NB_COLORS;
		while (i-- > 0)
		{
			if (ft_strnequ(color, g_colors_ref_table[i], len))
			{
				e->format += len + 1;
				ft_strdel(&color);
				return (g_colors_table[i]);
			}
		}
		ft_strdel(&color);
	}
	return (NULL);
}

static int		process_arg(t_env *e, va_list *args)
{
	t_conv	c;
	int		ret;

	ft_bzero(&c, sizeof(c));
	c.prefix = "";
	ret = 0;
	e->format++;
	if (e->format[0] != '\0')
	{
		while (IS_PARSE_CHAR(e->format[0]))
			EXEC_ASSOCIATE(e->format[0])(e, args, &c);
		if (e->format[0] != '\0')
		{
			ret = EXEC_ASSOCIATE(e->format[0])(e, args, &c);
			e->format++;
		}
	}
	return (ret);
}

static void		go_to_next(t_env *e)
{
	char	*next_arg;
	char	*next_color;
	char	*next;
	int		len;

	next_arg = ft_strchr(e->format + 1, '%');
	next_color = ft_strchr(e->format + 1, '{');
	if (next_arg == NULL)
		next = next_color;
	else if (next_color == NULL)
		next = next_arg;
	else
		next = next_arg < next_color ? next_arg : next_color;
	len = next == NULL ? (int)ft_strlen(e->format) : next - e->format;
	cpy_to_lst(e, e->format, len);
	e->format += len;
}

int				process_format(t_env *e, va_list *args)
{
	char	*color;

	while (e->format[0] != '\0')
	{
		if (e->format[0] == '%')
		{
			if (process_arg(e, args) == -1)
				return (-1);
		}
		else if (e->format[0] == '{' && (color = get_color(e)) != NULL)
			cpy_to_lst(e, color, ft_strlen(color));
		else
			go_to_next(e);
	}
	return (e->ret);
}
