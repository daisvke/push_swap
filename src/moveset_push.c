/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:27:15 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/24 01:25:18 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_param *p, t_stack *a, t_stack *b, bool w)
{
	t_stack	*tmp;
	
	if (b)
	{
		tmp = b->next;
		ft_add_front(a, b);
		p->b_head = tmp;
		p->a_head = b;
		if (w)
			write(1, "pa\n", 3);
	}
}

void	ft_pb(t_param *p, t_stack *a, t_stack *b, bool w)
{
	t_stack	*tmp;

	if (a)
	{
		tmp = a->next;
		ft_add_front(b, a);
		p->a_head = tmp;
		p->b_head = a;
		if (w)
			write(1, "pb\n", 3);
	}
}

void	ft_execute_command(t_param *p, int command)
{
	if (command == PA)
		ft_pa(p, p->a_head, p-b_>head, true);
	if (command == PB)
		ft_pb(p, p->a_head, p-b_>head, true);
	if (command == SA)
		ft_sa(p, p->a_head, p->a_head->next, true);
	if (command == SB)
		ft_sb(p, p->b_head, p->b_head->next, true);
	if (command == RA)
		ft_ra(p, p->a_head, ft_lastnode(p->a_head, true);
	if (command == RB)
		ft_rb(p, p->b_head, ft_lastnode(p->b_head, true);
	if (command == RRA)
		ft_rra(p, p->a_head, ft_lastnode(p->a_head, true);
	if (command == RRB)
		ft_rrb(p, p->b_head, ft_lastnode(p->b_head, true);
}
