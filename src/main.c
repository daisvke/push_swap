/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:21:17 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/19 03:17:48 by dtanigaw         ###   ########.fr       */
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

void	ft_find_in_stack_and_replace(t_param *p, int *nbrs_to_replace_with)
{
	t_stack	*node;
	int		i;

	node = p->a_head;
	while (node)
	{
		i = 0;
		while (nbrs_to_replace_with[i])
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
			if (!ft_isthere(node->data, checked_nbrs, i) && node->data < min)
				min = node->data;
			node = node->next;
		}
		checked_nbrs[i] = min;
		i++;
	}
	ft_find_in_stack_and_replace(p, checked_nbrs);
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

	node = NULL;
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
	free(split);
	split = NULL;
	p->size = ft_stacksize(p->a_head);
	ft_simplify_stack_nbr_values(p, p->size);
	p->lastmove = 0;
	p->b_head = NULL;
	return (p);
}

void	ft_sort_default_alg(t_param *p, int *disordered_position)
{
	int	tmp;

	if (*disordered_position || p->b_head)
	{
		if (p->a_head->data > p->a_head->next->data \
			&& (p->size != 5 || !(ft_ishighest(p->a_head, p->a_head->data)
			&& ft_islowest(p->a_head, ft_lastnode(p->a_head)->data))))
		{
			if (p->lastmove != 1
				&& (p->a_head->data < ft_lastnode(p->a_head)->data \
				|| (ft_isasc(p->a_head, 1, ft_stacksize(p->a_head) - 1))))
				ft_sa(p, p->a_head, p->a_head->next, true);
			else if (p->lastmove != 9)
				ft_ra(p, p->a_head, ft_lastnode(p->a_head), true);
		}
		else if (p->lastmove != 6
			&& (((!ft_isasc(p->a_head, 0, ft_stacksize(p->a_head) - 1) \
			&& ft_lastnode(p->a_head)->data < p->a_head->data))))
			ft_rra(p, p->a_head, ft_lastnode(p->a_head), true);
		else if (*disordered_position > p->size / 2 \
			|| (ft_islowest(p->a_head, p->a_head->data)
			&& ft_ishighest(p->a_head, ft_lastnode(p->a_head)->data)))
		{
			tmp = *disordered_position - 1;
			if (tmp < 0)
				tmp = 0;
			while (tmp--)
				ft_pb(p, p->a_head, p->b_head, true);
		}
		else if (p->b_head && p->lastmove != 5)
			ft_pa(p, p->a_head, p->b_head, true);
		else if (p->lastmove != 4)
			ft_pb(p, p->a_head, p->b_head, true);
		*disordered_position = ft_disordered(p, p->a_head, 0, p->size);
	}
}

void	ft_apply_algorithm(t_param *p, int *disordered_position)
{
//	int	*low;
//	low = ft_lowest_nodes(p);
//		printf("disordered_position: %d\n", disordered_position);
	if (ft_stacksize(p->a_head) == 3)
		ft_sort_three_elements(p, disordered_position);
	if (ft_stacksize(p->a_head) == 5)
		ft_sort_five_elements(p, disordered_position);
	ft_sort_default_alg(p, disordered_position);
	if (ft_stacksize(p->a_head) != 5)
		ft_sort_short_list(p, disordered_position);
/*		if ((pos || p->b_head) && p->size >= 60)
			ft_sort_long_list(p, low);
			*/
}

void	ft_redirect_to_algorithm(t_param *p)
{
	int	disordered_position;

	disordered_position = 1;
	while (disordered_position || p->b_head)
	{
		disordered_position = ft_disordered(p, p->a_head, 0, p->size);
//		printf("disordered_position: %d\n", disordered_position);
		if (!disordered_position && !p->b_head)
			break ;
		ft_apply_algorithm(p, &disordered_position);
/*		if ((pos || p->b_head) && p->size >= 60)
			ft_sort_long_list(p, low);
			*/
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
