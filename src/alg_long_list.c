/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_long_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 21:52:57 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/11 01:12:44 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*ft_lowest_nodes(t_param *p)
{
	t_stack	*node;
	int		*t;
	int		size;
	int		i;

	i = 0;
	size = p->size / 2;
	t = malloc(size * sizeof(*t));
	node = p->a_head;
	while (node && i != size)
	{
		if (ft_islowest_expt(p->a_head, node->data, t))
		{
			t[i] = node->data;
			i++;
		}
		node = node->next;
	}
	return (t);
}

bool	ft_isthere(int n, int *t)
{
	while (*t)
	{
		if (n == *t)
			return (true);
		t++;
	}
	return (false);
}

void	ft_sort_long_list(t_param *p, int *t)
{
	t_stack	*node;
	
	printf(">>>>BEGIN SORT LONG LIST<<<<\n");

	node = p->a_head;
	while (node)
	{
		while (ft_isthere(node->data, t))
			ft_pb(p, node, p->b_head, true);
		while (!ft_isthere(node->data, t))
			ft_ra(p, node, ft_lastnode(node), true);
		
		node = node->next;
	}
}
