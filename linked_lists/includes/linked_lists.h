/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:33:07 by upopee            #+#    #+#             */
/*   Updated: 2018/02/15 12:13:21 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LISTS_H
# define LINKED_LISTS_H

# include <stddef.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdelthis(t_list **alst, t_list *item);
void				ft_delcontent(void *content, size_t size);

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstappend(t_list **alst, t_list *new);

void				ft_lstmerge(t_list **lst1, t_list *lst2);
void				ft_lstreverse(t_list **lst);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstforeach(t_list *lst, void (*f)(void *));
void				ft_lstforeachif(t_list *l, void (*f)(void *),
									void *d, int (*c)());

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstat(t_list *lst, unsigned int nbr);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstfind(t_list *lst, void *data_ref, int (*cmp)());

#endif
