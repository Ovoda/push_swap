/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_simple_sa_ra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 10:56:08 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/04 18:54:11 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	alg_simple_sa_ra(t_stack *stack)
{
	t_stack	*tmp_stack;
	t_stack	*b;
	int		smallest;

	b = NULL;
	smallest = sl_get_min(stack);
	tmp_stack = stack;
	while (1)
	{
		if (stack->value > stack->next->value && stack->next->value != smallest)
		{
			sa(&stack, &b, 0);
			if (sl_check_sorted(stack))
				break ;
		}
		ra(&stack, &b, 0);
		if (sl_check_sorted(stack))
			break ;
	}
}
