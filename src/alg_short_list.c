/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_short_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:33:19 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/18 14:50:39 by dtanigaw         ###   ########.fr       */
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
	return (ft_islowest(p->a_head, \
		ft_xbef_lastnode(p, ft_stacksize(p->a_head), p->a_head, i)->data));
}

void	ft_reverse(t_param *p)
{
	while (ft_isdesc(p->a_head, 0, ft_stacksize(p->a_head)) && p->size--)
		ft_ra(p, p->a_head, ft_lastnode(p->a_head), true);
}

void	ft_move_to_bottom_when_three_elements(t_stack *node, int element)
{
	const int	top;
	const int	middle;

	top = node->data;
	middle = node->next->data;

	if (element == top)
		ft_ra(p, node, ft_lastnode(p->a_head)o, true);
}

void	ft_sort_three_elements(t_param *p)
{
	t_stack	*node;
	t_stack	*max;

	node = p->a_head;
	max = ft_find_node_with_highest_num(node); 
	ft_move_to_bottom_when_three_elements(node, max->data);
	swap_top_if_needed(node);
}

void	ft_sort_five_elements(t_param *p)
{
	t_stack	*fourth_node_num;

	fourth_node_num = ft_nth_node(p, 4)->data;
	if (fourth_node_num != 5)
	{
		
	}
	else (p->lastmove != 1
		&& (p->a_head->data < p->a_head->next->data
		&& ft_ishighest(p->a_head, p->a_head->next->data)
		&& !ft_ishighest(p->a_head->next->next, p->a_head->next->next->data)))
		ft_sa(p, p->a_head, p->a_head->next, true);
}

void	ft_sort_short_list(t_param *p, int pos, int tmp)
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
		&& (pos > p->size / 2 \
		|| (ft_islowest(p->a_head, p->a_head->data) \
		&& ft_ishighest(p->a_head, ft_lastnode(p->a_head)->data) \
		&& ft_stacksize(p->a_head) > 3)))
	{
		tmp = pos - 1;
		if (tmp < 0)
			tmp = 0;
		while (tmp--)
			ft_pb(p, p->a_head, p->b_head, true);
	}
	else if (p->b_head && p->lastmove != 5)
		ft_pa(p, p->a_head, p->b_head, true);
}

