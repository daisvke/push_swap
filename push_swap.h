/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:22:00 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/09 04:18:29 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# include "libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int				data;
}					t_stack;

typedef struct s_param
{
	int		size;
	t_stack	*a_head;
	t_stack	*b_head;
}			t_param;

/*
** Moves
*/
void	ft_pa(t_param *p, t_stack *a, t_stack *b, bool w);
void	ft_pb(t_param *p, t_stack *a, t_stack *b, bool w);
void	ft_ra(t_param *p, t_stack *head, t_stack *tail, bool w);
void	ft_rb(t_param *p, t_stack *head, t_stack *tail, bool w);
void	ft_rr(t_param *p, t_stack *ah, t_stack *at, t_stack *bh, t_stack *bt);
void	ft_rra(t_param *p, t_stack *head, t_stack *tail, bool w);
void	ft_rrb(t_param *p, t_stack *head, t_stack *tail, bool w);
void	ft_rrr(t_param *p, t_stack *ah, t_stack *at, t_stack *bh, t_stack *bt);
void	ft_sa(t_param *p, t_stack *node1, t_stack *node2, bool w);
void	ft_sb(t_param *p, t_stack *node1, t_stack *node2, bool w);
void	ft_ss(t_param *p, t_stack *a1, t_stack *a2, t_stack *b1, t_stack *b2);

void	ft_add_back(t_stack *head, t_stack *new);
void	ft_add_front(t_stack *head, t_stack *new);
t_stack	*ft_add_nbr(int data);
void	ft_exit_clearstack(t_param *p);
void	ft_exit_failure(void);
void	ft_exit_lst_tabfree(t_param *p, char **split, int size);
void	ft_exit_tabfree(char **str, int i);
bool	ft_ishighest(t_stack *node, int n);
char	**ft_split_errchk(char const *s, char c);
t_stack	*ft_lastnode(t_stack *node);
int		ft_stacksize(t_stack *node);
int		ft_stoi(t_param *p, char **split, char *str, int j);
t_stack	*ft_xbef_lastnode(t_param *p, int size, t_stack *node, int i);

#endif
