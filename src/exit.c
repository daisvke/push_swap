/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 01:50:44 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/07 14:27:40 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_exit_failure(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_exit_tabfree(char **str, int i)
{
	ft_tabfree(str, i);
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_clear_stack(t_stack *lst)
{
	t_stack	*next;

	if (!lst)
		return ;
	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
	lst = NULL;
}

void	ft_exit_lst_tabfree(t_param *p, char **split, int size)
{
	ft_tabfree(split, size);
	ft_clear_stack(p->a_first);
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}

