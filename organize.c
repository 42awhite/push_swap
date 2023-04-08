/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 01:06:44 by ablanco-          #+#    #+#             */
/*   Updated: 2023/04/08 18:32:45 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		idx_control(t_list **stack_b, int n_nodos)
{
	t_list	*search;

	search = *stack_b;
	if (n_nodos != n_nod(stack_b))
		return(1);
	return (0);
}

void	org_few_n(t_list **stack_a, t_list **stack_b, int n_total)
{
	t_list	*search;
	int		pos;
	static int		cont = 0;

	search = *stack_a;
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
	ft_push(stack_a, stack_b, 'b'); 
	if (idx_control(stack_b, n_total)) 
		org_few_n(stack_a, stack_b, n_total);
}

void	ft_all_btoa(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
		ft_push(stack_b, stack_a, 'a');
}

void	ft_radix(t_list **stack_a, t_list **stack_b, int n_nods)
{
	int	n_laps;
	int idx_nod;
	int idx_bi;

	n_laps = 1;
	idx_bi = 0;
	while (n_laps < n_nods)
	{
		n_laps = n_laps * 2;
		idx_nod = 0;
		while (idx_nod < n_nods)
		{
			if (((((t_in_nd *)(*stack_a)->content)->idx >> idx_bi) & 1) == 0)
				ft_push(stack_a, stack_b, 'b');
			else
				rotate_select(stack_a, NULL);
			idx_nod++;
		}
		ft_all_btoa(stack_a, stack_b);
		idx_bi++;
	}
 }