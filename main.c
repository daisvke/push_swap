/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:21:17 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/31 12:53:01 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_alloc()

int	ft_init_stack(char **args, s_stack *a, s_param *p, int size)
{
	s_stack	elem;
	int		i;

	i = 1;
	while (size--)
	{
		elem = ft_lstnew(arg[i]);
		elem = elem->nxt;
		i++;
	}
}

int	ft_check_arg()
{
	if (argc == 2)
}

int	main(int argc, char *argv[])
{
	s_stack	a;
	s_stack	b;
	s_param	p;

	ft_init_stacks(argv, &a, &p, argc);
}
