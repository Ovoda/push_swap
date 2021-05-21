/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:50:47 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/21 16:50:02 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack **stack_a)
{
	int	size;

	size = sl_get_size(*stack_a);
	if (size <= 1)
		return ;
	if (size == 2)
		sa(stack_a, NULL, 1);
	if (size == 3)
		alg_three(stack_a);
	if (size <= 5 && size > 3)
		alg_five(stack_a);
	if (size > 5)
		alg_pivot(stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (pre_prog(argc, argv, &stack_a) != 1)
		return (0);
	if (sl_check_sorted(stack_a))
	{
		sl_free_stack(stack_a);
		return (0);
	}
	push_swap(&stack_a);
	sl_free_stack(stack_a);
	return (0);
}
