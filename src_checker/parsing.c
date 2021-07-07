/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:00:33 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/07/08 00:39:14 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_split(char **split, int i_max)
{
	int	i;

	i = 0;
	if (i_max >= 0)
	{
		while (i <= i_max)
		{
			if (split[i])
				free(split[i]);
			++i;
		}
	}
	free(split);
	split = NULL;
}

void	ft_split_iter(t_param *p, char **split, char *s, char c)
{
	int		i;
	char	*head;

	i = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (!*s)
			break ;
		head = s;
		while (*s != c && *s)
		{
			if (!ft_isdigit(*s) && *s != '-' && *s != '+')
				ft_exit_and_free_split_and_stack(p, split, i - 1);
			++s;
		}
		split[i] = ft_strsdup(head, s - head);
		if (!split[i])
			ft_exit_and_free_split_and_stack(p, split, i);
		++i;
	}
	split[i] = NULL;
}

char	**ft_split_elem_from_argv(t_param *p, char const *str, char c)
{
	char	**split;
	int		total_elem_in_str;

	if (str == NULL)
		ft_exit_and_free_stack(p, PRINT_ERR);
	split = NULL;
	total_elem_in_str = ft_wordcount((char *)str, c);
	split = malloc(sizeof(*split) * (total_elem_in_str + 1));
	ft_bzero(split, total_elem_in_str);
	if (!split)
		ft_exit_failure();
	ft_split_iter(p, split, (char *)str, c);
	return (split);
}

bool	ft_twice(t_stack *node, int num)
{
	while (node)
	{
		if (node->data == num)
			return (true);
		node = node->next;
	}
	return (false);
}

void	ft_extract_split(t_param *p, char **split, int start_point)
{
	t_stack	*node;
	bool	must_exit;
	int		num;
	int		i;

	i = start_point;
	node = p->a_head;
	while (split[i])
	{
		int j;
		j = 0;
			while (split[j])
				j++;
		must_exit = false;
		num = ft_convert_str_to_num(split[i], &must_exit);
		if (must_exit == true)
			ft_exit_and_free_split_and_stack(p, split, j);
		if (ft_twice(p->a_head, num))
			ft_exit_and_free_split_and_stack(p, split, j);
		node = ft_add_nbr(num);
		ft_add_back(p->a_head, node);
		if (!node)
			ft_exit_and_free_split_and_stack(p, split, j);
		++i;
	}
	ft_free_split(split, i);
}
