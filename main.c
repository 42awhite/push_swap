/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:40:21 by ablanco-          #+#    #+#             */
/*   Updated: 2023/04/08 22:45:07 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_split_n(char *str)
{
	char	**n;

	n = ft_split(str, ' ');
	return (n);
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

void	call_ft(char **n, t_push push)
{
	int	n_nods;

	ft_n_comp(n);
	str_is_n(n);
	if (n == NULL)
	{
		perror("error");
		exit(-1);
	}
	ft_n_to_nod(n, &push);
	add_idx(&push.stack_a);
	n_nods = n_nod(&push.stack_a);
	if (n_nods <= 60)
	{
		org_few_n(&push.stack_a, &push.stack_b, n_nods);
		ft_all_btoa(&push.stack_a, &push.stack_b);
	}
	else
		ft_radix(&push.stack_a, &push.stack_b, n_nods);
}

int	main(int argc, char **argv)
{
	char	**n;
	char	*n_join;
	t_push	push;
	int		cont;

	(void)argc;
	ft_bzero(&push, sizeof(t_push));
	n_join = ft_strdup(argv[1]);
	cont = 2;
	while (argv[cont])
	{
		n_join = join_argv(n_join, argv[cont]);
		cont++;
	}
	n = ft_split_n(n_join);
	call_ft(n, push);
}
