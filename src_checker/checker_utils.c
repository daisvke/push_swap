/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lowests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 21:52:57 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/07/01 00:08:47 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_add_nbr(int data)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

int	ft_convert_str_to_num(t_param *p, char **split, char *str)
{
	int			sign;
	int			s_count;
	long long	res;

	while (ft_isws(*str))
		str++;
	sign = 1;
	s_count = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
		s_count++;
	}
	if (s_count > 1)
		return (0);
	res = 0;
	while (ft_isdigit(*str))
		res = res * 10 + *str++ - '0';
	res *= sign;
	if (res > 2147483647 || res < -2147483648)
		ft_exit_and_free_split_and_stack(p, split);
	return (res);
}

bool	ft_isthere(int nbr_to_find, int *array_of_nbrs, int array_size)
{
	int	i;

	i = 0;
	while (i < array_size)
	{
		if (array_of_nbrs[i] == nbr_to_find)
			return (true);
		++i;
	}
	return (false);
}

bool	ft_is_in_the_right_order(t_stack *node, int start, int end)
{
	int	size;
	int	st_tmp;

	if (!node)
		return (true);
	st_tmp = start;
	size = end - start - 1;
	while (node->next && start--)
		node = node->next;
	while (node->next && size--)
	{
		if (node->data > node->next->data)
			return (false);
		node = node->next;
	}
	return (true);
}
