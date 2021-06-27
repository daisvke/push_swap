/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:00:33 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/27 02:27:04 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_split_iter(char **split, char *s, char c)
{
	int		i;
	char	*head;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;

		head = s;
		while (*s != c && *s)
		{
			if (!ft_isdigit(*s) && *s != '-' && *s != '+')
				ft_exit_and_free_array(split, i);
			s++;
		}
		split[i] = ft_strsdup(head, s - head);
		if (!split[i])
			ft_exit_and_free_array(split, i);
		i++;
	}
	split[i] = NULL;
}

char	**ft_split_elem_from_argv(char const *s, char c)
{
	char	**split;
	int		elem_num_in_str;

	if (!s)
		return (malloc(0));
	elem_num_in_str = ft_wordcount((char *)s, c);
	split = (char **)malloc(sizeof(*split) * (elem_num_in_str + 1));
	ft_bzero(split, elem_num_in_str); 
	if (!split)
		ft_exit_failure();
	ft_split_iter(split, (char *)s, c);
	return (split);
}
