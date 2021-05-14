/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_rotate_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:13:33 by calide-n          #+#    #+#             */
/*   Updated: 2021/04/24 16:03:53 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sl_rotate_down(t_stack **stack)
{
	t_stack	*tmp_stack;
	t_stack	*last_elem;

	if (!(*stack) || !(*stack)->next)
		return ;
	last_elem = sl_last_elem(*stack);
	tmp_stack = (*stack);
	while (tmp_stack)
	{
		if (!tmp_stack->next->next)
			break;
		tmp_stack = tmp_stack->next;
	}
	tmp_stack->next = NULL;
	last_elem->next = (*stack);
	(*stack) = last_elem;
}
