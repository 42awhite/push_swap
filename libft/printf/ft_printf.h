/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:49:17 by ablanco-          #+#    #+#             */
/*   Updated: 2023/03/07 19:33:30 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>

int		ft_putchar(char c);
void	ft_char(char c);
int		ft_putnbr(long int nbr);
int		put_nbr_base(unsigned long long nbr, char *base, int base_size);
int		put_hex(unsigned long long nbr, char type);
int		put_pointer(unsigned long long pun);
int		put_unsigned(unsigned int nbr);
int		ft_strlen_f(char *str);
int		ft_putstr(char *s);
int		ft_printf(char const *str, ...);

#endif
