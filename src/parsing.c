/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:00:33 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/07 04:09:17 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_split_iter(char **split, char *s, char c)
{
	int		i;
	char	*start;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;

		start = s;
		while (*s != c && *s)
		{
			if (!ft_isdigit(*s))
				ft_exit_tabfree(split, i);
			s++;
		}
		split[i] = ft_strsdup(start, s - start);
		if (!split[i])
			ft_exit_tabfree(split, i);
		i++;
	}
	split[i] = 0;
}

char	**ft_split_errcheck(char const *s, char c)
{
	char	**split;

	if (!s)
		return (malloc(0));
	split = (char **)malloc(sizeof(*split) * (ft_wordcount((char *)s, c) + 1));
	if (!split)
		ft_exit_failure();
	ft_split_iter(split, (char *)s, c);
	return (split);
}
