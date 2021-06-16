/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:27:51 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/15 14:23:47 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_param *p, t_stack *head, t_stack *tail, bool w)
{
	t_stack	*tmp;

	if (head && tail)
	{
		tmp = head->next;
		head->next = NULL;
		tail->next = head;
		p->a_head = tmp;
	}
	if (w)
		write(1, "ra\n", 3);
	p->lastmove = 6;
}

void	ft_rb(t_param *p, t_stack *head, t_stack *tail, bool w)
{
	t_stack	*tmp;

	if (head && tail)
	{
		tmp = head->next;
		head->next = NULL;
		tail->next = head;
		p->b_head = tmp;
	}
	if (w)
		write(1, "rb\n", 3);
	p->lastmove = 7;
}

void	ft_rr(t_param *p, t_stack *ah, t_stack *at, t_stack *bh, t_stack *bt)
{
	ft_ra(p, ah, at, false);
	ft_rb(p, bh, bt, false);
	write(1, "rr\n", 3);
	p->lastmove = 8;
}
