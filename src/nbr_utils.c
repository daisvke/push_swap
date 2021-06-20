/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 23:59:01 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/20 13:33:43 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_disordered(t_param *p, t_stack *node, int start, int end)
{
	int	size;
	int	st_tmp;
	
	if (!node)
		return (0);
	st_tmp = start;
	size = end - start - 1;
	while (node->next && start--)
		node = node->next;
	while (node->next && size--)
	{
		if (node->data > node->next->data)
			return (p->size - st_tmp - size - 1);
		node = node->next;
	}
	return (0);
}

bool	ft_isasc(t_stack *node, int start, int end)
{
	int	size;
	int	st_tmp;
	
	if (!node)
		return (true);
	st_tmp = start;
	size = end - start - 1;
	while (node && start--)
		node = node->next;
	while (node && size--)
	{
		if (node->data > node->next->data)
			return (false);
		node = node->next;
	}
	return (true);
}

bool	ft_isdesc(t_stack *node, int start, int end)
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
		if (node->data < node->next->data)
			return (false);
		node = node->next;
	}
	return (true);
}

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

bool	ft_islowest_expt(t_stack *node, int n, int *t)
{
	int		i;
	bool	unfound;

	while (node)
	{
		unfound = true;
		if (node->data < n)
		{
			i = 0;
			while(t[i])
			{
				if (node->data == t[i])
				{
					unfound = false;
					break ;
				}
				i++;
			}
			if (unfound == true)
				return (false);
		}
		node = node->next;
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

bool	ft_ishighest_inrange(t_param *p, int start, int end)
{
	t_stack	*node;
	int		size;
	int		st_tmp;

	node = p->a_head;
	st_tmp = start;
	size = end - start;
	while (node && start--)
		node = node->next;
	while (node && size--)
	{
		if (ft_ishighest_in_stack(p->a_head, node->data))
			return (true);
		node = node->next;
	}
	return (false);
}

t_stack	*ft_find_node_with_highest_num(t_param *p)
{
	t_stack	*node;
	t_stack	*node_with_highest_num;
	int		highest_num;

	node = p->a_head;
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

t_stack	*ft_find_node_with_lowest_num(t_param *p)
{
	t_stack	*node;
	t_stack	*node_with_lowest_num;

	node_with_lowest_num = NULL;
	node = p->a_head;
	while (node)
	{
		if (node->data == 1)
		{
			node_with_lowest_num = node;
			break ;
		}
		node = node->next;
	}
	return (node_with_lowest_num);
}

int	ft_stoi(t_param *p, char **split, char *str, int j)
{
	int					sign;
	int					s_count;
	unsigned long long	res;

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
		res = res * 10 + *str++ - 48;
	if (res > 2147483647)
		ft_exit_lst_tabfree(p, split, j);
	return (res * sign);
}
