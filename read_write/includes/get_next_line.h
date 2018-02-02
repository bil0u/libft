/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:06:13 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:57:56 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define GNL_BUFF_SIZE 32
# define NEWLINE_CHAR '\n'
# define CONTENT(x) ((t_file *)(x)->content)

typedef struct		s_file
{
	int				fd;
	char			buff[GNL_BUFF_SIZE];
	char			*index;
	int				rd_len;
	unsigned int	remaining;
}					t_file;

int					get_next_line(const int fd, char **line);

#endif
