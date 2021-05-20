/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 12:11:50 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/20 16:17:31 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_pivot(t_stack *stack)
{
	int		stack_size;
	t_stack	*sorted;

	sorted = sort_ref_stack(stack);
	stack_size = sl_get_size(sorted) / 2;
	while (stack_size)
	{
		sorted = sorted->next;
		stack_size--;
	}
	return (sorted->value);
}

void	new_empty_b(t_stack **stack, t_stack **b, t_stack *sorted, int pivot)
{
	int	last_pushed;
	t_stack	*last;
	int	tbp;
	int total = 0;

	pa(stack, b, 1);
	while (*b)
	{
		try_all_elems(stack, b, pivot);
		pa(stack, b, 1);
	}
}


void	solve_first_half1(t_stack **stack, t_stack **b)
{
	int	size;
	int	pivot;
	int	pivot_b;
	int	max;
	int	min;

	t_stack	*sorted = sl_stackdup(*stack);
	sorted = sort_ref_stack(sorted);
	size = sl_get_size(*stack);
	pivot = get_pivot(*stack);
	while (sl_get_size(*b) < (size / 2) + 1)
	{
		if ((*stack)->value <= pivot)
			pb(stack, b, 1);
		else
			ra(stack, b, 1);
	}
	new_empty_b(stack, b, sorted, pivot);
	while ((*stack)->value <= pivot)
		ra(stack, b, 1);
}

void	alg_pivot(t_stack *stack)
{
	t_stack	*b;
	int	pivot;
	pivot = get_pivot(stack);

	b = NULL;
	solve_first_half1(&stack, &b);
	int	min = sl_get_min(stack);
	while (stack->value > min)
		pb(&stack, &b, 1);
	pa(&stack, &b, 1);
	while (b)
	{
		try_all_elems2(&stack, &b, pivot);
		pa(&stack, &b, 1);
	}
	min = sl_get_min(stack);
	while (stack->value > min)
		ra(&stack, NULL, 1);
	sl_print_stack(stack);
	sl_print_stack(b);
}
