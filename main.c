/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:40:21 by ablanco-          #+#    #+#             */
/*   Updated: 2023/04/21 17:32:47 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	all_order(t_list **stack_a)
{
	t_list	*idx;
	int		cont;

	idx = *stack_a;
	cont = 1;
	while (idx)
	{
		if (((t_in_nd *)idx->content)->idx != cont)
		{
			return ;
		}
		idx = idx->next;
		cont++;
	}
	exit (1);
}

char	*join_argv(char *old_str, char *to_join)
{
	char	*aux;
	char	*space;

	space = ft_strjoin(old_str, " ");
	aux = ft_strjoin(space, to_join);
	free(old_str);
	free(space);
	return (aux);
}

static void	call_ft(char **n, t_push *push, int n_nods)
{
	str_is_n(n);
	if (n == NULL)
	{
		perror("error");
		exit(-1);
	}
	ft_n_to_nod(n, push);
	ft_n_comp(&push->stack_a);
	add_idx(&push->stack_a);
	all_order(&push->stack_a);
	n_nods = n_nod(&push->stack_a);
	if (n_nods == 2)
		two_n(&push->stack_a);
	else if (n_nods < 10 && n_nods > 2)
	{
		n_less_ten(&push->stack_a, &push->stack_b, n_nods);
	}
	else if (n_nods <= 60 && n_nods >= 10)
	{
		org_few_n(&push->stack_a, &push->stack_b, n_nods);
		ft_all_btoa(&push->stack_a, &push->stack_b);
	}
	else
		ft_radix(&push->stack_a, &push->stack_b, n_nods);
}

int	main(int argc, char **argv)
{
	char	**n;
	char	*n_join;
	t_push	push;
	int		cont;

	if (argc == 1)
		return (0);
	ft_bzero(&push, sizeof(t_push));
	n_join = ft_strdup(argv[1]);
	cont = 2;
	while (argv[cont])
	{
		n_join = join_argv(n_join, argv[cont]);
		cont++;
	}
	n = ft_split(n_join, ' ');
	call_ft(n, &push, 0);
}
