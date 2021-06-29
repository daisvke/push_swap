/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 01:44:35 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/29 02:21:29 by root             ###   ########.fr       */
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
		ft_execute_command(p, PA);
}

void	ft_push_according_to_binary_digit_value(t_param *p, int size, \
	int max_bits)
{
	t_stack	*node;
	int		i;
	int		j;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			node = p->a_head;
			if (((node->data >> i) & 1) == 1)
				ft_execute_command(p, RA);
			else
				ft_execute_command(p, PB);
			++j;
		}
		ft_connect_back_elem_from_b_to_a(p);
		++i;
	}
}

void	ft_execute_radix_sort(t_param *p)
{
	int	stacksize;
	int	max_num;
	int	max_bits;
	
	if (!ft_is_in_the_right_order(p->a_head, 0, p->size))
	{
		stacksize = ft_stacksize(p->a_head);
		max_num = ft_stacksize(p->a_head);
		max_bits = ft_compute_max_bits(max_num);
		ft_push_according_to_binary_digit_value(p, stacksize, max_bits);
	}
}
