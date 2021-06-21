/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_long_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 21:52:57 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/21 01:08:00 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*ft_lowest_nodes(t_param *p)
{
	t_stack	*node;
	int		*t;
	int		size;
	int		i;

	i = 0;
	size = p->size / 2;
	t = malloc(size * sizeof(*t));
	node = p->a_head;
	while (node && i != size)
	{
		if (ft_islowest_expt(p->a_head, node->data, t))
		{
			t[i] = node->data;
			i++;
		}
		node = node->next;
	}
	return (t);
}

bool	ft_isthere(int nbr_to_find, int *array_of_nbrs, int array_size)
{
	int	i;

	i = 0;
	while (i < array_size)
	{
		if (array_of_nbrs[i] == nbr_to_find)
			return (true);
		i++;
	}
	return (false);
}

void	ft_find_lowest_nodes_in_long_list_and_push_to_b(t_param *p)
{
	int	min_position;
	int	nth_lowest;

	nth_lowest = 1;
	while (ft_stacksize(p->a_head) > 3)
	{
		min_position = ft_find_nth_lowest_node_position(p, nth_lowest);
		if (ft_evaluate_fastest_op(p, min_position) == RA)
			ft_ra_until_reach_min(p, min_position);
		else if (ft_evaluate_fastest_op(p, min_position) == RRA)
			ft_rra_until_reach_min(p, min_position);
		ft_pb(p, p->a_head, p->b_head, true);
		nth_lowest++;
	}
}

void	ft_sort_long_list(t_param *p)
{
	if (p->disordered_position)
	{
		ft_find_lowest_nodes_in_long_list_and_push_to_b(p);
		ft_sort_three_elements(p, A);
		ft_push_back_from_b_to_a(p);
		p->disordered_position = ft_disordered(p, p->a_head, 0, p->size);
	}
}
