/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:22:00 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/31 02:36:37 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_stack
{
	struct s_stack	*nxt;
	int				n;
}					t_stack;

typedef struct s_param
{
	int				size;
	struct s_stack	a_start;
	struct s_stack	a_end;
	struct s_stack	b_start;
	struct s_stack	b_end;
}					t_param;
