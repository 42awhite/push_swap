/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:24:43 by ablanco-          #+#    #+#             */
/*   Updated: 2023/03/31 18:41:36 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	t_list	*aux;
	t_list	*aux_pt;

	if (!(*stack_a) || !(*stack_a)->next)
	{
		perror("insuficentes nodos");
		return ;
	}
	aux = *stack_a;
	(*stack_a) = (*stack_a)->next;
	aux_pt = (*stack_a)->next;
	(*stack_a)->next = aux;
	(*stack_a)->next->next = aux_pt;
}