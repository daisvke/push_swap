/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:21:17 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/07 02:01:03 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_init_stack(char **args, s_stack *a, s_param *p, int size)
{
	t_stack	elem;
	char	**joined;
	int		i;

	i = 1;
	while (size--)
	{
		joined = ft_split_errcheck(arg[i], ' ');
		j = 0;
		while (joined[j])
		{
			elem = ft_lstnew(arg[i]);
			if (!elem)
				
			elem = elem->nxt;
			j++;
		}
		i++;
	}

}

int	ft_check_arg()
{
	if (argc == 2)
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_param	p;

	if (ft_init_stacks(argv, &a, &p, argc) == ERROR)
	{
		ft_putstr("Error\n");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
