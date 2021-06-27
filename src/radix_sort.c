/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 01:44:35 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/27 11:29:45 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_compute_max_bits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while (max_num >> max_bits)
		++max_bits;
	return (max_bits);
}

void	ft_connect_back_elem_from_b_to_a(t_param *p)
{
	while (p->b_head)
		ft_pa(p, p->a_head, p->b_head, true);
}

void	ft_execute_radix_sort(t_param *p, int size, int max_num, int max_bits)
{
	t_stack	*node;
	int		i;
	int		j;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while(j < size)
		{
			node = p->a_head;
			if (((node->data >> i) & 1) == 1)
				ft_ra(p, p->a_head, ft_lastnode(p->a_head), true);
			else
				ft_pb(p, p->a_head, p->b_head, true);
			++j;
		}
		ft_connect_back_elem_from_b_to_a(p);
		++i;
	}
}

void	ft_redirect_to_radix_sort(t_param *p)
{
	if (!ft_is_in_the_right_order(p->a_head, 0, p->size))
	{
		int	stacksize;
		int	max_num;
		int	max_bits;

		stacksize = ft_stacksize(p->a_head);
		max_num = ft_stacksize(p->a_head);
		max_bits = ft_compute_max_bits(max_num);
		ft_execute_radix_sort(p, stacksize, max_num, max_bits);
	}
}
