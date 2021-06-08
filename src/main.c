/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:21:17 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/08 18:15:31 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_printnode(t_param *p)
{
	t_stack	*node;

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
	printf("NULL\n\n");
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
	return (p);
}

t_param	*ft_extract_split(t_param *p, t_stack *node, char **split, int i)
{
	while (split[i])
	{
		node = ft_add_nbr(ft_stoi(p, split, split[i], i));
		ft_add_back(&(p->a_head), node);
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

int	main(int argc, char *argv[])
{
	t_param	*p;

	if (argc < 2)
		ft_exit_failure();
	p = ft_init_stack(argv, argc - 1);
	if (ft_stacksize(p->a_head) < 2)
		ft_exit_clearstack(p);

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

//	ft_pa(p, p->a_head, p->b_head, true);
//	ft_printnode(p);

//	ft_pb(p, p->a_head, p->b_head, true);
//	ft_printnode(p);

//	ft_ra(p, p->a_head, ft_lastnode(p->a_head), true);
//	ft_printnode(p);

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
		ft_lastnode(p->b_head));
	ft_printnode(p);
	return (EXIT_SUCCESS);
}
