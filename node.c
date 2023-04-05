/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:23:38 by ablanco-          #+#    #+#             */
/*   Updated: 2023/04/05 00:51:51 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_idx(t_list **stack_a)
{
	t_list	*comp;
	t_list	*other_n;
	int		cont;

	comp = *stack_a;
	while (comp)
	{
		cont = 0;
		other_n = *stack_a;
		while (other_n)
		{
			if (comp->content < other_n->content)
				cont++;
		other_n = other_n->next;
		}
		((t_in_nd *)comp->content)->idx = cont;
		comp = comp->next;
	}
}

int	n_nod(t_list **stack_a)
{
	int	cont;

	cont = 0;
	while(*stack_a)
	{
		*stack_a = (*stack_a)->next;
		cont++;
	}
	return(cont);
}

