/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:40:21 by ablanco-          #+#    #+#             */
/*   Updated: 2023/04/02 20:24:51 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_split_n(char *str)
{
	char	**n;

	n = ft_split(str, ' ');
	return (n);
}

void	fnc(void *par) //Función para print el interor del nodo
{
	t_in_nd *lst = par;
	printf("%d\n", lst->n);
}

void	ft_n_comp(char **num)
{
	int	cont;
	int	cont2;

	cont = 0;
	while (num[cont])
	{
		cont2 = cont + 1;
		while (num[cont2])
		{
			if (ft_strncmp(num[cont], num[cont2]) == 0)
			{
				perror("n iguales");
				exit(-1);
			}
			cont2++;
		}
		cont++;
	}
}

void	str_is_n(char **num)
{
	int	cont;
	int	cont2;

	cont = 0;
	cont2 = 0;
	while (num[cont])
	{
		while (num[cont][cont2])
		{
			if ((num[cont][cont2] < '0' || num[cont][cont2] > '9') && (num[cont][cont2] != '\0'))
			{
				perror("no n");
				exit(-1);
			}
			cont2++;
		}
		cont2 = 0;
		cont++;
	}
}

void	ft_n_to_nod(char **num, t_push *push)
{
	int			cont;
	t_in_nd		*pt;
	t_list		*aux;

	cont = 0;
	while (num[cont])
	{
		pt = ft_calloc(1, sizeof(t_in_nd));
		if (pt == NULL)
			exit (-1);
		pt->n = ft_atoi(num[cont]);
		aux = ft_lstnew(pt);
		ft_lstadd_back(&push->stack_a, aux);
		cont++;
	}
//	ft_lstiter(push->stack_a, &fnc);
}

//Usar strdup con un argv1
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
//Hacer una estructura con el contenido del nodo, que va a ser
//int, indice = posición del numero en la lista de menor a mayor

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

	//push.stack_b = NULL;
	//push.stack_b = ft_lstnew(NULL);
	while (argv[cont])
	{
		n_join = join_argv(n_join, argv[cont]);
		cont++;
	}
	//printf("%s\n", n_join);
	n = ft_split_n(n_join);
//	free(n_join);
	ft_n_comp(n);
	str_is_n(n);
	if (n == NULL)
	{
		perror("error");
		exit(-1);
	}
	ft_n_to_nod(n, &push);

	//swap_a_b(&push.stack_a, &push.stack_b);
	ft_push(&push.stack_a, &push.stack_b, 'b');
	ft_push(&push.stack_a, &push.stack_b, 'b');
	ft_push(&push.stack_a, &push.stack_b, 'b');
	printf("STACK A: \n");
	ft_lstiter(push.stack_a, &fnc);
	printf("STACK B: \n");
	ft_lstiter(push.stack_b, &fnc);
	reverse_select(&push.stack_a, &push.stack_b);
	printf("/////////DESPUES DEL REVERSE /////////\n");
	printf("STACK A: \n");
	ft_lstiter(push.stack_a, &fnc);
	printf("STACK B: \n");
	ft_lstiter(push.stack_b, &fnc);
//	system("leaks -q push_swap");
	//printf("%d", *(int *)(node->content));
}
