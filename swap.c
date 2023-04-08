/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:24:43 by ablanco-          #+#    #+#             */
/*   Updated: 2023/04/08 23:15:25 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*aux;
	t_list	*aux_pt;

	if (!(*stack) || !(*stack)->next)
	{
		perror("insuficentes nodos\n");
		return ;
	}
	aux = *stack;
	(*stack) = (*stack)->next;
	aux_pt = (*stack)->next;
	(*stack)->next = aux;
	(*stack)->next->next = aux_pt;
}

void	swap_a_b(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL)
	{
		swap(stack_b);
		ft_printf("sb\n");
	}
	else if (stack_b == NULL)
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
	else
	{
		swap(stack_a);
		swap(stack_b);
		ft_printf("ss\n");
	}
}

void	ft_push(t_list **stack_out, t_list **stack_add, char c)
{
	t_list	*aux;

	if (!(*stack_out))
	{
		perror("insuficentes nodos\n");
		return ;
	}
	aux = *stack_add;
	*stack_add = *stack_out;
	*stack_out = (*stack_out)->next;
	(*stack_add)->next = aux;
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}
