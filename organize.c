/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 01:06:44 by ablanco-          #+#    #+#             */
/*   Updated: 2023/04/06 03:00:28 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		idx_control(t_list **stack_b, int n_nodos)
{
	t_list	*search;

	search = *stack_b;
	if (n_nodos != n_nod(stack_b))
		return(1);
	while (search)
	{
		while (((t_in_nd *)search->content)->idx == n_nodos)
		{
			search = search->next;
			n_nodos--;
		}
		if (((t_in_nd *)search->content)->idx != n_nodos)
			return (1);
	}
	return (0);
}

void	org_few_n(t_list **stack_a, t_list **stack_b, int n_total)
{
	t_list	*search;
	int		pos;
	static int		cont = -1;

	search = *stack_a;
	//cont = 0;
	pos = 0;
	cont++;
	while (((t_in_nd *)search->content)->idx != cont && search->next)
	{
		
		search = search->next;
		pos++;
	}
	if (pos < (n_nod(stack_a) / 2) && idx_control(stack_b, n_total))
	{
		while (*stack_a != search)
			rotate_select(stack_a, NULL);
	}
	else if (pos >= (n_nod(stack_a) / 2) && idx_control(stack_b, n_total))
		while (*stack_a != search)
			reverse_select(stack_a, NULL);
	ft_push(stack_a, stack_b, 'b'); //Revisar que sea la letra a
	if (idx_control(stack_b, n_nod(stack_b))) // TIENES QUE MIRAR QUE NO SE META AQUI CUANDO NO HAYA STACK A
		org_few_n(stack_a, stack_b, n_total);
}