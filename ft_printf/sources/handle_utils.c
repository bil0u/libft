/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 02:24:04 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:19:24 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_structs.h"
#include "memory.h"
#include "strings.h"

void	lstcpy_to_str(t_list *list, char *str)
{
	while (list)
	{
		ft_memmove(str, list->content, list->content_size);
		str += list->content_size;
		list = list->next;
	}
}

void	cpy_to_lst(t_env *e, char *str, size_t len)
{
	if (len)
	{
		ft_lstappend(&(e->list), ft_lstnew(str, len));
		e->ret += len;
	}
}

void	pad_to_lst(t_env *e, char c, int len)
{
	char	*pad;

	if (len > 0)
	{
		pad = ft_strnew(len);
		ft_memset(pad, c, len);
		cpy_to_lst(e, pad, len);
		ft_strdel(&pad);
	}
}

void	str_to_lst(t_env *e, char *str, t_conv *c, t_mod *m)
{
	if (c->left_justify == 0)
		pad_to_lst(e, ' ', m->delta);
	cpy_to_lst(e, str, m->p_len + m->a_len);
	if (c->left_justify == 1)
		pad_to_lst(e, ' ', m->delta);
}
