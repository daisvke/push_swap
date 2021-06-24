/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_long_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 21:52:57 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/24 03:37:57 by dtanigaw         ###   ########.fr       */
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
	int		next_lowest_limit;
	int		i;

	pushed_next_lowest = false;
	next_lowest = *nth_lowest + 1;
	next_lowest_limit = ft_stacksize(p->a_head) - 3;
	i = FIRST_POS;
	while (i != min_position)
	{
		if (p->a_head->data == next_lowest && next_lowest < next_lowest_limit)
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
	int		next_lowest_limit;

	pushed_next_lowest = false;
	last_position = ft_stacksize(p->a_head);
	next_lowest = *nth_lowest + 1;
	next_lowest_limit = last_position - 3;
	while (last_position != min_position - 1)
	{
		if (p->a_head->data == next_lowest && next_lowest < next_lowest_limit)
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

void    ft_execute_ra_until_reach_elem(t_param *p, int elem_pos, int elem)
{
	int	next_top;
	int	next_bottom;
	int	i;
	int	middle;

	next_top = elem + 1;
	next_bottom = elem - 1;
	i = FIRST_POS;
	middle = p->size / 2;
	while (i < elem_pos)
	{
		if (((p->a_head->data == next_top) \
			|| (p->a_head->data == next_bottom \
			&& next_bottom)))
		{
			ft_pb(p, p->a_head, p->b_head, true);
		}
		else
			ft_ra(p, p->a_head, ft_lastnode(p->a_head), true);
		++i;
	}
}

void    ft_execute_rra_until_reach_elem(t_param *p, int elem_pos, int elem)
{
	int	next_top;
	int	next_bottom;
	int	i;
	int	middle;

	next_top = elem + 1;
	next_bottom = elem - 1;
	i = ft_stacksize(p->a_head);
	middle = p->size / 2;
	while (i > elem_pos - 1)
	{
		if (((p->a_head->data == next_top) \
			|| (p->a_head->data == next_bottom \
			&& next_bottom)))
		{
			ft_pb(p, p->a_head, p->b_head, true);
		}
//	ft_printnode(p);
		ft_rra(p, p->a_head, ft_lastnode(p->a_head), true);
//	ft_printnode(p);
		--i;
	}
}

void	ft_execute_sb_or_rb_if_needed(t_param *p)
{
	t_stack	*head;
	t_stack	*second;
	int		top;
	int		next;

	if (ft_stacksize(p->b_head) > 1)
	{
		head = p->b_head;
		second = head->next;
		top = head->data;
		next = second->data;
		if (top == next - 1)
			ft_sb(p, head, second, true);
		while (p->b_head->data < ft_lastnode(p->b_head)->data)
			ft_rb(p, p->b_head, ft_lastnode(p->b_head), true);
	}
}

int	ft_find_node_position_by_its_value(t_param *p, int value)
{
	t_stack	*node;
	int		i;

	node = p->a_head;
	i = FIRST_POS;
	while (node)
	{
		if (node->data == value)
			break ;
		++i;
		node = node->next;
	}
	return (i);
}

void	ft_find_and_push_median_node_to_b(t_param *p)
{
	int	median_value;
	int	median_pos;

	median_value = ft_stacksize(p->a_head) / 2;
	median_pos = ft_find_node_position_by_its_value(p, median_value);
	if (ft_evaluate_fastest_op(p, median_pos) == RA)
		ft_execute_ra_until_reach_elem(p, median_pos, median_value);
	else if (ft_evaluate_fastest_op(p, median_pos) == RRA)
		ft_execute_rra_until_reach_elem(p, median_pos, median_value);
	ft_pb(p, p->a_head, p->b_head, true);
	ft_execute_sb_or_rb_if_needed(p);
}

int	ft_compute_closest_to_top(int stacksize, int next_top_pos, int next_bottom_pos)
{
	int	top_index;
	int	bottom_index;
	int	middle;
	int	closest_node_pos;

	middle = stacksize / 2;
	if (next_top_pos <= middle)
		top_index = next_top_pos - 1;
	else
		top_index = stacksize - next_top_pos + 1;
	if (next_bottom_pos <= middle)
		bottom_index = next_bottom_pos - 1;
	else
		bottom_index = stacksize - next_bottom_pos + 1;
	if (top_index <= bottom_index)
		closest_node_pos = next_top_pos;
	else
		closest_node_pos = next_bottom_pos;
	return (closest_node_pos);
}

int	ft_find_nearest_next_node_position(t_param *p)
{
	int	next_top;
	int	next_top_pos;
	int	next_bottom;
	int	next_bottom_pos;
	int	only_solution;

	next_top = 0;
	next_top_pos = 0;
	next_bottom = 0;
	next_bottom_pos = 0;
	only_solution = 0;
	if (p->b_head->data != p->size)
	{
		next_top = p->b_head->data + 1;
		next_top_pos = ft_find_node_position_by_its_value(p, next_top);
		only_solution = next_top_pos;
	}
	if (ft_lastnode(p->b_head)->data != 1)
	{
		next_bottom = ft_lastnode(p->b_head)->data - 1;
		
		next_bottom_pos = ft_find_node_position_by_its_value(p, next_bottom);
		only_solution = next_bottom_pos;
	}
	//printf("nt: %d, ntp: %d, nb: %d, nbp: %d\n", next_top, next_top_pos, next_bottom, next_bottom_pos);
	if (next_top && next_bottom)
		return (ft_compute_closest_to_top(ft_stacksize(p->a_head), next_top_pos, \
			next_bottom_pos));
	else
		return (only_solution);
}

void	ft_take_care_of_last_node_in_a(t_param *p)
{
	int	lastnode;
	int	middle;

	middle = ft_stacksize(p->a_head) / 2;
	lastnode = p->a_head->data;
	if (lastnode < middle)
	{
		ft_pb(p, p->a_head, p->b_head, true);
		ft_rb(p, p->b_head, ft_lastnode(p->b_head), true);
	}
}

void	ft_find_and_push_next_top_and_bottom(t_param *p)
{
	int		next_pos;
	int		next_value;

	while (p->a_head)
	{
		if (ft_stacksize(p->a_head) == 1)
		{
			ft_take_care_of_last_node_in_a(p);	
			break ;
		}
		next_pos = ft_find_nearest_next_node_position(p);
		next_value = ft_nth_node(p, next_pos)->data;
		if (ft_evaluate_fastest_op(p, next_pos) == RA)
			ft_execute_ra_until_reach_elem(p, next_pos, next_value);
		else if (ft_evaluate_fastest_op(p, next_pos) == RRA)
			ft_execute_rra_until_reach_elem(p, next_pos, next_value);
		ft_pb(p, p->a_head, p->b_head, true);
		ft_execute_sb_or_rb_if_needed(p);
	}
}

void	ft_execute_median_sort(t_param *p)
{
	if (p->disordered_position)
	{
		ft_find_and_push_median_node_to_b(p);
		ft_find_and_push_next_top_and_bottom(p);
		ft_push_back_from_b_to_a(p);
		p->disordered_position = ft_disordered(p, p->a_head, 0, p->size);
	}
}
