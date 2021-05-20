/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_pivot_try_elem2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:00:18 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/20 16:17:00 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_top_a2(t_stack *a, int b, int pivot)
{
	t_stack	*tmp_a;
	int		last;

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
	return (tmp_a->value);
}

int	count_step_to_get_right_pos2(t_stack **a, t_stack **b, int pivot, int index_b, int print)
{
	int value_a;
	int	value_b;
	int	index_a;
	int	size_a;
	int	size_b;

	size_a = sl_get_size(*a);
	size_b = sl_get_size(*b);
	value_b = sl_get_elem_at_index(*b, index_b);
//	printf("\n----\ntrying for [%d] at index [%d]\n", value_b, index_b);
	value_a = get_top_a2(*a, value_b, pivot);
	index_a = sl_get_index(*a, value_a);
	
//	printf("I found that for [%d] stack A top needs to be [%d] which index is [%d]\n", value_b, value_a, index_a);

	int	total_a;
	int	total_b;
	int	is_rra;
	int	is_rrb;
	int	total_rr;

	is_rra = 0;
	is_rrb = 0;
	if (index_a > size_a / 2)
	{
		total_a = size_a - index_a;
		is_rra = 1;
	}
	else
		total_a = index_a;

	if (index_b > size_b / 2)
	{
		total_b = size_b - index_b;
		is_rrb = 1;
	}
	else
		total_b = index_b;

	total_rr = 0;
	if ((is_rra == 0 && is_rrb == 0) || (is_rra == 1 && is_rrb == 1))
	{
		if (total_a > total_b)
			total_rr = total_b;
		else
			total_rr = total_a;
		total_a -= total_rr;
		total_b -= total_rr;
	}

//	printf("Total ope = ra/rra[%d] + rb/rrb[%d] + rr/rrr[%d] + pa = %d\n----\n", total_a, total_b, total_rr, total_a + total_b + total_rr + 1);

//	if (total_a + total_b + total_rr > 25)
//		printf("\n\n\n\n\n\n\n\n\nHEEEEEREREREREEERRE\n\n\n\n\n\n\n\n\n");
	if (print == 1)
	{
		if (is_rra == 0 && is_rrb == 0)
			while (total_rr--)
				rr(a, b, 1);
		if (is_rra == 1 && is_rrb == 1)
			while (total_rr--)
				rrr(a, b, 1);
		if (is_rra == 1)
			while (total_a--)
				rra(a, b, 1);
		if (is_rra == 0)
			while (total_a--)
				ra(a, b, 1);
		if (is_rrb == 1)
			while (total_b--)
				rrb(a, b, 1);
		if (is_rrb == 0)
			while (total_b--)
				rb(a, b, 1);
	}
	return (total_a + total_b + total_rr);
}

int	try_all_elems2(t_stack **stack, t_stack **b, int pivot)
{
	int		size;
	int		index;
	t_stack	*tmp_b;
	t_stack	*tmp_a;
	int		min[3];

	index = 0;
	size = sl_get_size(*b);
	min[0] = -1;
	while (index < size)
	{
		tmp_a = sl_stackdup(*stack);
		tmp_b = sl_stackdup(*b);
		min[1] = count_step_to_get_right_pos2(&tmp_a, &tmp_b, pivot, index, 0);
		if (min[1] < min[0] || min[0] == -1)
		{
			min[0] = min[1];
			min[2] = index;
		}
		free(tmp_a);
		free(tmp_b);
		index++;
	}
	count_step_to_get_right_pos2(stack, b, pivot, min[2], 1);
	return (min[0]);
}
