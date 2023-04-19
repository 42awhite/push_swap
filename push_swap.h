/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:23:01 by ablanco-          #+#    #+#             */
/*   Updated: 2023/04/19 18:11:35 by ablanco-         ###   ########.fr       */
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
	t_list	*stack_a;
	t_list	*stack_b;
}		t_push;

void	swap(t_list **stack_a);
void	swap_a_b(t_list **stack_a, t_list **stack_b);
void	ft_push(t_list **stack_out, t_list **stack_add, char c);
void	rotate(t_list **stack);
void	rotate_select(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack);
void	reverse_select(t_list **stack_a, t_list **stack_b);
void	add_idx(t_list **stack_a);
int		n_nod(t_list **stack_a);
void	org_few_n(t_list **stack_a, t_list **stack_b, int n_nods);
int		check_all_in_stack_b(t_list **stack_b, int n_nodos);
void	ft_all_btoa(t_list **stack_a, t_list **stack_b);
void	ft_radix(t_list **stack_a, t_list **stack_b, int n_nods);
void	str_is_n(char **num);
void	ft_n_comp(t_list **stack_a);
void	ft_n_to_nod(char **num, t_push *push);
void	three_n(t_list **stack_a);
void	n_less_ten(t_list **stack_a, t_list **stack_b, int n_total);
void	two_n(t_list **stack_a);

#endif
