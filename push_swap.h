/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:22:00 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/07/08 03:17:19 by dtanigaw         ###   ########.fr       */
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
# define A			0
# define B			1

/*
** moves
*/
# define SA			0
# define SB			1
# define PA			2
# define PB			3
# define RA			4
# define RB			5
# define RRA		6
# define RRB		7

/*
** exit
*/
# define PRINT_ERR	1

/*
** checker
*/
# define SANE		1

/*
** linked list for stacks
*/
typedef struct s_stack
{
	struct s_stack	*next;
	int				data;
}					t_stack;

/*
** linked list parameters
*/
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
** init
*/
void	ft_find_in_stack_and_replace(t_param *p, int *nbrs_to_replace_with, \
	int array_size);
char	*ft_get_arg_with_num(char **args, int pos, int *i);
t_param	*ft_init_param_with_first_node(char **split, int i);
t_param	*ft_init_param_with_stack(char **args, int size);
void	ft_simplify_stack_num_values(t_param *p, int size);

/*
** parsing
*/
size_t	ft_count_split_len(char **split);
bool	ft_elem_appears_multiple_times(t_stack *node, int num);
void	ft_extract_split(t_param *p, char **split, int start_point);
void	ft_free_split(char **split, int i_max);
char	**ft_split_elem_from_argv(t_param *p, char const *s, char c);

/*
** moves
*/
void	ft_execute_pa(t_param *p, t_stack *a, t_stack *b, bool print_command);
void	ft_execute_pb(t_param *p, t_stack *a, t_stack *b, bool print_command);
void	ft_execute_ra(t_param *p, t_stack *head, t_stack *tail, \
	bool print_command);
void	ft_execute_rb(t_param *p, t_stack *head, t_stack *tail, \
	bool print_command);
void	ft_execute_rra(t_param *p, t_stack *head, t_stack *tail, \
	bool print_command);
void	ft_execute_rrb(t_param *p, t_stack *head, t_stack *tail, \
	bool print_command);
void	ft_execute_sa(t_param *p, t_stack *node1, t_stack *node2, \
	bool print_command);
void	ft_execute_sb(t_param *p, t_stack *node1, t_stack *node2, \
	bool print_command);

/*
** utils for linked list
*/
void	ft_add_front(t_stack *head, t_stack *new);
void	ft_add_back(t_stack *head, t_stack *new);
t_stack	*ft_lastnode(t_stack *node);
int		ft_stacksize(t_stack *node);
t_stack	*ft_second_to_lastnode(t_param *p, int which_stack);

/*
** utils for numbers
*/
t_stack	*ft_add_nbr(int data);
t_stack	*ft_find_node_with_highest_num(t_param *p);
bool	ft_is_in_the_right_order(t_stack *node, int start, int end);
bool	ft_is_in_the_inverse_order(t_stack *node, int start, int end);
bool	ft_ishighest_in_stack(t_stack *head, int value_to_check);
bool	ft_ishighest_inrange(t_param *p, int start, int end);
bool	ft_islowest_in_stack(t_stack *head, int value_to_check);
int		ft_convert_str_to_num(char *str, bool *must_exit);

/*
** algorithms
*/
int		ft_evaluate_fastest_op(t_param *p, int min_position);
void	ft_execute_command(t_param *p, int command);
t_stack	*ft_find_node_with_highest_num(t_param *p);
int		ft_find_nth_lowest_node_position(t_param *p, int nth_lowest);
bool	ft_isthere(int nbr_to_find, int *array_of_nbrs, int array_size);
void	ft_push_back_from_b_to_a(t_param *p);
void	ft_ra_until_reach_min(t_param *p, int min_position);
void	ft_execute_lowests_sort(t_param *p);
void	ft_execute_radix_sort(t_param *p);
void	ft_rra_until_reach_min(t_param *p, int min_position);
void	ft_sort_stack_b_with_short_list(t_param *p);
void	ft_sort_three_elements(t_param *p);
void	ft_swap_top_if_needed(t_param *p);

/*
** exit
*/
void	ft_free_stack(t_stack *node);
void	ft_exit_and_free_split(char **split, int i);
void	ft_exit_and_free_stack(t_param *p, bool print_error);
void	ft_exit_failure(void);
void	ft_exit_and_free_split_and_stack(t_param *p, char **split, int i);

/*
** checker
*/
char	**ft_init_array_of_commands(void);

#endif
