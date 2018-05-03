/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:33:07 by upopee            #+#    #+#             */
/*   Updated: 2018/05/03 12:31:48 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include <stddef.h>
# include <stdint.h>

# define OPP(x) (-(x))
# define MIN(x1, x2) ((x1) < (x2) ? (x1) : (x2))
# define MAX(x1, x2) ((x1) < (x2) ? (x2) : (x1))

# define BASE_2 "01"
# define BASE_8 "01234567"
# define BASE_10 "0123456789"
# define BASE_16_LOWER "0123456789abcdef"
# define BASE_16_UPPER "0123456789ABCDEF"
# define DECIMAL_SEPARATOR '.'

typedef __uint128_t	t_uint128_t;

int				ft_atoi(const char *str);
int				ft_atoi_base(const char *str, const char *base);
long int		ft_atol(const char *str);
long int		ft_atol_base(const char *str, const char *base);
intmax_t		ft_atoimax(const char *str);
intmax_t		ft_atoimax_base(const char *str, const char *base);

int				ft_atoi_chr(char **str);

char			*ft_itoa(int n);
char			*ft_itoa_base(int n, const char *base);
char			*ft_ltoa(long int n);
char			*ft_ltoa_base(long int n, const char *base);
char			*ft_imaxtoa(intmax_t n);
char			*ft_imaxtoa_base(intmax_t n, const char *base);
char			*ft_utoa_base(uintmax_t n, const char *base);
size_t			ft_nbrlen_base(t_uint128_t n, unsigned int base_n);
intmax_t		ft_sqrt(intmax_t nb);
intmax_t		ft_sqrt_next(intmax_t nb);
intmax_t		ft_power(intmax_t nb, int p);
intmax_t		ft_pgcd(intmax_t a, intmax_t b);
unsigned int	ft_factorl(unsigned int nbr);
void			ft_swap(int *a, int *b);
int				ft_abs(int n);

#endif
