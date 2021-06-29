/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lowests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 21:52:57 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/29 02:14:17 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ft_isthere(int nbr_to_find, int *array_of_nbrs, int array_size)
{
	int	i;

	i = 0;
	while (i < array_size)
	{
		if (array_of_nbrs[i] == nbr_to_find)
			return (true);
		++i;
	}
	return (false);
}

bool	ft_ra_until_reach_min_for_long_list(t_param *p, int min_position, \
	int *nth_lowest)
{
	bool	pushed_next_lowest;
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
			ft_execute_command(p, PB); 
		}
		else
			ft_execute_command(p, RA);
		++i;
	}
	return (pushed_next_lowest);
}

bool	ft_rra_until_reach_min_for_long_list(t_param *p, int min_position, \
	int *nth_lowest)
{
	bool	pushed_next_lowest;
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
			ft_execute_command(p, PB);
		}
		ft_execute_command(p, RRA);
		--last_position;
	}
	return (pushed_next_lowest);
}

void	ft_find_lowest_nodes_in_long_list_and_push_to_b(t_param *p)
{
	bool	pushed_next_lowest;
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
		ft_execute_command(p, PB);
		if (pushed_next_lowest)
		{
			if (p->b_head->data < p->b_head->next->data)
				ft_execute_command(p, SB);
			++nth_lowest;
		}
		++nth_lowest;
	}
}

void	ft_execute_lowests_sort(t_param *p)
{
	if (!ft_is_in_the_right_order(p->a_head, 0, p->size))
	{
		ft_find_lowest_nodes_in_long_list_and_push_to_b(p);
		ft_sort_three_elements(p);
		ft_push_back_from_b_to_a(p);
	}
}
