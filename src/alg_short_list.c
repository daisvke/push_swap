/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_short_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:33:19 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/10 05:28:42 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ft_isasc_between(t_param *p)
{
	return (ft_isasc(p, p->a_head, 1, ft_stacksize(p->a_head) - 1));
}

bool	ft_isdesc_between(t_param *p)
{
	return (ft_isdesc(p, p->a_head, 1, ft_stacksize(p->a_head) - 1));
}

bool	ft_islowest_xbef_lastnode(t_param *p, int i)
{
	return (ft_islowest(p->a_head, \
		ft_xbef_lastnode(p, ft_stacksize(p->a_head), p->a_head, i)->data));
}

void	ft_reverse(t_param *p)
{
	while (ft_isdesc(p, p->a_head, 0, ft_stacksize(p->a_head)) && p->size--)
		ft_ra(p, p->a_head, ft_lastnode(p->a_head), true);
}

void	ft_sort_short_list(t_param *p, int pos, int tmp)
{
	if (p->a_head->data > p->a_head->next->data)
	{
		if (p->a_head->data < ft_lastnode(p->a_head)->data \
		|| !(p->a_head->next->next))
		ft_sa(p, p->a_head, p->a_head->next, true);
		else if (!ft_isasc(p, p->a_head, 1, ft_stacksize(p->a_head)) \
		|| (ft_ishighest(p->a_head, p->a_head->data) \
		&& ft_isasc(p, p->a_head, 1, ft_stacksize(p->a_head) - 1)) \
		|| (ft_ishighest(p->a_head, p->a_head->data)
		&& ft_isdesc_between(p)))
		ft_ra(p, p->a_head, ft_lastnode(p->a_head), true);
	}
	else if (((!ft_isasc(p, p->a_head, 0, \
		ft_stacksize(p->a_head) - 1) \
		&& ft_lastnode(p->a_head)->data < p->a_head->data)) \
		|| (ft_islowest_xbef_lastnode(p, 0)) \
		|| (!ft_isasc_between(p) && ft_ishighest(p->a_head, p->a_head->data) \
		&& ft_islowest_xbef_lastnode(p, 1)))
		ft_rra(p, p->a_head, ft_lastnode(p->a_head), true);
	else if (pos > p->size / 2
		|| (ft_islowest(p->a_head, p->a_head->data)
		&& ft_ishighest(p->a_head, ft_lastnode(p->a_head)->data)
		&& ft_stacksize(p->a_head) > 3))
	{
		tmp = pos - 1;
		if (tmp < 0)
			tmp = 0;
		while (tmp--)
			ft_pb(p, p->a_head, p->b_head, true);
	}
	else if (pos == -1)
		ft_pa(p, p->a_head, p->b_head, true);
}

