/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funciones.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:44:48 by ablanco-          #+#    #+#             */
/*   Updated: 2023/03/07 19:34:03 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_f(char *str)
{
	size_t	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

void	ft_char(char c)
{
	write(1, &c, 1);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	write (1, s, ft_strlen_f(s));
	return (ft_strlen_f(s));
}
