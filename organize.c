/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 01:06:44 by ablanco-          #+#    #+#             */
/*   Updated: 2023/04/05 02:28:23 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	idx_control(t_list **stack_a, t_list **stack_b)
{
	int cont;
	t_list	*search;

	cont = 0;
	search = *stack_a;
	while (search)
	{
		while (((t_in_nd *)search->content)->idx == cont)
		{
			search = search->next;
			cont++;
		}
		if (((t_in_nd *)search->content)->idx != cont)
			org_few_n(stack_a, stack_b);
	}
}

void	org_few_n(t_list **stack_a, t_list **stack_b)
{
	t_list	*search;
	int		pos;
	static int		cont = -1;

	search = *stack_a;
	//cont = 0;
	pos = 0;
	cont++;
	while (((t_in_nd *)search->content)->idx != cont)
	{
		search = search->next;
		pos++;
	}
	if (pos < (n_nod(stack_a) / 2))
	{
		while (*stack_a != search)
			rotate_select(stack_a, NULL);
	}
	else
		while (*stack_a != search)
			reverse_select(stack_a, NULL);
	ft_push(stack_a, stack_b, 'a'); //Revisar que sea la letra a
	idx_control(stack_a, stack_b);
}