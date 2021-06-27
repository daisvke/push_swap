/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_short_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:33:19 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/27 11:31:17 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_move_to_bottom_when_three_elements(t_param *p, int element, \
	int which_stack)
{
	t_stack	*head;
	int		top;
	int		middle;

	head = NULL;
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

	head = NULL;
	if (which_stack == A)
		head = p->a_head;
	else if (which_stack == B)
		head = p->b_head;
	body = head->next;
	top = head->data;
	middle = body->data;
	bottom = body->next->data;
	if (top > middle && !ft_islowest_in_stack(head, top) // remove ?
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
	
	head = NULL;
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

	head = NULL;
	if (!ft_is_in_the_right_order(p->a_head, 0, p->size))
	{
		if (which_stack == A)
			head = p->a_head;
		else if (which_stack == B)
			head = p->b_head;
		max = ft_find_node_with_highest_num(p);
		ft_move_to_bottom_when_three_elements(p, max->data, which_stack);
		ft_reverse_rotate_when_three_elements(p, which_stack);
		ft_swap_top_if_needed(p, which_stack);
	}
}

int	ft_find_nth_lowest_node_position(t_param *p, int nth_lowest)
{
	t_stack	*node;
	int		i;

	node = p->a_head;
	i = FIRST_POS;
	while (node)
	{
		if (node->data == nth_lowest)
			break ;
		i++;
		node = node->next;
	}
	return (i);
}

int	ft_evaluate_fastest_op(t_param *p, int elem_pos)
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
	if (elem_pos <= middle)
		fastest_op = RA;
	else
		fastest_op = RRA;
	return (fastest_op);
}

void	ft_push_back_from_b_to_a(t_param *p)
{
	while (p->b_head)
		ft_pa(p, p->a_head, p->b_head, true);
}
