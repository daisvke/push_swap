/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:33:19 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/29 02:23:51 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_move_to_bottom_when_three_elements(t_param *p, int element)
{
	t_stack	*head;
	int		top;
	int		middle;

	head = NULL;
	head = p->a_head;
	top = head->data;
	middle = head->next->data;
	if (element == top)
		ft_execute_command(p, RA);
}

void	ft_swap_top_if_needed(t_param *p)
{
	t_stack	*head;
	t_stack	*body;
	int		top;
	int		middle;
	int		bottom;

	head = NULL;
	head = p->a_head;
	body = head->next;
	top = head->data;
	middle = body->data;
	bottom = body->next->data;
	if (top > middle && !ft_ishighest_in_stack(head, middle))
		ft_execute_command(p, SA);
}

void	ft_reverse_rotate_when_three_elements(t_param *p)
{
	t_stack	*head;
	int		top;
	int		middle;
	int		bottom;

	head = NULL;
	head = p->a_head;
	top = head->data;
	middle = head->next->data;
	bottom = head->next->next->data;
	if (top < middle && (middle > bottom))
		ft_execute_command(p, RRA);
}

void	ft_sort_three_elements(t_param *p)
{
	t_stack	*head;
	t_stack	*max;

	head = NULL;
	if (!ft_is_in_the_right_order(p->a_head, 0, p->size))
	{
		head = p->a_head;
		max = ft_find_node_with_highest_num(p);
		ft_move_to_bottom_when_three_elements(p, max->data);
		ft_reverse_rotate_when_three_elements(p);
		ft_swap_top_if_needed(p);
	}
}
