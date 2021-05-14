/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_three_less.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 18:20:47 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/04 19:00:56 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	alg_three_less(t_stack *stack, int print)
{
	int	max;
	int	min;
	int	a;
	int	b;
	int	c;

	if (sl_check_sorted(stack))
		return ;
	if (sl_get_size(stack) == 2)
	{
		sa(&stack, NULL, print);
		return ;
	}
	max = sl_get_max(stack);
	min = sl_get_min(stack);
	a = stack->value;
	b = stack->next->value;
	c = stack->next->next->value;
	if (a == max && b == min)
		ra(&stack, NULL, print);
	if ((b == min && c == max) || (a == max && c == min) || (a == min && b == max))
		sa(&stack, NULL, print);
	if (b == max && c == min)
		rra(&stack, NULL, print);
	alg_three_less(stack, print);
	return ;
}
