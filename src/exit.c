/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 01:50:44 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/28 13:36:47 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
	split = NULL;
}

void	ft_exit_failure(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_exit_and_free_split(char **split)
{
	ft_free_split(split);
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
	node = NULL;
}

void	ft_exit_and_free_split_and_stack(t_param *p, char **split)
{
	ft_free_split(split);
	if (p)
	{
		ft_free_stack(p->a_head);
		free(p);
	}
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_exit_and_free_stack(t_param *p)
{
	if (p)
	{
		ft_free_stack(p->a_head);
		free(p);
	}
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}
