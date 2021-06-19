/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:22:00 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/19 05:06:40 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# include "libft/libft.h"

# define FIRST_POSITION 1
# define RA 			1
# define RRA			2

typedef struct s_stack
{
	struct s_stack	*next;
	int				data;
}					t_stack;

/*
** 1: sa	6: ra	9:	rra
** 2: sb	7: rb	10:	rrb
** 3: ss	8: rr	11:	rrr
** 4: pa	
** 5: pb
*/
typedef struct s_param
{
	int		size;
	int		lastmove;
	t_stack	*a_head;
	t_stack	*b_head;
}			t_param;

/*
** movesets
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

/*
** node_utils
*/
void	ft_add_back(t_stack *head, t_stack *new);
void	ft_add_front(t_stack *head, t_stack *new);
t_stack	*ft_lastnode(t_stack *node);
int		ft_stacksize(t_stack *node);
t_stack	*ft_xbef_lastnode(t_param *p, int size, t_stack *node, int i);
t_stack	*ft_xnode(t_stack *node, int x);

/*
** nbr_utils
*/
t_stack	*ft_find_node_with_highest_num(t_param *p);
t_stack	*ft_find_node_with_lowest_num(t_param *p);
bool	ft_isasc(t_stack *node, int start, int end);
bool	ft_isdesc(t_stack *node, int start, int end);
bool	ft_ishighest(t_stack *node, int stacksize);
bool	ft_ishighest_inrange(t_param *p, int start, int end);
bool	ft_islowest(t_stack *node);
bool	ft_islowest_expt(t_stack *node, int n, int *t);
t_stack	*ft_nth_node(t_param *p, int n);
int		ft_stoi(t_param *p, char **split, char *str, int j);

/*
** algorithms
*/
int		ft_disordered(t_param *p, t_stack *node, int start, int end);
t_stack	*ft_find_node_with_highest_num(t_param *p);
bool	ft_isasc_between(t_param *p);
bool	ft_isdesc_between(t_param *p);
bool	ft_islowest_xbef_lastnode(t_param *p, int x);
int		*ft_lowest_nodes(t_param *p);
void	ft_sort_five_elements(t_param *p, int *disordered_position);
void	ft_sort_four_elements(t_param *p, int *disordered_position);
void	ft_sort_long_list(t_param *p, int *t);
void	ft_sort_short_list(t_param *p, int *disordered_position);
void	ft_sort_three_elements(t_param *p, int *disordered_position);

/*
** exit
*/
void	ft_exit_clearstack(t_param *p);
void	ft_exit_failure(void);
void	ft_exit_lst_tabfree(t_param *p, char **split, int size);
void	ft_exit_tabfree(char **str, int i);

bool	ft_isthere(int nbr_to_find, int *array_of_nbrs, int array_size);
char	**ft_split_errchk(char const *s, char c);
void	ft_reverse(t_param *p);

t_stack	*ft_add_nbr(int data);
#endif
