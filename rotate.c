/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 23:02:25 by ablanco-          #+#    #+#             */
/*   Updated: 2023/04/08 23:10:07 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!(*stack) || !(*stack)->next)
	{
		perror("insuficentes nodos\n");
		return ;
	}
	first = *stack;
	*stack = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = first;
	first->next = NULL;
}

void	rotate_select(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL)
	{
		rotate(stack_b);
		ft_printf("rb\n");
	}
	else if (stack_b == NULL)
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
	else
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_printf("rr\n");
	}
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*pre_last;

	if (!(*stack) || !(*stack)->next)
	{
		perror("insuficentes nodos\n");
		return ;
	}
	pre_last = *stack;
	while (pre_last->next->next)
		pre_last = pre_last->next;
	last = ft_lstlast(*stack);
	last->next = *stack;
	*stack = last;
	pre_last->next = NULL;
}

void	reverse_select(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL)
	{
		reverse_rotate(stack_b);
		ft_printf("rrb\n");
	}
	else if (stack_b == NULL)
	{
		reverse_rotate(stack_a);
		ft_printf("rra\n");
	}
	else
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		ft_printf("rrr\n");
	}
}
