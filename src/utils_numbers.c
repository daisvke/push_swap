/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 23:59:01 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/29 01:38:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ft_islowest_in_stack(t_stack *head, int value_to_check)
{
	while (head)
	{
		if (head->data < value_to_check)
			return (false);
		head = head->next;
	}
	return (true);
}

bool	ft_ishighest_in_stack(t_stack *head, int value_to_check)
{
	while (head)
	{
		if (head->data > value_to_check)
			return (false);
		head = head->next;
	}
	return (true);
}

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

t_stack	*ft_find_node_with_highest_num(t_param *p)
{
	t_stack	*node;
	t_stack	*node_with_highest_num;
	int		highest_num;

	node = p->a_head;
	node_with_highest_num = NULL;
	highest_num = p->size;
	while (node)
	{
		if (node->data == highest_num)
		{
			node_with_highest_num = node;
			break ;
		}
		node = node->next;
	}
	return (node_with_highest_num);
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
