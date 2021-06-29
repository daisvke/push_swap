/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 01:34:06 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/29 02:21:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		ft_execute_command(p, PA);
}

bool	ft_is_in_the_right_order(t_stack *node, int start, int end)
{
	int	size;
	int	st_tmp;

	if (!node)
		return (true);
	st_tmp = start;
	size = end - start - 1;
	while (node->next && start--)
		node = node->next;
	while (node->next && size--)
	{
		if (node->data > node->next->data)
			return (false);
		node = node->next;
	}
	return (true);
}

bool	ft_is_in_the_inverse_order(t_stack *node, int start, int end)
{
	int	size;
	int	st_tmp;

	if (!node)
		return (true);
	st_tmp = start;
	size = end - start - 1;
	while (node->next && start--)
		node = node->next;
	while (node->next && size--)
	{
		if (node->data < node->next->data)
			return (false);
		node = node->next;
	}
	return (true);
}
