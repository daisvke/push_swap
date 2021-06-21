/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_long_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 21:52:57 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/21 14:07:53 by dtanigaw         ###   ########.fr       */
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

bool    ft_ra_until_reach_min_for_long_list(t_param *p, int min_position, \
	int *nth_lowest)
{
	bool    pushed_next_lowest;
	int		next_lowest;
	int		i;

	pushed_next_lowest = false;
	next_lowest = *nth_lowest + 1;
	i = FIRST_POSITION;
	while (i != min_position)
	{
		if (p->a_head->data == next_lowest)
		{
				pushed_next_lowest = true;
				ft_pb(p, p->a_head, p->b_head, true);
		}
		else
			ft_ra(p, p->a_head, ft_lastnode(p->a_head), true);
		i++;
	}
	return (pushed_next_lowest);
}

bool    ft_rra_until_reach_min_for_long_list(t_param *p, int min_position, \
	int *nth_lowest)
{
	bool    pushed_next_lowest;
	int		last_position;
	int		next_lowest;

	pushed_next_lowest = false;
	last_position = ft_stacksize(p->a_head);
	next_lowest = *nth_lowest + 1;
	while (last_position != min_position - 1)
	{
		if (p->a_head->data == next_lowest)
		{
			pushed_next_lowest = true;
			ft_pb(p, p->a_head, p->b_head, true);
		}
		ft_rra(p, p->a_head, ft_lastnode(p->a_head), true);
		last_position--;
	}
	return (pushed_next_lowest);
}

void	ft_find_lowest_nodes_in_long_list_and_push_to_b(t_param *p)
{
	bool    pushed_next_lowest;
	int		min_position;
	int		nth_lowest;

	nth_lowest = 1;
	while (ft_stacksize(p->a_head) > 3)
	{
		min_position = ft_find_nth_lowest_node_position(p, nth_lowest);
		if (ft_evaluate_fastest_op(p, min_position) == RA)
			pushed_next_lowest = ft_ra_until_reach_min_for_long_list(p, \
				min_position, &nth_lowest);
		else if (ft_evaluate_fastest_op(p, min_position) == RRA)
			pushed_next_lowest = ft_rra_until_reach_min_for_long_list(p, \
				min_position, &nth_lowest);
		ft_pb(p, p->a_head, p->b_head, true);
		if (pushed_next_lowest)
		{
			if (p->b_head->data < p->b_head->next->data)
				ft_sb(p, p->b_head, p->b_head->next, true);
			nth_lowest++;
		}
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
