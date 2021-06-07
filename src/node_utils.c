/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 23:42:41 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/08 00:23:26 by root             ###   ########.fr       */
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

t_stack	*ft_stacklast(t_stack *node)
{
	if (node)
		while (node->next)
			node = node->next;
	return (node);
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
		node = ft_stacklast(*head);
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
