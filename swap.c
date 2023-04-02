/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:24:43 by ablanco-          #+#    #+#             */
/*   Updated: 2023/04/02 20:23:09 by ablanco-         ###   ########.fr       */
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
		ft_printf("pa");
	else if (c == 'b')
		ft_printf("pb");
}

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