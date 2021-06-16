/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset_reverse_r.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:28:18 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/15 14:23:47 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_param *p, t_stack *head, t_stack *tail, bool w)
{
	t_stack	*tmp;

	if (head && tail)
	{
		tmp = ft_xbef_lastnode(p, p->size, p->a_head, 1);
		tail->next = head;
		tmp->next = NULL;
		p->a_head = tail;
	}
	if (w)
		write(1, "rra\n", 4);
	p->lastmove = 9;
}

void	ft_rrb(t_param *p, t_stack *head, t_stack *tail, bool w)
{
	t_stack	*tmp;

	if (head && tail)
	{
		tmp = ft_xbef_lastnode(p, p->size, p->b_head, 1);
		printf("tmp:%d\n\n", tmp->data);
		tail->next = head;
		tmp->next = NULL;
		p->b_head = tail;
	}
	if (w)
		write(1, "rrb\n", 4);
	p->lastmove = 10;
}

void	ft_rrr(t_param *p, t_stack *ah, t_stack *at, t_stack *bh, t_stack *bt)
{
	ft_rra(p, ah, at, false);
	ft_rrb(p, bh, bt, false);
	write(1, "rrr\n", 4);
	p->lastmove = 11;
}
