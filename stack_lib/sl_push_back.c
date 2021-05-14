/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:19:08 by calide-n          #+#    #+#             */
/*   Updated: 2021/04/21 15:21:59 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sl_push_back(t_stack **stack, t_stack *elem)
{
	t_stack	*tmp_stack;

	if (!(*stack))
		*stack = elem;
	else
	{
		tmp_stack = (*stack);
		while (tmp_stack->next)
		{
			tmp_stack = tmp_stack->next;
		}
		tmp_stack->next = elem;
	}
}

