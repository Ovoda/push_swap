/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_push_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:19:08 by calide-n          #+#    #+#             */
/*   Updated: 2021/04/24 16:02:06 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sl_push_front(t_stack **stack, t_stack *elem)
{
	if (!(*stack))
		*stack = elem;
	else
	{
		elem->next = (*stack);
		(*stack) = elem;
	}
}

