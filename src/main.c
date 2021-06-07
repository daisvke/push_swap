/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:21:17 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/07 15:16:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	printlst(t_param *p)
{
	t_stack	*elem;

	if (!p)
		printf("EMPTY\n");
	elem = p->a_first;
	while (elem)
	{
		printf("%d -> ", elem->data);
		elem = elem->next;
	}
	printf("NULL\n");
}

t_param	*ft_init(int n)
{
	t_param	*p;
	t_stack	*elem;
	t_stack	*next;

	p = malloc(sizeof(*p));
	elem = malloc(sizeof(*elem));
	next = malloc(sizeof(*next));
	if (!p || !elem)
		ft_exit_failure();
	elem->data = n;
	p->a_first = elem;
	p->a_first->next = next;
	return (p);
}

t_stack	*ft_add_nbr(int data)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_init_stack(char **args, int size)
{
	t_param	*p;
	t_stack	*elem;
	char	**split;
	int		i;
	int		j;

	elem = NULL;
	split = ft_split_errchk(args[1], ' ');
	p = ft_init(ft_atoi(split[0]));
	p->a_first->next = elem;

	j = 2;
	while (split[j])
	{
		elem = ft_add_nbr(ft_atoi(split[j]));
		if (!elem)
			ft_exit_lst_tabfree(p, split, j);	
		elem = elem->next;
		j++;
	}
	i = 2;
	while (size--)
	{
		split = ft_split_errchk(args[i], ' ');
		j = 0;
		while (split[j])
		{
			elem = ft_add_nbr(ft_atoi(split[j]));
			if (!elem)
				ft_exit_lst_tabfree(p, split, j);	
			elem = elem->next;
			j++;
		}
		i++;
	}
	printlst(p);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		ft_exit_failure();
	ft_init_stack(argv, argc - 1);
//	printf("first: %d\n", p.a_first->data);
	return (EXIT_SUCCESS);
}
