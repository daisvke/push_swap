/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 01:50:44 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/27 02:05:06 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_exit_failure(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_exit_and_free_array(char **str, int i)
{
	ft_free_array_of_pointers(str, i);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_free_stack(t_stack *node)
{
	t_stack	*next;

	if (!node)
		return ;
	while (node)
	{
		next = node->next;
		if (node)
			free(node);
		node = next;
	}
	if (node)
		node = NULL;
}

void	ft_exit_and_free_array_and_stack(t_param *p, char **split, int size)
{
	ft_free_array_of_pointers(split, size);
	if (p)
		ft_free_stack(p->a_head);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_exit_and_free_stack(t_param *p)
{
	ft_free_stack(p->a_head);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}
