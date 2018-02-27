/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_write.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:33:07 by upopee            #+#    #+#             */
/*   Updated: 2018/02/26 23:02:36 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_WRITE_H
# define READ_WRITE_H

# include <stddef.h>

int			get_next_line(const int fd, char **line);
int			gnl_end(const int fd);

void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putnchar_fd(char c, size_t len, int fd);

int			ft_putstr(char const *s);
int			ft_putstr_fd(char const *s, int fd);
int			ft_putendl(char const *s);
int			ft_putendl_fd(char const *s, int fd);

int			ft_putnbr(int n);
int			ft_putnbr_fd(int n, int fd);

int			ft_putwchart(wchar_t c);
int			ft_putwchart_fd(wchar_t wc, int fd);

int			ft_putwstr(wchar_t const *s);
int			ft_putwstr_fd(wchar_t const *s, int fd);
int			ft_putnwstr_fd(wchar_t const *s, size_t len, int fd);
int			ft_putnbyteswstr_fd(wchar_t const *s, size_t len, int fd);

int			ft_putnbits(void *item, size_t len);
int			ft_putnbits_fd(void *item, size_t len, int fd);
int			ft_putnbytes(void *item, size_t byte_size, int mod);
int			ft_putnbytes_fd(void *item, size_t byte_size, int fd, int mod);

#endif
