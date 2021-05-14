/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 12:11:50 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/14 09:46:12 by calide-n         ###   ########.fr       */
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

int	get_nb_step(t_stack *b, int pivot, int min)
{
	t_stack *a;
	int		step_1;
	int		step_2;

	step_1 = 0;
	step_2 = 0;
	a = sl_stackdup(b);
	while (a->value != min && a->value < pivot)
	{
		ra(&a, NULL, 0);
		step_1++;
	}
	//printf("value [%d] in [%d] steps\n", a->value, step_1);
	a = sl_stackdup(b);
	while (a->value != min && a->value < pivot)
	{
		rra(&a, NULL, 0);
		step_2++;
	}
	//printf("value [%d] in [%d] steps\n", a->value, step_2);
	if (step_1 <= step_2)
		return (1);
	return (2);
}

int		empty_b(t_stack **stack, t_stack **b)
{
	int		pivot;
	int		size;
	int		min;
	int		max;
	int		trigger;

	if (!(*b))
		return (0);
	size = sl_get_size(*b);
	pivot = get_pivot(*b);
	max = 0;
	trigger = 0;
	int	nb = 0;
	int step;
	while ((*b))
	{
		min = sl_get_min(*b);
		step = get_nb_step(*b, pivot, min);
		if ((*b)->value >= pivot)
		{
			if (trigger == 0)
			{
				trigger = 1;
				max = (*b)->value;
			}
			pa(stack, b, 1);
		}
		else if ((*b)->value == min) 
		{
			pa(stack, b, 1);
			if (step == 1 && *b)
				rr(stack, b, 1);
			else
				ra(stack, b, 1);
			nb++;
		}
		else 
		{
			if (step == 1)
				rb(stack, b, 1);
			if (step == 2)
				rrb(stack, b, 1);
		}
	//	sl_print_stack(*b);
		nb++;
	}
	//printf("nb -> %d\n", nb);
	return (max);
}

int	get_nb_step2(t_stack *b, int max, int min)
{
	t_stack *a;
	int		step_1;
	int		step_2;

	step_1 = 0;
	step_2 = 0;
	a = sl_stackdup(b);
	while (a->value != min && a->value != max)
	{
		ra(&a, NULL, 0);
		step_1++;
	}
	//printf("value [%d] in [%d] steps\n", a->value, step_1);
	a = sl_stackdup(b);
	while (a->value != min && a->value != max)
	{
		rra(&a, NULL, 0);
		step_2++;
	}
	//printf("value [%d] in [%d] steps\n", a->value, step_2);
	if (step_1 <= step_2)
		return (1);
	return (2);
}

int		empty_b2(t_stack **stack, t_stack **b)
{
	int		pivot;
	int		size;
	int		min;
	int		max;

	if (!(*b))
		return (0);
	size = sl_get_size(*b);
	pivot = get_pivot(*b);
	int step;
	while ((*b))
	{
		min = sl_get_min(*b);
		max = sl_get_max(*b);
		step = get_nb_step2(*b, max, min);
		if ((*b)->value == max)
			pa(stack, b, 1);
		else if ((*b)->value == min) 
		{
			pa(stack, b, 1);
			if (step == 1 && *b)
				rr(stack, b, 1);
			else
				ra(stack, b, 1);
		}
		else 
		{
			if (step == 1)
				rb(stack, b, 1);
			if (step == 2)
				rrb(stack, b, 1);
		}
	}
	return (max);
}

void	solve_first_half(t_stack **stack, t_stack **b)
{
	int	size;
	int	pivot;
	int	max;
	int	min;

	size = sl_get_size(*stack) + 1;
	pivot = get_pivot(*stack);
	while (size--)
	{
		if ((*stack)->value < pivot)
			pb(stack, b, 1);
		else
			ra(stack, b, 1);
	}
	max = empty_b(stack, b);

	while ((*stack)->value != max)
		pb(stack, b, 1);
	pb(stack, b, 1);
	max = empty_b(stack, b);

	while ((*stack)->value != max)
		pb(stack, b, 1);
	pb(stack, b, 1);
	max = empty_b2(stack, b);

	while ((*stack)->value <= pivot)
		ra(stack, b, 1);
}

void	alg_pivot(t_stack *stack)
{
	int		pivot;
	int		new_pivot;
	int		size;
	int		max;
	int		min;
	t_stack	*b;

	b = NULL;
	pivot = get_pivot(stack);
	solve_first_half(&stack, &b);
	min = sl_get_min(stack);

	while (stack->value != min)
		pb(&stack, &b, 1);
	max = empty_b(&stack, &b);

	while ((stack)->value != max)
		pb(&stack, &b, 1);
	pb(&stack, &b, 1);
	max = empty_b(&stack, &b);

	while ((stack)->value != max)
		pb(&stack, &b, 1);
	pb(&stack, &b, 1);
	max = empty_b2(&stack, &b);

	while ((stack)->value != min)
		ra(&stack, &b, 1);

	sl_print_stack(stack);
	sl_print_stack(b);
}
