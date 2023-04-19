/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:27:38 by ablanco-          #+#    #+#             */
/*   Updated: 2023/04/17 21:04:09 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int				c;
	int				neg;
	unsigned long	dest;

	c = 0;
	neg = 1;
	dest = 0;
	while ((str[c] == ' ') || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
		neg = neg * -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
		dest = (str[c++] - '0') + (dest * 10);
	if (dest > INT_MAX)
		exit(-1);
	return (dest * neg);
}
/*
int main(void)
{
	char nom[] = "-+646461254865";
	
	printf("%d\n", ft_atoi(nom));
	printf("%d\n", atoi(nom));
}
*/
