/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:27:15 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/20 04:04:26 by dtanigaw         ###   ########.fr       */
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
	}
	if (w)
		write(1, "pa\n", 3);
	p->lastmove = 4;
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
	}
	if (w)
		write(1, "pb\n", 3);
	p->lastmove = 5;
}


