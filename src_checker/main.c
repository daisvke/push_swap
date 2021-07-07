/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 03:14:17 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/07/08 01:43:21 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_apply_moves_read_from_output_to_stack(t_param *p, char **move)
{
	char	**array_of_cmds;
	size_t	cmd_len;	
	size_t	i;

	cmd_len = ft_strlen(*move);
	array_of_cmds = ft_init_array_of_commands();
	i = 0;
	while (array_of_cmds[i])
	{
		if (ft_strncmp(array_of_cmds[i], *move, cmd_len) == 0)
		{
			ft_execute_command(p, i);
			return ;
		}
		++i;
	}
	ft_exit_and_free_stack(p, PRINT_ERR);
}

void	ft_read_moves_from_output(t_param *p)
{
	char	*move;

	move = NULL;
	while (get_next_line(0, &move))
	{
		ft_apply_moves_read_from_output_to_stack(p, &move);
		free(move);
	}
	free(move);
	move = NULL;
}

void	ft_check_order(t_param *p)
{
	bool	is_ordered;

	is_ordered = ft_is_in_the_right_order(p->a_head, 0, p->size);
	if (is_ordered && p->b_head == NULL)
		write(1, "\e[32;40mOK\e[32;0m\n", 19);
	else
		write(1, "\e[31;40mKO\e[32;0m\n", 19);
}

int	main(int argc, char *argv[])
{
	t_param	*p;

	if (argc > 1)
	{
		p = ft_init_param_with_stack(argv, argc - 1);
		if (p->size < 2)
			ft_exit_and_free_stack(p, false);
		ft_read_moves_from_output(p);
		ft_check_order(p);
		ft_free_stack(p->a_head);
		if (p->b_head)
			ft_free_stack(p->b_head);
		free(p);
	}
	return (EXIT_SUCCESS);
}
