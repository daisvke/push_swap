/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:21:17 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/07 05:49:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_add_nbr(int data)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->data = data;
	new->nxt = NULL;
	return (new);
}

void	ft_init_stack(char **args, t_stack *a, t_param *p, int size)
{
	t_stack	*elem;
	char	**split;
	int		i;
	int		j;

	i = 1;
	split = ft_split_errcheck(args[i], ' ');
	a = ft_add_nbr(ft_atoi(split[0]));
	p->a_start = &a;
	elem = a;
	elem = a->nxt;
		j = 1;
		while (split[j])
		{
			elem = ft_add_nbr(ft_atoi(split[j]));
			if (!elem)
				ft_exit_lst_tabfree(p, split, j);	
			elem = elem->nxt;
			j++;
		}
	i = 2;
	while (size--)
	{
		split = ft_split_errcheck(args[i], ' ');
		j = 0;
		while (split[j])
		{
//	printf("split: %s", split[j]);
			elem = ft_add_nbr(ft_atoi(split[j]));
	printf("start: %d\n", (*p->a_start)->data);
			if (!elem)
				ft_exit_lst_tabfree(p, split, j);	
			elem = elem->nxt;
			j++;
		}
		i++;
	}
	printf("lst: %d\n", a->nxt->data);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_param	p;

	if (argc < 2)
		ft_exit_failure();
	ft_init_stack(argv, &a, &p, argc - 1);
//	printf("first: %d\n", p.a_start->data);
	return (EXIT_SUCCESS);
}
