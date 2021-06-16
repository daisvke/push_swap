/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:26:58 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/15 14:23:47 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_param *p, t_stack *node1, t_stack *node2, bool w)
{
	t_stack	*tmp;

	if (node1 && node2)
	{
		tmp = node1;
		node1->next = node2->next;
		node2->next = tmp;
		p->a_head = node2;
	}
	if (w)
		write(1, "sa\n", 3);
	p->lastmove = 1;
}

void	ft_sb(t_param *p, t_stack *node1, t_stack *node2, bool w)
{
	t_stack	*tmp;

	if (node1 && node2)
	{
		tmp = node1;
		node1->next = node2->next;
		node2->next = tmp;
		p->b_head = node2;
	}
	if (w)
		write(1, "sb\n", 3);
	p->lastmove = 2;
}

void	ft_ss(t_param *p, t_stack *a1, t_stack *a2, t_stack *b1, t_stack *b2)
{
	ft_sa(p, a1, a2, false);
	ft_sb(p, b1, b2, false);
	write(1, "ss\n", 3);
	p->lastmove = 3;
}
