/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:28:32 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/21 14:42:18 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFFER_SIZE 1024

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libsh/libsh.h"

typedef struct	s_stack
{
	struct s_stack	*next;
	int				value;
}				t_stack;

typedef struct	s_var
{
	int	value_a;
	int	value_b;
	int	index_a;
	int	index_b;
	int	size_a;
	int	size_b;
	int	total_a;
	int	total_b;
	int	is_rra;
	int	is_rrb;
	int	total_rr;
}				t_var;

typedef void	t_psf(t_stack **a, t_stack **b, int c);

int				get_next_line(int fd, char **line);
int				ps_error(void);
int				ps_ko(void);
int				ps_ok(void);
int				check_arg(char **argv);
int				ft_strisnum_orneg(char *str);
int				pre_prog(int argc, char **argv, t_stack **a);
t_stack			*sort_ref_stack(t_stack *stack);
void			alg_insert(t_stack *a);
void			alg_simple_sa_ra(t_stack *stack);
void			alg_pivot(t_stack **stack);
void			alg_three(t_stack **stack);
void			alg_five(t_stack **stack);
void			solve_second_half(t_stack **stack, t_stack **b);
int				get_pivot(t_stack *stack);
void			solve_first_half(t_stack **a, t_stack **b);
int				try_all_elems(t_stack **stack, t_stack **b, int pivot);
int				try_all_elems2(t_stack **stack, t_stack **b, int pivot);
void			pa(t_stack **a, t_stack **b, int print);
void			pb(t_stack **a, t_stack **b, int print);
void			sa(t_stack **a, t_stack **b, int print);
void			sb(t_stack **a, t_stack **b, int print);
void			ss(t_stack **a, t_stack **b, int print);
void			ra(t_stack **a, t_stack **b, int print);
void			rb(t_stack **a, t_stack **b, int print);
void			rr(t_stack **a, t_stack **b, int print);
void			rra(t_stack **a, t_stack **b, int print);
void			rrb(t_stack **a, t_stack **b, int print);
void			rrr(t_stack **a, t_stack **b, int print);
int				sl_check_sorted(t_stack *a);
int				sl_get_index(t_stack *stack, int elem);
int				sl_get_last(t_stack *stack);
int				sl_get_elem_at_index(t_stack *stack, int index);
t_stack			*sl_stackdup(t_stack *stack);
void			sl_push_back(t_stack **stack, t_stack *elem);
int				sl_check_error_stack(t_stack *stack);
int				sl_get_min(t_stack *stack);
int				sl_get_max(t_stack *stack);
int				sl_get_size(t_stack *stack);
void			sl_push_front(t_stack **stack, t_stack *elem);
void			sl_print_stack(t_stack *stack);
void			sl_free_stack(t_stack *stack);
t_stack			*sl_create_elem(int value);
t_stack			*sl_tab_to_stack(char **argv);
void			sl_rotate_up(t_stack **stack);
void			sl_rotate_down(t_stack **stack);
void			sl_swap_first_two(t_stack **stack);
t_stack			*sl_last_elem(t_stack *stack);
void			sl_remove_first_elem(t_stack **stack);
void			sl_push(t_stack **a, t_stack **b);
t_var			check_rr_or_r(t_var var, int index_b);
t_var			count_rr_rrr(t_var var, int index_b);
#endif
