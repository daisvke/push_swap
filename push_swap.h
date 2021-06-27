/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:22:00 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/27 11:11:51 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# include "libft/libft.h"

/*
** start position
*/
# define FIRST_POS	1

/*
** stacks
*/
# define A			1
# define B			2

/*
** moves
*/
# define SA			1
# define SB			2
# define PA			3
# define PB			4

# define RA			5
# define RB		6
# define RRA			7
# define RRB			8

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
** for testing purpose
*/
void	ft_printnode(t_param *p);

/*
** movesets
*/
void	ft_pa(t_param *p, t_stack *a, t_stack *b, bool w);
void	ft_pb(t_param *p, t_stack *a, t_stack *b, bool w);
void	ft_ra(t_param *p, t_stack *head, t_stack *tail, bool w);
void	ft_rb(t_param *p, t_stack *head, t_stack *tail, bool w);
void	ft_rra(t_param *p, t_stack *head, t_stack *tail, bool w);
void	ft_rrb(t_param *p, t_stack *head, t_stack *tail, bool w);
void	ft_sa(t_param *p, t_stack *node1, t_stack *node2, bool w);
void	ft_sb(t_param *p, t_stack *node1, t_stack *node2, bool w);

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
bool	ft_is_in_the_right_order(t_stack *node, int start, int end);
bool	ft_is_in_the_inverse_order(t_stack *node, int start, int end);
bool	ft_ishighest_in_stack(t_stack *head, int value_to_check);
bool	ft_ishighest_inrange(t_param *p, int start, int end);
bool	ft_islowest_in_stack(t_stack *head, int value_to_check);
bool	ft_islowest_expt(t_stack *node, int n, int *t);
t_stack	*ft_nth_node(t_param *p, int n);
int		ft_convert_str_to_num(t_param *p, char **split, char *str, int i);

/*
** algorithms
*/
int		ft_disordered(t_param *p, t_stack *node, int start, int end);
int		ft_evaluate_fastest_op(t_param *p, int min_position);
void	ft_execute_median_sort(t_param *p);
t_stack	*ft_find_node_with_highest_num(t_param *p);
int		ft_find_nth_lowest_node_position(t_param *p, int nth_lowest);
bool	ft_is_in_the_right_order_between(t_param *p);
bool	ft_is_in_the_inverse_order_between(t_param *p);
bool	ft_islowest_xbef_lastnode(t_param *p, int x);
int		*ft_lowest_nodes(t_param *p);
void	ft_push_back_from_b_to_a(t_param *p);
void	ft_ra_until_reach_min(t_param *p, int min_position);
void	ft_execute_lowests_sort(t_param *p);
void	ft_execute_radix_sort(t_param *p);
void	ft_rra_until_reach_min(t_param *p, int min_position);
void	ft_sort_stack_b_with_short_list(t_param *p);
void	ft_sort_three_elements(t_param *p, int which_stack);
void	ft_sort_two_elements(t_param *p, int which_stack);
void	ft_swap_top_if_needed(t_param *p, int which_stack);

/*
** exit
*/
void	ft_free_stack(t_stack *node);
void	ft_exit_and_free_stack(t_param *p);
void	ft_exit_failure(void);
void	ft_exit_and_free_array_and_stack(t_param *p, char **split, int size);
void	ft_exit_and_free_array(char **str, int i);

bool	ft_isthere(int nbr_to_find, int *array_of_nbrs, int array_size);
char	**ft_split_elem_from_argv(char const *s, char c);
void	ft_reverse(t_param *p);

t_stack	*ft_add_nbr(int data);
#endif
