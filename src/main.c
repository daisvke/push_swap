/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:21:17 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/27 11:11:13 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*
void	ft_printnode(t_param *p)
{
	t_stack	*node;

	printf("=========\n");
	if (!p)
		printf("EMPTY\n");
	node = p->a_head;
	printf("a stack:\n");
	while (node)
	{
		printf("%d -> ", node->data);
		node = node->next;
	}
	printf("NULL\n\n");
	printf("b stack:\n");
	node = p->b_head;
	while (node)
	{
		printf("%d -> ", node->data);
		node = node->next;
	}
	printf("NULL\n");
	printf("=========\n\n");
}
*/

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

bool	ft_twice(t_stack *node, int num)
{
	while (node)
	{
		if (node->data == num)
			return (true);
		node = node->next;
	}
	return (false);
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
			i++;
		}
		node = node->next;
	}
}

void	ft_simplify_stack_nbr_values(t_param *p, int size)
{
	t_stack	*node;
	int		i;
	int		min;
	int		*checked_nbrs;

	i = 0;
	checked_nbrs = malloc(size * sizeof(*checked_nbrs));
	while (i < size)
	{
		node = p->a_head;
		while (ft_isthere(node->data, checked_nbrs, i))
			node = node->next;
		min = node->data;
		while (node)
		{
			if (node->data < min && !ft_isthere(node->data, checked_nbrs, i))
				min = node->data;
			node = node->next;
		}
		checked_nbrs[i] = min;
		i++;
	}
	ft_find_in_stack_and_replace(p, checked_nbrs, size);
	free(checked_nbrs);
}

t_param	*ft_extract_split(t_param *p, char **split, int start_point)
{
	t_stack	*node;
	int		num;
	int		i;
	
	i = start_point;
	node = p->a_head;
	while (split[i])
	{
		num = ft_convert_str_to_num(p, split, split[i], i);
		if (ft_twice(p->a_head, num))
			ft_exit_and_free_array_and_stack(p, split, i);
		node = ft_add_nbr(num);
		ft_add_back(p->a_head, node);
		if (!node)
			ft_exit_and_free_array_and_stack(p, split, i);	
		++i;
	}
	return (p);
}

t_param	*ft_init_param_with_stack(char **args, int size)
{
	t_param	*p;
	char	**split;
	int		i;
	int		size_cpy;

	size_cpy = size;
	split = ft_split_elem_from_argv(args[1], ' ');
	p = ft_init_param_with_first_node(ft_convert_str_to_num( \
		NULL, split, split[0], 1));
	p = ft_extract_split(p, split, 1);
	ft_free_array_of_pointers(split, 1);
	i = 2;
	while (size--)
	{
		split = ft_split_elem_from_argv(args[i], ' ');
		p = ft_extract_split(p, split, 0);
		i++;
	}
//	ft_free_array_of_pointers(split, size_cpy - 1);
	p->size = ft_stacksize(p->a_head);
	ft_simplify_stack_nbr_values(p, p->size);
	p->b_head = NULL;
	return (p);
}

void	ft_sa_if_everything_else_is_ordered(t_param *p)
{
	t_stack	*top_node;
	t_stack	*second_node;
	t_stack	*last_node;
	int		top;
	int		next;
	int		last;
	int		end;

	top_node = p->a_head;
	second_node = top_node->next;
	last_node = ft_lastnode(top_node);
	top = top_node->data;
	next = second_node->data;
	last = last_node->data;
	end = ft_stacksize(top_node);
	if (top > next && top < last && ft_is_in_the_right_order(top_node, 2, end))
		ft_sa(p, top_node, second_node, true);
}

void	ft_ra_if_everything_else_is_ordered(t_param *p)
{
	t_stack	*top_node;
	t_stack	*second_node;
	t_stack	*last_node;
	int		top;
	int		last;
	int		end;

	top_node = p->a_head;
	second_node = top_node->next;
	last_node = ft_lastnode(top_node);
	top = top_node->data;
	last = last_node->data;
	end = ft_stacksize(top_node);
	if (top > last && ft_is_in_the_right_order(top_node, 1, end))
		ft_ra(p, top_node, last_node, true);
}

void	ft_rra_if_everything_else_is_ordered(t_param *p)
{
	t_stack	*top_node;
	t_stack	*last_node;
	int		top;
	int		last;
	int		end;

	top_node = p->a_head;
	last_node = ft_lastnode(top_node);
	top = top_node->data;
	last = last_node->data;
	end = ft_stacksize(top_node);
	if (last < top && ft_is_in_the_right_order(top_node, 0, end - 1))
		ft_execute_command_if_everything_else_is_ordered(p, RRA);
}

void	ft_execute_command_if_everything_else_is_ordered(t_param *p)
{
	
}

void	ft_execute_default_sort(t_param *p)
{
	if (ft_stacksize(p->a_head) != 3)
	{
		ft_execute_sa_if_everything_else_is_ordered(p);
		ft_ra_if_everything_else_is_ordered(p);
		ft_rra_if_everything_else_is_ordered(p);
	}
}

void	ft_apply_algorithm(t_param *p)
{
	int	stacksize;

	stacksize = ft_stacksize(p->a_head);
	ft_execute_default_sort(p);
	if (stacksize < 80)
		ft_execute_lowests_sort(p);
	if (stacksize >= 80)
		ft_execute_radix_sort(p);
}

void	ft_redirect_to_algorithm_while_disordered(t_param *p)
{
	while (!ft_is_in_the_right_order(p->a_head, 0, p->size) || p->b_head)
		ft_apply_algorithm(p);
}

int	main(int argc, char *argv[])
{
	t_param	*p;

	if (argc < 2)
		ft_exit_failure();
	p = ft_init_param_with_stack(argv, argc - 1);
	if (p->size < 2)
		ft_exit_and_free_stack(p);
	ft_redirect_to_algorithm_while_disordered(p);
	ft_free_stack(p->a_head);
//	ft_printnode(p);
	return (EXIT_SUCCESS);
}
