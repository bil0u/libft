/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 02:24:21 by upopee            #+#    #+#             */
/*   Updated: 2018/03/16 02:38:41 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "process_functions.h"
#include "handle_utils.h"
#include "memory.h"
#include "strings.h"

int		ft_vprintf(const char *format, va_list ap)
{
	char		*str;
	t_env		e;
	va_list		args;

	if (format == NULL)
		return (-1);
	ft_bzero(&e, sizeof(e));
	va_copy(args, ap);
	e.format = (char *)format;
	e.ret = process_format(&e, &args);
	if (e.ret > 0)
	{
		str = ft_strnew(e.ret);
		lstcpy_to_str(e.list, str);
		write(STDIN_FILENO, str, e.ret);
		ft_strdel(&str);
	}
	if (e.list)
		ft_lstdel(&(e.list), &ft_delcontent);
	va_end(args);
	return (e.ret);
}

int		ft_vdprintf(int fd, const char *format, va_list ap)
{
	char		*str;
	t_env		e;
	va_list		args;

	if (fd < 1 || format == NULL)
		return (-1);
	ft_bzero(&e, sizeof(e));
	va_copy(args, ap);
	e.format = (char *)format;
	e.ret = process_format(&e, &args);
	if (e.ret > 0)
	{
		str = ft_strnew(e.ret);
		lstcpy_to_str(e.list, str);
		write(fd, str, e.ret);
		ft_strdel(&str);
	}
	if (e.list)
		ft_lstdel(&(e.list), &ft_delcontent);
	va_end(args);
	return (e.ret);
}

int		ft_vsprintf(char *str, const char *format, va_list ap)
{
	t_env		e;
	va_list		args;

	if (format == NULL || str == NULL)
		return (-1);
	ft_bzero(&e, sizeof(e));
	va_copy(args, ap);
	e.format = (char *)format;
	e.ret = process_format(&e, &args);
	if (e.ret > 0)
		lstcpy_to_str(e.list, str);
	if (e.list)
		ft_lstdel(&(e.list), &ft_delcontent);
	va_end(args);
	return (e.ret);
}

int		ft_vasprintf(char **ret, const char *format, va_list ap)
{
	t_env		e;
	va_list		args;
	char		*dst;

	if (format == NULL || ret == NULL)
		return (-1);
	ft_bzero(&e, sizeof(e));
	va_copy(args, ap);
	e.format = (char *)format;
	e.ret = process_format(&e, &args);
	if (e.ret > 0)
	{
		dst = ft_strnew(e.ret);
		lstcpy_to_str(e.list, dst);
		*ret = dst;
	}
	if (e.list)
		ft_lstdel(&(e.list), &ft_delcontent);
	va_end(args);
	return (e.ret);
}
