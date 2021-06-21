/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_short_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:33:19 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/21 13:35:09 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ft_isasc_between(t_param *p)
{
	return (ft_isasc(p->a_head, 1, ft_stacksize(p->a_head) - 1));
}

bool	ft_isdesc_between(t_param *p)
{
	return (ft_isdesc(p->a_head, 1, ft_stacksize(p->a_head) - 1));
}

bool	ft_islowest_xbef_lastnode(t_param *p, int i)
{
	return (ft_islowest_in_stack(p->a_head, ft_nth_node(p, ft_stacksize(p->a_head) - 1)->data));
}

void	ft_reverse(t_param *p)
{
	while (ft_isdesc(p->a_head, 0, ft_stacksize(p->a_head)) && p->size--)
		ft_ra(p, p->a_head, ft_lastnode(p->a_head), true);
}

void	ft_move_to_bottom_when_three_elements(t_param *p, int element, \
	int which_stack)
{
	t_stack	*head;
	int		top;
	int		middle;

	if (which_stack == A)
		head = p->a_head;
	else if (which_stack == B)
		head = p->b_head;
	top = head->data;
	middle = head->next->data;
	if (element == top)
	{
		if (which_stack == A)
			ft_ra(p, head, ft_lastnode(head), true);
		else if (which_stack == B)
			ft_rb(p, head, ft_lastnode(head), true);
	}
}

void	ft_swap_top_if_needed(t_param *p, int which_stack)
{
	t_stack	*head;
	t_stack	*body;
	int		top;
	int		middle;
	int		bottom;

	if (which_stack == A)
		head = p->a_head;
	else if (which_stack == B)
		head = p->b_head;
	body = head->next;
	top = head->data;
	middle = body->data;
	bottom = body->next->data;
	if (top > middle && !ft_islowest_in_stack(head, top)
		&& !ft_ishighest_in_stack(head, middle))
	{
		if (which_stack == A)
			ft_sa(p, head, body, true);
		else if (which_stack == B)
			ft_sb(p, head, body, true);
	}
}

void	ft_reverse_rotate_when_three_elements(t_param *p, int which_stack)
{
	t_stack	*head;
	int		top;
	int		middle;
	int		bottom;
	
	if (which_stack == A)
		head = p->a_head;
	else if (which_stack == B)
		head = p->b_head;
	top = head->data;
	middle = head->next->data;
	bottom = head->next->next->data;
	if (top < middle && (middle > bottom))
	{
		if (which_stack == A)
			ft_rra(p, head, ft_lastnode(head), true);
		else if (which_stack == B)
			ft_rrb(p, head, ft_lastnode(head), true);
	}
}

void	ft_sort_three_elements(t_param *p, int which_stack)
{
	t_stack	*head;
	t_stack	*max;

	if (p->disordered_position)
	{
		if (which_stack == A)
			head = p->a_head;
		else if (which_stack == B)
			head = p->b_head;
		max = ft_find_node_with_highest_num(p);
		ft_move_to_bottom_when_three_elements(p, max->data, which_stack);
		ft_reverse_rotate_when_three_elements(p, which_stack);
		ft_swap_top_if_needed(p, which_stack);
		p->disordered_position = ft_disordered(p, head, 0, p->size);
	}
}

int	ft_find_nth_lowest_node_position(t_param *p, int nth_lowest)
{
	t_stack	*node;
	int		i;

	node = p->a_head;
	i = FIRST_POSITION;
	while (node)
	{
		if (node->data == nth_lowest)
			break ;
		i++;
		node = node->next;
	}
	return (i);
}

int	ft_evaluate_fastest_op(t_param *p, int min_position)
{
	t_stack	*head;
	int		stacksize;
	int		middle;
	int		fastest_op;

	head = p->a_head;
	stacksize = ft_stacksize(head);
	middle = stacksize / 2;
	if (stacksize % 2 != 0)
		middle++;
	if (min_position <= middle)
		fastest_op = RA;
	else
		fastest_op = RRA;
	return (fastest_op);
}

void	ft_ra_until_reach_min(t_param *p, int min_position)
{
	int		i;

	i = FIRST_POSITION;
	while (i != min_position)
	{
		ft_ra(p, p->a_head, ft_lastnode(p->a_head), true);
		i++;
	}
}

void	ft_rra_until_reach_min(t_param *p, int min_position)
{
	int		i;
	int		last_position;

	last_position = ft_stacksize(p->a_head);
	while (last_position != min_position - 1)
	{
		ft_rra(p, p->a_head, ft_lastnode(p->a_head), true);
		last_position--;
	}
}

void	ft_find_lowest_nodes_and_push_to_b(t_param *p)
{
	int	min_position;
	int	num_of_lowest_nodes_to_push;
	int	nth_lowest;

	num_of_lowest_nodes_to_push = ft_stacksize(p->a_head) - 3;
	nth_lowest = 1;
	while (num_of_lowest_nodes_to_push--)
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

void	ft_sort_two_elements(t_param *p, int which_stack)
{
	t_stack	*head;
	int		top;
	int		bottom;

	if (p->disordered_position)
	{
		if (which_stack == A)
			head = p->a_head;
		else if (which_stack == B)
			head = p->b_head;
		top = head->data;
		bottom = head->next->data;
		if (top < bottom)
		{
			if (which_stack == A)
				ft_sa(p, head, p->a_head->next, true);
			else if (which_stack == B)
				ft_sb(p, head, p->a_head->next, true);
		}
		p->disordered_position = ft_disordered(p, head, 0, p->size);
	}
}

void	ft_push_back_from_b_to_a(t_param *p)
{
	while (p->b_head)
		ft_pa(p, p->a_head, p->b_head, true);
}

void	ft_sort_stack_b_with_short_list(t_param *p)
{
	int	stacksize;

	stacksize = ft_stacksize(p->b_head);
	if (stacksize == 2)
		ft_sort_two_elements(p, B);
	if (stacksize == 3)
		ft_sort_three_elements(p, B);
}

void	ft_sort_short_list(t_param *p)
{
	if (p->disordered_position)
	{
		ft_find_lowest_nodes_and_push_to_b(p);
		ft_sort_three_elements(p, A);
		ft_sort_stack_b_with_short_list(p);
		ft_push_back_from_b_to_a(p);
		p->disordered_position = ft_disordered(p, p->a_head, 0, p->size);
	}
}
