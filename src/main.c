/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:21:17 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/07/08 03:16:21 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_count_split_len(char **split)
{
	int i;

	i = 0;
	while (split[i])
		++i;
	return (i);
}

void	ft_execute_command(t_param *p, int command)
{
	if (command == PA)
		ft_execute_pa(p, p->a_head, p->b_head, true);
	if (command == PB)
		ft_execute_pb(p, p->a_head, p->b_head, true);
	if (command == SA)
		ft_execute_sa(p, p->a_head, p->a_head->next, true);
	if (command == SB)
		ft_execute_sb(p, p->b_head, p->b_head->next, true);
	if (command == RA)
		ft_execute_ra(p, p->a_head, ft_lastnode(p->a_head), true);
	if (command == RB)
		ft_execute_rb(p, p->b_head, ft_lastnode(p->b_head), true);
	if (command == RRA)
		ft_execute_rra(p, p->a_head, ft_lastnode(p->a_head), true);
	if (command == RRB)
		ft_execute_rrb(p, p->b_head, ft_lastnode(p->b_head), true);
}

void	ft_execute_command_if_everything_else_is_ordered(t_param *p)
{
	t_stack	*second_node;
	int		top;
	int		next;
	int		last;
	int		end;

	second_node = p->a_head->next;
	top = p->a_head->data;
	next = second_node->data;
	last = ft_lastnode(p->a_head)->data;
	end = ft_stacksize(p->a_head);
	if (top > next && top < last && ft_is_in_the_right_order(p->a_head, 2, end))
		ft_execute_command(p, SA);
	else if (top > last && ft_is_in_the_right_order(p->a_head, 1, end))
		ft_execute_command(p, RA);
	else if (last < top && ft_is_in_the_right_order(p->a_head, 0, end - 1))
		ft_execute_command(p, RRA);
}

void	ft_redirect_to_algorithm_while_disordered(t_param *p)
{
	int	stacksize;

	stacksize = ft_stacksize(p->a_head);
	while (!ft_is_in_the_right_order(p->a_head, 0, p->size) || p->b_head)
	{
		if (stacksize != 3)
			ft_execute_command_if_everything_else_is_ordered(p);
		if (stacksize < 80)
			ft_execute_lowests_sort(p);
		if (stacksize >= 80)
			ft_execute_radix_sort(p);
	}
}

int	main(int argc, char *argv[])
{
	t_param	*p;

	if (argc > 1)
	{
		p = ft_init_param_with_stack(argv, argc - 1);
		if (p->size < 2)
			ft_exit_and_free_stack(p, false);
		ft_redirect_to_algorithm_while_disordered(p);
		ft_free_stack(p->a_head);
		free(p);
	}
	return (EXIT_SUCCESS);
}
