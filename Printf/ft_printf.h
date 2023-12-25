/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:05:56 by eboumaza          #+#    #+#             */
/*   Updated: 2023/08/29 18:05:56 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_print_c(int c);
int		ft_print_s(char *s);
int		ft_print_p(unsigned long int p);
int		ft_print_d(int d);
int		ft_print_i(int i);
int		ft_print_u(unsigned int u);
int		ft_print_x(unsigned int x);
int		ft_print_maj_x(unsigned int X);

int		ft_putnbr(int n, int i);
int		ft_putnbr_unsigned_int(unsigned int n, int i);

char	*ft_putptr(unsigned long int n);
char	*ft_int_to_hexa(unsigned int n);

int		ft_printf(const char *str, ...);

#endif