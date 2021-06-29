/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:28:18 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/29 02:14:17 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_execute_ra(t_param *p, t_stack *head, t_stack *tail, \
	bool print_command)
{
	t_stack	*tmp;

	if (head && tail)
	{
		tmp = head->next;
		head->next = NULL;
		tail->next = head;
		p->a_head = tmp;
		if (print_command)
			write(1, "ra\n", 3);
	}
}

void	ft_execute_rb(t_param *p, t_stack *head, t_stack *tail, \
	bool print_command)
{
	t_stack	*tmp;

	if (head && tail)
	{
		tmp = head->next;
		head->next = NULL;
		tail->next = head;
		p->b_head = tmp;
		if (print_command)
			write(1, "rb\n", 3);
	}
}

void	ft_execute_rra(t_param *p, t_stack *head, t_stack *tail, \
	bool print_command)
{
	t_stack	*tmp;

	if (head && tail)
	{
		tmp = ft_second_to_lastnode(p, A);
		tail->next = head;
		tmp->next = NULL;
		p->a_head = tail;
		if (print_command)
			write(1, "rra\n", 4);
	}
}

void	ft_execute_rrb(t_param *p, t_stack *head, t_stack *tail, \
	bool print_command)
{
	t_stack	*tmp;

	if (head && tail)
	{
		tmp = ft_second_to_lastnode(p, B);
		tail->next = head;
		tmp->next = NULL;
		p->b_head = tail;
		if (print_command)
			write(1, "rrb\n", 4);
	}
}
