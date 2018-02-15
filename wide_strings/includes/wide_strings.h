/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_strings.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:33:07 by upopee            #+#    #+#             */
/*   Updated: 2018/02/15 12:17:21 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIDE_STRINGS_H
# define WIDE_STRINGS_H

# include <stddef.h>

size_t		ft_wcharlen(wchar_t wc);
int			ft_wchar_to_str(wchar_t wc, char *dst);
int			ft_wchar_to_astr(wchar_t wc, char **dst);

wchar_t		*ft_wstrnew(size_t size);
void		ft_wstrdel(wchar_t **ws);
wchar_t		*ft_wstrdup(wchar_t const *ws);
wchar_t		*ft_wstrncpy(wchar_t *dst, const wchar_t *src, size_t len);
size_t		ft_wstrlen(wchar_t const *ws);
size_t		ft_wstrbyteslen(wchar_t const *ws);
int			ft_wstr_to_str(wchar_t const *ws, char *dst);
int			ft_wstr_to_astr(wchar_t const *ws, char **dst);

#endif
