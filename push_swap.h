/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:22:00 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/07 04:45:34 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

# define ERROR 1
# define SUCCESS 0

typedef struct s_stack
{
	struct s_stack	*nxt;
	int				data;
}					t_stack;

typedef struct s_param
{
	int		size;
	t_stack	**a_start;
	t_stack	*a_end;
	t_stack	*b_start;
	t_stack	*b_end;
}			t_param;

void	ft_exit_failure(void);
void	ft_exit_lst_tabfree(t_param *p, char **split, int size);
void	ft_exit_tabfree(char **str, int i);
char	**ft_split_errcheck(char const *s, char c);

#endif
