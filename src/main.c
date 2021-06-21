/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:21:17 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/21 14:18:31 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

t_param	*ft_init(int n)
{
	t_param	*p;
	t_stack	*node;

	p = malloc(sizeof(*p));
	node = malloc(sizeof(*node));
	if (!p || !node)
		ft_exit_failure();
	node->data = n;
	p->a_head = node;
	p->b_head = NULL;
	return (p);
}

bool	ft_twice(t_stack *node, int n)
{
	while (node)
	{
		if (node->data == n)
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

t_param	*ft_extract_split(t_param *p, t_stack *node, char **split, int i)
{
	int	n;
	
	while (split[i])
	{
		n = ft_stoi(p, split, split[i], i);
		if (ft_twice(p->a_head, n))
			ft_exit_lst_tabfree(p, split, i);
		node = ft_add_nbr(n);
		ft_add_back(p->a_head, node);
		if (!node)
			ft_exit_lst_tabfree(p, split, i);	
		i++;
	}
	return (p);
}

t_param	*ft_init_stack(char **args, int size)
{
	t_param	*p;
	t_stack	*node;
	char	**split;
	int		i;
	int		size_cpy;

	node = NULL;
	size_cpy = size;
	split = ft_split_errchk(args[1], ' ');
	p = ft_init(ft_atoi(split[0]));
	node = p->a_head;
	p = ft_extract_split(p, node, split, 1);
	i = 2;
	while (size--)
	{
		split = ft_split_errchk(args[i], ' ');
		p = ft_extract_split(p, node, split, 0);
		i++;
	}
//	ft_tabfree(split, size_cpy);
	p->size = ft_stacksize(p->a_head);
	ft_simplify_stack_nbr_values(p, p->size);
	p->lastmove = 0;
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
	if (top > next && top < last && ft_isasc(top_node, 2, end))
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
	if (top > last && ft_isasc(top_node, 1, end))
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
	if (last < top && ft_isasc(top_node, 0, end - 1))
		ft_rra(p, top_node, last_node, true);
}

void	ft_default_sort_algorithm(t_param *p)
{
	if (p->disordered_position)
	{
		if (ft_stacksize(p->a_head) != 3)
		{
			ft_sa_if_everything_else_is_ordered(p);
			ft_ra_if_everything_else_is_ordered(p);
			ft_rra_if_everything_else_is_ordered(p);
		}
		p->disordered_position = ft_disordered(p, p->a_head, 0, p->size);
	}
}

void	ft_apply_algorithm(t_param *p)
{
	ft_default_sort_algorithm(p);
	if (ft_stacksize(p->a_head) == 2)
		ft_sort_two_elements(p, A);
	if (ft_stacksize(p->a_head) == 3)
		ft_sort_three_elements(p, A);
	if (ft_stacksize(p->a_head) > 3 && ft_stacksize(p->a_head) < 6)//7
		ft_sort_short_list(p);
	if (ft_stacksize(p->a_head) > 5)//6
		ft_sort_long_list(p);
}

void	ft_redirect_to_algorithm(t_param *p)
{
	p->disordered_position = 1;
	while (p->disordered_position || p->b_head)
	{
		p->disordered_position = ft_disordered(p, p->a_head, 0, p->size);
		if (!(p->disordered_position) && !p->b_head)
			break ;
		ft_apply_algorithm(p);
	}
}

int	main(int argc, char *argv[])
{
	t_param	*p;

	if (argc < 2)
		ft_exit_failure();
	p = ft_init_stack(argv, argc - 1);
	if (p->size < 2)
		ft_exit_clearstack(p);
//	ft_printnode(p);
	ft_redirect_to_algorithm(p);
//	ft_printnode(p);
	return (EXIT_SUCCESS);
}
