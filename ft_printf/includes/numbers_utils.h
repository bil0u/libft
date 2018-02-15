/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 03:58:52 by upopee            #+#    #+#             */
/*   Updated: 2018/02/15 12:11:46 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBERS_UTILS_H
# define NUMBERS_UTILS_H

# include <stdint.h>

char	*utoa_base_prec(uintmax_t n, t_mod *m, size_t sz);
void	init_mod_nbr(t_conv *c, t_mod *m, uintmax_t nbr);
void	apply_parsing_nbr(t_conv *c, t_mod *m);
char	*add_prefix(char *s, char *p, size_t s_len, size_t p_len);

#endif
