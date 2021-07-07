/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 01:50:44 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/07/07 22:49:47 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_exit_failure(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_exit_and_free_split(char **split, int i)
{
	ft_free_split(split, i);
	write(2, "Error\n", 6);
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
	node = NULL;
}

void	ft_exit_and_free_split_and_stack(t_param *p, char **split, int i)
{
	if (split)
		ft_free_split(split, i);
	if (p)
	{
		ft_free_stack(p->a_head);
		free(p);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_exit_and_free_stack(t_param *p, bool print_error)
{
	if (p)
	{
		ft_free_stack(p->a_head);
		free(p);
	}
	if (print_error == true)
		write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
