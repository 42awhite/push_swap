/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:54:26 by ablanco-          #+#    #+#             */
/*   Updated: 2023/04/08 22:53:12 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_n_comp(char **num)
{
	int	cont;
	int	cont2;

	cont = 0;
	while (num[cont])
	{
		cont2 = cont + 1;
		while (num[cont2])
		{
			if (ft_strncmp(num[cont], num[cont2]) == 0)
			{
				perror("n iguales");
				exit(-1);
			}
			cont2++;
		}
		cont++;
	}
}

void	str_is_n(char **num)
{
	int	cont;
	int	cont2;

	cont = 0;
	cont2 = 0;
	while (num[cont])
	{
		while (num[cont][cont2])
		{
			if ((num[cont][cont2] < '0' || num[cont][cont2] > '9') &&
				(num[cont][cont2] != '\0'))
			{
				perror("no n");
				exit(-1);
			}
			cont2++;
		}
		cont2 = 0;
		cont++;
	}
}
