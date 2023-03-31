/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:23:01 by ablanco-          #+#    #+#             */
/*   Updated: 2023/03/31 17:40:01 by ablanco-         ###   ########.fr       */
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

void	swap_a(t_list **stack_a);