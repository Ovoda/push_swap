/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:28:32 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/04 19:00:43 by calide-n         ###   ########.fr       */
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

// SRCS
int		get_next_line(int fd, char **line);
int		ps_error();
int		ps_ko();
int		ps_ok();
t_stack	*sort_ref_stack(t_stack *stack);

// ALGORITHMS
void	alg_simple_sa_ra(t_stack *stack);
void	alg_pivot(t_stack *stack);
void	alg_three_less(t_stack *stack, int print);

// PUSH_SWAP LIB
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);
void	sa(t_stack **a, t_stack **b, int print);
void	sb(t_stack **a, t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
void	ra(t_stack **a, t_stack **b, int print);
void	rb(t_stack **a, t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, t_stack **b, int print);
void	rrb(t_stack **a, t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

// STACK LIB

int		sl_check_sorted(t_stack *a);
t_stack	*sl_stackdup(t_stack *stack);
void	sl_push_back(t_stack **stack, t_stack *elem);
int		sl_check_error_stack(t_stack *stack);
int		sl_get_min(t_stack *stack);
int		sl_get_max(t_stack *stack);
int		sl_get_size(t_stack *stack);
void	sl_push_front(t_stack **stack, t_stack *elem);
void	sl_print_stack(t_stack *stack);
void	sl_free_stack(t_stack *stack);
t_stack	*sl_create_elem(int value);
t_stack	*sl_tab_to_stack(char **argv);
void	sl_rotate_up(t_stack **stack);
void	sl_rotate_down(t_stack **stack);
void    sl_swap_first_two(t_stack **stack);
t_stack	*sl_last_elem(t_stack *stack);
void    sl_remove_first_elem(t_stack **stack);
void    sl_push(t_stack **a, t_stack **b);

#endif
