/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 02:24:51 by upopee            #+#    #+#             */
/*   Updated: 2018/02/02 15:12:02 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_UTILS_H
# define HANDLE_UTILS_H

# include <stddef.h>
# include "ft_printf_structs.h"
# include "linked_lists.h"

void	lstcpy_to_str(t_list *list, char *str);
void	cpy_to_lst(t_env *e, char *str, size_t len);
void	pad_to_lst(t_env *e, char c, int len);
void	str_to_lst(t_env *e, char *str, t_conv *c, t_mod *m);

#endif
