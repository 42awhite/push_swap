/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:23:38 by ablanco-          #+#    #+#             */
/*   Updated: 2023/04/06 00:29:41 by ablanco-         ###   ########.fr       */
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
			if (((t_in_nd *)comp->content)->n > ((t_in_nd *)other_n->content)->n)
				cont++;
			other_n = other_n->next;
		}
		((t_in_nd *)comp->content)->idx = cont;
		comp = comp->next;
	}
}

int	n_nod(t_list **stack_a)
{
	int		cont;
	t_list 	*aux;

	cont = 0;
	aux = *stack_a;
	while(aux)
	{
		aux = aux->next;
		cont++;
	}
	return(cont);
}

