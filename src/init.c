/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 00:33:45 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/29 00:50:33 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_param	*ft_init_param_with_first_node(int num)
{
	t_param	*p;
	t_stack	*node;

	p = malloc(sizeof(*p));
	if (!p)
		ft_exit_failure();
	node = malloc(sizeof(*node));
	if (!node)
	{
		free(p);
		p = NULL;
		ft_exit_failure();
	}
	node->data = num;
	node->next = NULL;
	p->a_head = node;
	p->b_head = NULL;
	return (p);
}

void	ft_find_in_stack_and_replace(t_param *p, int *nbrs_to_replace_with, \
	int array_size)
{
	t_stack	*node;
	int		i;
	int		j;

	node = p->a_head;
	while (node)
	{
		i = 0;
		j = array_size;
		while (j--)
		{
			if (nbrs_to_replace_with[i] == node->data)
			{
				node->data = i + 1;
				break ;
			}
			++i;
		}
		node = node->next;
	}
}

void	ft_simplify_stack_num_values(t_param *p, int size)
{
	t_stack	*node;
	int		i;
	int		min;
	int		*checked_nums;

	i = 0;
	checked_nums = malloc(size * sizeof(*checked_nums));
	while (i < size)
	{
		node = p->a_head;
		while (ft_isthere(node->data, checked_nums, i))
			node = node->next;
		min = node->data;
		while (node)
		{
			if (node->data < min && !ft_isthere(node->data, checked_nums, i))
				min = node->data;
			node = node->next;
		}
		checked_nums[i] = min;
		++i;
	}
	ft_find_in_stack_and_replace(p, checked_nums, size);
	free(checked_nums);
	checked_nums = NULL;
}

char	*ft_get_arg_with_num(char **args, int pos, int num_of_args)
{
	int	j;

	while (--num_of_args)
	{
		j = 0;
		while (args[pos][j])
		{
			if (ft_isdigit(args[pos][j]))
				return (args[pos]);
			++j;
		}
		++pos;
	}
	return (NULL);
}

t_param	*ft_init_param_with_stack(char **args, int size)
{
	t_param	*p;
	char	**split;
	int		i;
	int		size_cpy;

	p = NULL;
	size_cpy = size;
	i = FIRST_POS;
	split = ft_split_elem_from_argv(p, ft_get_arg_with_num( \
		args, 1, size_cpy), ' ');
	p = ft_init_param_with_first_node(ft_convert_str_to_num( \
		NULL, split, split[0]));
	ft_extract_split(p, split, 1);
	i = FIRST_POS + 1;
	while (--size)
	{
		split = ft_split_elem_from_argv(p, ft_get_arg_with_num( \
			args, i, size_cpy), ' ');
		ft_extract_split(p, split, 0);
		++i;
	}
	split = NULL;
	p->size = ft_stacksize(p->a_head);
	ft_simplify_stack_num_values(p, p->size);
	p->b_head = NULL;
	return (p);
}
