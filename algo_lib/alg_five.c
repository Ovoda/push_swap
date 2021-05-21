/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_five.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 18:20:47 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/21 16:51:45 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_till_min(t_stack **a, t_stack **b, int limit)
{
	int	min;
	int	index;

	min = sl_get_min(*a);
	index = sl_get_index(*a, min);
	if (index > limit)
		while ((*a)->value != min)
			rra(a, NULL, 1);
	else
		while ((*a)->value != min)
			ra(a, NULL, 1);
	pb(a, b, 1);
}

void	alg_five(t_stack **stack)
{
	t_stack	*b;

	b = NULL;
	rotate_till_min(stack, &b, 3);
	rotate_till_min(stack, &b, 2);
	alg_three(stack);
	pa(stack, &b, 1);
	pa(stack, &b, 1);
	return ;
}
