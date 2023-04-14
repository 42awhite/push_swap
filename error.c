/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:54:26 by ablanco-          #+#    #+#             */
/*   Updated: 2023/04/11 16:34:35 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_n_comp(t_list **stack_a)
{
	t_list	*n_comp;
	t_list	*other_n;

	n_comp = *stack_a;
	while (n_comp)
	{
		other_n = n_comp->next;
		while (other_n)
		{
			if (((t_in_nd *)n_comp->content)->n
				== ((t_in_nd *)other_n->content)->n)
			{
				perror("n iguales");
				exit(-1);
			}
			other_n = other_n->next;
		}
		n_comp = n_comp->next;
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
			if (cont2 == 0
				&& (num[cont][cont2] == '-' || num[cont][cont2] == '+'))
				cont2++;
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
