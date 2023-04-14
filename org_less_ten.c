/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   org_less_ten.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:51:37 by ablanco-          #+#    #+#             */
/*   Updated: 2023/04/14 18:10:34 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_n(t_list **stack_a)
{
	int	n[3];

	n[0] = ((t_in_nd *)(*stack_a)->content)->idx;
	n[1] = ((t_in_nd *)(*stack_a)->next->content)->idx;
	n[2] = ((t_in_nd *)(*stack_a)->next->next->content)->idx;
	if (n[0] > n[1] && n[0] < n[2])
		swap_a_b(stack_a, NULL);
	else if (n[0] > n[1] && n[0] > n[2] && n[1] > n[2])
	{
		swap_a_b(stack_a, NULL);
		reverse_select(stack_a, NULL);
	}
	else if (n[0] > n[1] && n[0] > n[2] && n[1] < n[2])
		rotate_select(stack_a, NULL);
	else if (n[0] < n[1] && n[0] < n[2] && n[1] > n[2])
	{
		swap_a_b(stack_a, NULL);
		rotate_select(stack_a, NULL);
	}
	else if (n[0] < n[1] && n[0] > n[2] && n[1] > n[2])
		reverse_select(stack_a, NULL);
}

int	found_next(t_list *search, int cont)
{
	int	pos;

	pos = 0;
	while (((t_in_nd *)search->content)->idx != cont && search->next)
	{
		search = search->next;
		pos++;
	}
	return (pos);
}

void	rotate_halves(t_list **stack_a, t_list *search, int pos)
{
	if (pos < (n_nod(stack_a) / 2))
	{
		while (*stack_a != search)
			rotate_select(stack_a, NULL);
	}
	else if (pos >= (n_nod(stack_a) / 2))
		while (*stack_a != search)
			reverse_select(stack_a, NULL);
}

void	n_less_ten(t_list **stack_a, t_list **stack_b, int n_total)
{
	t_list			*search;
	int				pos;
	static int		cont = 0;

	search = *stack_a;
	pos = 0;
	cont++;
	if (n_total <= 3)
	{
		three_n(stack_a);
		return ;
	}
	pos = found_next(search, cont);
	rotate_halves(stack_a, search, pos);
	ft_push(stack_a, stack_b, 'b');
	if (check_all_in_stack_b(stack_b, (n_total - 3)))
		n_less_ten(stack_a, stack_b, n_total);
	else
	{
		three_n(stack_a);
		ft_all_btoa(stack_a, stack_b);
	}
}