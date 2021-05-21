/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_pivot_try_elem2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:00:18 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/21 14:21:12 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_top_a2(t_stack *a, int b, int pivot)
{
	t_stack	*tmp_a;
	int		last;
	int		res;

	tmp_a = sl_stackdup(a);
	if (a->value > b)
	{
		last = sl_get_last(tmp_a);
		while (last != pivot && last > b)
		{
			rra(&tmp_a, NULL, 0);
			last = sl_get_last(tmp_a);
		}
	}
	else
	{
		while (tmp_a->value < b && tmp_a->value > pivot)
			ra(&tmp_a, NULL, 0);
	}
	res = tmp_a->value;
	sl_free_stack(tmp_a);
	return (res);
}

t_var	init_var2(t_stack **a, t_stack **b, int index_b, int pivot)
{
	t_var	var;

	var.size_a = sl_get_size(*a);
	var.size_b = sl_get_size(*b);
	var.value_b = sl_get_elem_at_index(*b, index_b);
	var.value_a = get_top_a2(*a, var.value_b, pivot);
	var.index_a = sl_get_index(*a, var.value_a);
	var.is_rra = 0;
	var.is_rrb = 0;
	return (var);
}

int		count_step_to_get_right_pos2(t_stack **a, t_stack **b,
		int pivot_index[2], int print)
{
	t_var	var;

	var = init_var2(a, b, pivot_index[1], pivot_index[0]);
	var = count_rr_rrr(var, pivot_index[1]);
	if (print == 0)
		return (var.total_a + var.total_b + var.total_rr);
	if (var.is_rra == 0 && var.is_rrb == 0)
		while (var.total_rr--)
			rr(a, b, 1);
	if (var.is_rra == 1 && var.is_rrb == 1)
		while (var.total_rr--)
			rrr(a, b, 1);
	if (var.is_rra == 1)
		while (var.total_a--)
			rra(a, b, 1);
	if (var.is_rra == 0)
		while (var.total_a--)
			ra(a, b, 1);
	if (var.is_rrb == 1)
		while (var.total_b--)
			rrb(a, b, 1);
	if (var.is_rrb == 0)
		while (var.total_b--)
			rb(a, b, 1);
	return (0);
}

int		count_steps2(t_stack **stack, t_stack **b, int pivot_index[2])
{
	t_stack	*tmp_b;
	t_stack	*tmp_a;
	int		ret;

	tmp_a = sl_stackdup(*stack);
	tmp_b = sl_stackdup(*b);
	ret = count_step_to_get_right_pos2(&tmp_a, &tmp_b, pivot_index, 0);
	sl_free_stack(tmp_a);
	sl_free_stack(tmp_b);
	return (ret);
}

int		try_all_elems2(t_stack **stack, t_stack **b, int pivot)
{
	int		size;
	int		min[3];
	int		pivot_index[2];

	pivot_index[0] = pivot;
	pivot_index[1] = 0;
	size = sl_get_size(*b);
	min[0] = -1;
	while (pivot_index[1] < size)
	{
		min[1] = count_steps2(stack, b, pivot_index);
		if (min[1] < min[0] || min[0] == -1)
		{
			min[0] = min[1];
			min[2] = pivot_index[1];
		}
		if ((min[0] <= (sl_get_size(*stack) + size) / 60 &&
			(sl_get_size(*stack) + size) > 400) || min[0] <= 1)
			break ;
		pivot_index[1]++;
	}
	pivot_index[1] = min[2];
	count_step_to_get_right_pos2(stack, b, pivot_index, 1);
	return (min[0]);
}
