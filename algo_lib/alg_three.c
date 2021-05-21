/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:20:18 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/21 14:41:07 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	alg_three(t_stack **stack)
{
	int	max;
	int	min;
	int	a[3];

	if (sl_check_sorted(*stack))
		return ;
	if (sl_get_size(*stack) == 2)
	{
		sa(stack, NULL, 1);
		return ;
	}
	max = sl_get_max(*stack);
	min = sl_get_min(*stack);
	a[0] = (*stack)->value;
	a[1] = (*stack)->next->value;
	a[2] = (*stack)->next->next->value;
	if (a[0] == max && a[1] == min)
		ra(stack, NULL, 1);
	if ((a[1] == min && a[2] == max) || (a[0] == max && a[2] == min) ||
		(a[0] == min && a[1] == max))
		sa(stack, NULL, 1);
	if (a[1] == max && a[2] == min)
		rra(stack, NULL, 1);
	alg_three(stack);
	return ;
}
