/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:06:01 by upopee            #+#    #+#             */
/*   Updated: 2018/03/06 17:03:43 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "linked_lists.h"
#include "strings.h"
#include "memory.h"

static t_list	*find_or_create(const int fd, t_list **list)
{
	t_file	file;
	t_list	*current;

	if (*list)
	{
		current = *list;
		while (current != NULL)
		{
			if (CONTENT(current)->fd == fd)
				return (current);
			current = current->next;
		}
	}
	file.fd = fd;
	file.index = NULL;
	file.remaining = 1;
	ft_lstadd(list, ft_lstnew(&file, sizeof(file)));
	return (*list);
}

static int		update_buffer(t_file *file)
{
	ft_bzero(file->buff, GNL_BUFF_SIZE);
	file->rd_len = read(file->fd, file->buff, GNL_BUFF_SIZE);
	if (file->rd_len == -1)
		return (-1);
	else if (file->rd_len == 0)
	{
		file->index = NULL;
		file->remaining = 0;
		return (0);
	}
	file->index = file->buff;
	return (1);
}

static size_t	read_line(t_file *file, char **line)
{
	size_t	to_read;
	size_t	len;
	char	*end;

	*line = NULL;
	if (file->index != NULL && file->remaining == 1)
	{
		to_read = file->buff + file->rd_len - file->index;
		end = (char *)ft_memchr(file->index, NEWLINE_CHAR, to_read);
		len = (end == NULL ? to_read : (size_t)(end - file->index));
		*line = ft_strnew(len);
		*line = ft_memmove(*line, file->index, len);
		file->index = (end == NULL ? NULL : end + 1);
		return (len);
	}
	return (0);
}

static int		get_line(t_file *file, char **line)
{
	char	*tmp;
	char	*leak;
	size_t	len;
	size_t	len_tmp;

	if (file->index == NULL && update_buffer(file) == -1)
		return (-1);
	if (file->index == NULL && file->remaining == 0)
		return (0);
	len = read_line(file, line);
	while (file->index == NULL && file->remaining == 1)
	{
		if (!(leak = *line) || update_buffer(file) == -1)
			return (-1);
		len_tmp = read_line(file, &tmp);
		*line = (char *)ft_memmove(ft_strnew(len + len_tmp), leak, len);
		ft_memmove(*line + len, tmp, len_tmp);
		if (tmp)
			free(tmp);
		if (leak)
			free(leak);
		len += len_tmp;
	}
	return (len > 0 || file->remaining == 1 ? 1 : 0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*file;
	int				ret;

	if (fd < 0 || line == NULL || GNL_BUFF_SIZE < 1)
		return (-1);
	file = find_or_create(fd, &list);
	ret = get_line(CONTENT(file), line);
	if (ret < 1)
	{
		ft_strdel(line);
		ft_lstdelthis(&list, file, ft_delcontent);
	}
	return (ret);
}
