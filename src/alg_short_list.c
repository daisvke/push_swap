/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_short_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:33:19 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/19 05:29:28 by dtanigaw         ###   ########.fr       */
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
	return (ft_islowest(ft_nth_node(p, ft_stacksize(p->a_head) - 1)));
}

void	ft_reverse(t_param *p)
{
	while (ft_isdesc(p->a_head, 0, ft_stacksize(p->a_head)) && p->size--)
		ft_ra(p, p->a_head, ft_lastnode(p->a_head), true);
}

void	ft_move_to_bottom_when_three_elements(t_param *p, int element)
{
	t_stack	*head;
	int		top;
	int		middle;

	head = p->a_head;
	top = head->data;
	middle = head->next->data;
	if (element == top)
		ft_ra(p, head, ft_lastnode(head), true);
}

void	ft_swap_top_if_needed(t_param *p)
{
	t_stack	*head;
	t_stack	*body;
	int		top;
	int		middle;
	int		bottom;

	head = p->a_head;
	body = head->next;
	top = head->data;
	middle = body->data;
	bottom = body->next->data;
	if (top > middle && !ft_islowest(head) && !ft_ishighest(body, 3))
		ft_sa(p, head, body, true);
}

void	ft_reverse_rotate_when_three_elements(t_param *p)
{
	t_stack	*head;
	int		top;
	int		middle;
	int		bottom;

	head = p->a_head;
	top = head->data;
	middle = head->next->data;
	bottom = head->next->next->data;
	if (top < middle && (middle > bottom))
		ft_rra(p, head, ft_lastnode(head), true);
}

void	ft_sort_three_elements(t_param *p, int *disordered_position)
{
	t_stack	*head;
	t_stack	*max;

	if (*disordered_position)
	{
		head = p->a_head;
		max = ft_find_node_with_highest_num(p);
		ft_move_to_bottom_when_three_elements(p, max->data);
		ft_reverse_rotate_when_three_elements(p);
		ft_swap_top_if_needed(p);
		*disordered_position = ft_disordered(p, head, 0, p->size);
	}
}

int	ft_find_min_position(t_param *p)
{
	t_stack	*node;
	int		i;

	node = p->a_head;
	i = FIRST_POSITION;
	while (node)
	{
		if (node->data == 1)
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
	t_stack	*node;
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
	t_stack	*node;
	int		i;
	int		last_position;

	last_position = ft_stacksize(p->a_head);
	i = last_position;
		while (i != min_position - 1)
	{
		ft_rra(p, p->a_head, ft_lastnode(p->a_head), true);
		i--;
	}
}

void	ft_sort_four_elements(t_param *p, int *disordered_position)
{
	int		min_position;

	if (*disordered_position)
	{
		min_position = ft_find_min_position(p);
		if (ft_evaluate_fastest_op(p, min_position) == RA)
			ft_ra_until_reach_min(p, min_position);
		else if (ft_evaluate_fastest_op(p, min_position) == RRA)
			ft_rra_until_reach_min(p, min_position);
		ft_pb(p, p->a_head, p->b_head, true);
		ft_sort_three_elements(p, disordered_position);
		ft_pa(p, p->a_head, p->b_head, true);
		*disordered_position = ft_disordered(p, p->a_head, 0, p->size);
	}
}

void	ft_sort_five_elements(t_param *p, int *disordered_position)
{
	if (*disordered_position)
	{
	/*	int	fourth_node_num;

		fourth_node_num = ft_nth_node(p, 4)->data;
		if (fourth_node_num == 5)
		{
			ft_pb(p, p->a_head, p->b_head, true);
				
		}
		else*/
		if	(p->lastmove != 1
			&& (p->a_head->data < p->a_head->next->data
			&& ft_ishighest(p->a_head, p->a_head->next->data)
			&& !ft_ishighest(p->a_head->next->next, p->a_head->next->next->data)))
			ft_sa(p, p->a_head, p->a_head->next, true);
		*disordered_position = ft_disordered(p, p->a_head, 0, p->size);
	}
}

void	ft_sort_short_list(t_param *p, int *disordered_position)
{
	int	tmp;
	
	if (*disordered_position || p->b_head)
	{
		if (p->a_head->data > p->a_head->next->data)
		{
			if (p->lastmove != 1
				&& (p->a_head->data < ft_lastnode(p->a_head)->data \
				|| !(p->a_head->next->next)))
				ft_sa(p, p->a_head, p->a_head->next, true);
			else if (p->lastmove != 9
				&& (!ft_isasc(p->a_head, 1, ft_stacksize(p->a_head)) \
				|| (ft_ishighest(p->a_head, p->a_head->data) \
				&& ft_isasc(p->a_head, 1, ft_stacksize(p->a_head) - 1)) \
				|| (ft_ishighest(p->a_head, p->a_head->data)
				&& ft_isdesc_between(p))))
				ft_ra(p, p->a_head, ft_lastnode(p->a_head), true);
		}
		else if (p->lastmove != 6
			&& (((!ft_isasc(p->a_head, 0, \
			ft_stacksize(p->a_head) - 1) \
			&& ft_lastnode(p->a_head)->data < p->a_head->data)) \
			|| (ft_islowest_xbef_lastnode(p, 0)) \
			|| (!ft_isasc_between(p) && ft_ishighest(p->a_head, p->a_head->data) \
			&& ft_islowest_xbef_lastnode(p, 1))))
			ft_rra(p, p->a_head, ft_lastnode(p->a_head), true);
		else if (((p->b_head && p->b_head->next) || !p->b_head) \
			&& (*disordered_position > p->size / 2 \
			|| (ft_islowest(p->a_head) \
			&& ft_ishighest(p->a_head, ft_lastnode(p->a_head)->data) \
			&& ft_stacksize(p->a_head) > 3)))
		{
			tmp = *disordered_position - 1;
			if (tmp < 0)
				tmp = 0;
			while (tmp--)
				ft_pb(p, p->a_head, p->b_head, true);
		}
		else if (p->b_head && p->lastmove != 5)
			ft_pa(p, p->a_head, p->b_head, true);
		*disordered_position = ft_disordered(p, p->a_head, 0, p->size);
	}
}

