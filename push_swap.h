/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:23:01 by ablanco-          #+#    #+#             */
/*   Updated: 2023/04/02 20:23:42 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"

typedef struct s_in_nd
{
	int		n;
	int		idx;
}	t_in_nd;

typedef struct s_push
{
	//t_list	*list; //cambiar el aux por los stacks;
	t_list	*stack_a;
	t_list 	*stack_b;
}		t_push;
#endif

void	swap(t_list **stack_a);
void	swap_a_b(t_list **stack_a, t_list **stack_b);
void	ft_push(t_list **stack_out, t_list **stack_add, char c);
void	rotate(t_list **stack);
void	rotate_select(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack);
void	reverse_select(t_list **stack_a, t_list **stack_b);
