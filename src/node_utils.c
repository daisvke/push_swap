/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 23:42:41 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/08 14:54:56 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_add_nbr(int data)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

t_stack	*ft_lastnode(t_stack *node)
{
	if (node)
		while (node->next)
			node = node->next;
	return (node);
}

t_stack	*ft_xbef_lastnode(t_param *p, t_stack *node, int i)
{
	int	size;

	size = p->size - i - 1;
	if (size == 0 || i == 0)
		return (node);
	if (node && i)
		while (node->next && size--)
			node = node->next;
	return (node);
}

void	ft_add_front(t_stack **head, t_stack *new)
{
	t_stack	*node;

	if (*head && new)
	{
		new->next = *head;
		*head = new;
	}
}

void	ft_add_back(t_stack **head, t_stack *new)
{
	t_stack	*node;

	if (!head || !new)
		return ;
	if (!*head)
		*head = new;
	else
	{
		node = ft_lastnode(*head);
		node->next = new;
	}
}

int	ft_stacksize(t_stack *node)
{
	int		i;

	i = 0;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}
