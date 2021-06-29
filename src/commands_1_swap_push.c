/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1_swap_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:27:15 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/29 01:32:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_execute_sa(t_param *p, t_stack *node1, t_stack *node2, bool print_command)
{
	t_stack	*tmp;

	if (node1 && node2)
	{
		tmp = node1;
		node1->next = node2->next;
		node2->next = tmp;
		p->a_head = node2;
		if (print_command)
			write(1, "sa\n", 3);
	}
}

void	ft_execute_sb(t_param *p, t_stack *node1, t_stack *node2, bool print_command)
{
	t_stack	*tmp;

	if (node1 && node2)
	{
		tmp = node1;
		node1->next = node2->next;
		node2->next = tmp;
		p->b_head = node2;
		if (print_command)
			write(1, "sb\n", 3);
	}
}

void	ft_execute_pa(t_param *p, t_stack *a, t_stack *b, bool print_command)
{
	t_stack	*tmp;
	
	if (b)
	{
		tmp = b->next;
		ft_add_front(a, b);
		p->b_head = tmp;
		p->a_head = b;
		if (print_command)
			write(1, "pa\n", 3);
	}
}

void	ft_execute_pb(t_param *p, t_stack *a, t_stack *b, bool print_command)
{
	t_stack	*tmp;

	if (a)
	{
		tmp = a->next;
		ft_add_front(b, a);
		p->a_head = tmp;
		p->b_head = a;
		if (print_command)
			write(1, "pb\n", 3);
	}
}
