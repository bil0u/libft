/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:01:46 by upopee            #+#    #+#             */
/*   Updated: 2018/03/20 15:38:04 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "process_functions.h"
#include "handle_utils.h"
#include "memory.h"
#include "strings.h"

int		ft_printf(const char *format, ...)
{
	char		*str;
	t_env		e;
	va_list		args;

	if (format == NULL)
		return (-1);
	ft_bzero(&e, sizeof(e));
	va_start(args, format);
	e.format = (char *)format;
	e.ret = process_format(&e, &args);
	if (e.ret > 0)
	{
		str = ft_strnew(e.ret + 1);
		lstcpy_to_str(e.list, str);
		write(STDIN_FILENO, str, e.ret);
		ft_strdel(&str);
	}
	if (e.list)
		ft_lstdel(&(e.list), &ft_delcontent);
	va_end(args);
	return (e.ret);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	char		*str;
	t_env		e;
	va_list		args;

	if (fd < 1 || format == NULL)
		return (-1);
	ft_bzero(&e, sizeof(e));
	va_start(args, format);
	e.format = (char *)format;
	e.ret = process_format(&e, &args);
	if (e.ret > 0)
	{
		str = ft_strnew(e.ret + 1);
		lstcpy_to_str(e.list, str);
		write(fd, str, e.ret);
		ft_strdel(&str);
	}
	if (e.list)
		ft_lstdel(&(e.list), &ft_delcontent);
	va_end(args);
	return (e.ret);
}

int		ft_sprintf(char *str, const char *format, ...)
{
	t_env		e;
	va_list		args;

	if (format == NULL || str == NULL)
		return (-1);
	ft_bzero(&e, sizeof(e));
	va_start(args, format);
	e.format = (char *)format;
	e.ret = process_format(&e, &args);
	if (e.ret > 0)
		lstcpy_to_str(e.list, str);
	if (e.list)
		ft_lstdel(&(e.list), &ft_delcontent);
	va_end(args);
	return (e.ret);
}

int		ft_asprintf(char **ret, const char *format, ...)
{
	t_env		e;
	va_list		args;
	char		*dst;

	if (format == NULL || ret == NULL)
		return (-1);
	ft_bzero(&e, sizeof(e));
	va_start(args, format);
	e.format = (char *)format;
	e.ret = process_format(&e, &args);
	if (e.ret > 0)
	{
		dst = ft_strnew(e.ret + 1);
		lstcpy_to_str(e.list, dst);
		*ret = dst;
	}
	if (e.list)
		ft_lstdel(&(e.list), &ft_delcontent);
	va_end(args);
	return (e.ret);
}
