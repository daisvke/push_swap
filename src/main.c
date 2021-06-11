/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:21:17 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/11 15:06:27 by dtanigaw         ###   ########.fr       */
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
	p->b_head = NULL;
	return (p);
}

void	ft_sort_default_alg(t_param *p, int pos, int tmp)
{
	if (p->a_head->data > p->a_head->next->data)
	{
		if (p->a_head->data < ft_lastnode(p->a_head)->data \
		|| !(p->a_head->next->next) \
		|| (ft_isasc(p, p->a_head, 1, ft_stacksize(p->a_head) - 1) \
		&& (p->a_head->data > ft_lastnode(p->a_head)->data \
		&& ft_ishighest_inrange(p, 1, ft_stacksize(p->a_head) - 1)))
		|| ft_isasc(p, p->a_head, 1, ft_stacksize(p->a_head)))
		ft_sa(p, p->a_head, p->a_head->next, true);
		else if ((!ft_isasc(p, p->a_head, 1, ft_stacksize(p->a_head)) \
		&& ) \
		|| (ft_ishighest(p->a_head, p->a_head->data) \
		&& ft_isasc(p, p->a_head, 1, ft_stacksize(p->a_head) - 1)) \
		|| (ft_ishighest(p->a_head, p->a_head->data)
		&& ft_isdesc_between(p)))
		ft_ra(p, p->a_head, ft_lastnode(p->a_head), true);
	}
	else if ((ft_isasc(p, p->a_head, 0, ft_stacksize(p->a_head) - 1)
		&& ft_islowest(p->a_head, ft_lastnode(p->a_head)->data)) \
		|| ((!ft_isasc(p, p->a_head, 0, \
		ft_stacksize(p->a_head) - 1) \
		&& ft_lastnode(p->a_head)->data < p->a_head->data)) \
		|| (ft_islowest_xbef_lastnode(p, 0)) \
		|| (!ft_isasc_between(p) && ft_ishighest(p->a_head, p->a_head->data) \
		&& ft_islowest_xbef_lastnode(p, 1)))
		ft_rra(p, p->a_head, ft_lastnode(p->a_head), true);
		//rra until lowest->top
	else if (pos > p->size / 2
		|| (ft_islowest(p->a_head, p->a_head->data)
		&& ft_ishighest(p->a_head, ft_lastnode(p->a_head)->data)
		&& ft_stacksize(p->a_head) > 3)
		|| ft_isdesc_between(p))
	{
		tmp = pos - 1;
		if (tmp < 0)
			tmp = 0;
		while (tmp--)
			ft_pb(p, p->a_head, p->b_head, true);
	}
	else if (p->b_head)
		ft_pa(p, p->a_head, p->b_head, true);
}

void	ft_redirect(t_param *p, int size)
{
	int	pos;
	int	tmp;
	int	*low;

	int sizes= 8;

	pos = 1;
	low = ft_lowest_nodes(p);
	while ((pos || p->b_head) &&  sizes--)
	{
		pos = ft_disordered(p, p->a_head, 0, p->size);
		if (!pos && !p->b_head)
			break ;
		ft_sort_default_alg(p, pos, tmp);
		pos = ft_disordered(p, p->a_head, 0, p->size);
		if (pos || p->b_head)
			ft_sort_short_list(p, pos, tmp);
/*		else if (ft_lastnode(p->a_head)->data
			< ft_xbef_lastnode(p, p->size, p->a_head, 1)->data)
		{
			ft_pb(p, p->a_head, p->b_head, true);
			ft_sa(p, p->a_head, p->a_head->next, true);
			ft_pa(p, p->a_head, p->b_head, true);
		}*/
//		printf("pos: %d\n", pos);
		pos = ft_disordered(p, p->a_head, 0, p->size);
		if ((pos || p->b_head) && p->size >= 600)
			ft_sort_long_list(p, low);
	}
}

int	main(int argc, char *argv[])
{
	t_param	*p;

	if (argc < 2)
		ft_exit_failure();
	p = ft_init_stack(argv, argc - 1);
	p->size = ft_stacksize(p->a_head);
	if (p->size < 2)
		ft_exit_clearstack(p);

//	ft_printnode(p);

	ft_redirect(p, p->size);
	
//	ft_printnode(p);

	/*
	t_stack *b = malloc(sizeof(*b));
	p->b_head = b;
	b->data = 34;
	t_stack *elem = malloc(sizeof(*b));
	b->next = elem;
	elem->data = 54;
	t_stack *next = malloc(sizeof(*b));
	elem->next = next;
	next->data = 400;
	next->next = NULL;
	ft_printnode(p);

	ft_pa(p, p->a_head, p->b_head, true);
	ft_printnode(p);

	ft_pb(p, p->a_head, p->b_head, true);
	ft_printnode(p);

//	ft_ra(p, p->a_head, ft_lastnode(p->a_head), true);
	ft_printnode(p);

//	ft_rb(p, p->b_head, ft_lastnode(p->b_head), true);
//	ft_printnode(p);

	ft_ss(p, p->a_head, p->a_head->next, p->b_head, p->b_head->next);
	ft_printnode(p);

	ft_rr(p, p->a_head, ft_lastnode(p->a_head), p->b_head, \
		ft_lastnode(p->b_head));
	ft_printnode(p);

	ft_rra(p, p->a_head, ft_lastnode(p->a_head), true);
	ft_printnode(p);

	ft_rrb(p, p->b_head, ft_lastnode(p->b_head), true);
	ft_printnode(p);

	ft_rrr(p, p->a_head, ft_lastnode(p->a_head), p->b_head, \
		ft_lastnode(p->b_head));*/
//	ft_printnode(p);
	return (EXIT_SUCCESS);
}
