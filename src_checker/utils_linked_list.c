/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linked_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 23:42:41 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/07/01 00:06:54 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lastnode(t_stack *node)
{
	if (node)
		while (node->next)
			node = node->next;
	return (node);
}

t_stack	*ft_second_to_lastnode(t_param *p, int which_stack)
{
	t_stack	*node;
	int		size;

	if (which_stack == A)
		node = p->a_head;
	else
		node = p->b_head;
	size = ft_stacksize(node) - 2;
	if (node)
		while (node->next && size--)
			node = node->next;
	return (node);
}

void	ft_add_front(t_stack *head, t_stack *new)
{
	if (new)
	{
		new->next = head;
		head = new;
	}
}

void	ft_add_back(t_stack *head, t_stack *new)
{
	t_stack	*node;

	if (!head || !new)
		return ;
	if (!head)
		head = new;
	else
	{
		node = ft_lastnode(head);
		node->next = new;
	}
}

int	ft_stacksize(t_stack *node)
{
	int	i;

	i = 0;
	while (node)
	{
		node = node->next;
		++i;
	}
	return (i);
}
