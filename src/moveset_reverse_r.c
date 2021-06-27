/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset_reverse_r.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:28:18 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/23 02:55:45 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_param *p, t_stack *head, t_stack *tail, bool w)
{
	t_stack	*tmp;

	if (head && tail)
	{
		tmp = ft_xbef_lastnode(p, ft_stacksize(p->a_head), p->a_head, 1);
		tail->next = head;
		tmp->next = NULL;
		p->a_head = tail;
		if (w)
			write(1, "rra\n", 4);
	}
}

void	ft_rrb(t_param *p, t_stack *head, t_stack *tail, bool w)
{
	t_stack	*tmp;

	if (head && tail)
	{
		tmp = ft_xbef_lastnode(p, ft_stacksize(p->b_head), p->b_head, 1);
		tail->next = head;
		tmp->next = NULL;
		p->b_head = tail;
		if (w)
			write(1, "rrb\n", 4);
	}
}

void	ft_rrr(t_param *p, t_stack *ah, t_stack *at, t_stack *bh, t_stack *bt)
{
	if ((ah && at) || (bh && bt))
	{
		ft_rra(p, ah, at, false);
		ft_rrb(p, bh, bt, false);
		write(1, "rrr\n", 4);
	}
}
