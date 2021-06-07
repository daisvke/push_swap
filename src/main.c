/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:21:17 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/08 00:51:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	printnode(t_param *p)
{
	t_stack	*node;

	if (!p)
		printf("EMPTY\n");
	node = p->a_head;
	while (node)
	{
		printf("%d -> ", node->data);
		node = node->next;
	}
	printf("NULL\n");
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
	printnode(p);
	return (p);
}

void	ft_check_input_err(t_param *p)
{
	if (ft_stacksize(p->a_head) < 2)
		ft_exit_clearstack(p);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		ft_exit_failure();
	ft_check_input_err(ft_init_stack(argv, argc - 1));
//	printf("head: %d\n", p.a_head->data);
	return (EXIT_SUCCESS);
}
