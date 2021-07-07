/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 00:33:45 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/07/08 01:25:21 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_param	*ft_init_param_with_first_node(char **split, int i)
{
	t_param	*p;
	t_stack	*node;
	int		num;
	bool	must_exit;

	must_exit = false;
	num = ft_convert_str_to_num(split[0], &must_exit);
	if (must_exit == true)
		ft_exit_and_free_split(split, i);
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

char	*ft_get_arg_with_num(char **args, int pos, int *i)
{
	int	j;

	while (args[pos])
	{
		j = 0;
		while (args[pos][j])
		{
			if (ft_isdigit(args[pos][j]))
				return (args[pos]);
			++j;
		}
		++pos;
		++*i;
	}
	return (NULL);
}

t_param	*ft_init_param_with_stack(char **args, int size)
{
	t_param	*p;
	char	**split;
	int		i;

	p = NULL;
	i = FIRST_POS;
	split = ft_split_elem_from_argv(p, ft_get_arg_with_num(\
		args, 1, &i), ' ');
	p = ft_init_param_with_first_node(split, i);
	ft_extract_split(p, split, 1);
	i += 1;
	while (--size)
	{
		split = ft_split_elem_from_argv(p, ft_get_arg_with_num(\
			args, i, &i), ' ');
		ft_extract_split(p, split, 0);
		++i;
	}
	p->size = ft_stacksize(p->a_head);
	p->b_head = NULL;
	return (p);
}

char	**ft_init_array_of_commands(void)
{
	 static char	*array_of_cmds[9];

	array_of_cmds[0] = "sa";
	array_of_cmds[1] = "sb";
	array_of_cmds[2] = "pa";
	array_of_cmds[3] = "pb";
	array_of_cmds[4] = "ra";
	array_of_cmds[5] = "rb";
	array_of_cmds[6] = "rra";
	array_of_cmds[7] = "rrb";
	array_of_cmds[8] = NULL;
	return (array_of_cmds);	
}
