/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_short_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:33:19 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/19 03:19:22 by dtanigaw         ###   ########.fr       */
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
	int		top;
	int		middle;

	head = p->a_head;
	top = head->data;
	middle = head->next->data;

	if (top > middle && top != 1 && middle != 3)
		ft_sa(p, head, head->next, true);
}

void	ft_reverse_rotate_when_three_elements(t_param *p)
{
	t_stack	*head;
	int		top;
	int		bottom;

	head = p->a_head;
	top = head->data;
	bottom = head->next->next->data;
	if ((top == 1 && bottom == 2) || (top == 2 && bottom == 1))
	{
		ft_rra(p, head, ft_lastnode(head), true);
	}
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
			|| (ft_islowest(p->a_head, p->a_head->data) \
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

