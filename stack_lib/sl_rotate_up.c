/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_rotate_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:13:33 by calide-n          #+#    #+#             */
/*   Updated: 2021/04/24 16:04:24 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sl_rotate_up(t_stack **stack)
{
	t_stack	*tmp_stack;
	t_stack	*first_elem;

	if (!(*stack) || !(*stack)->next)
		return ;
	first_elem = (*stack);
	(*stack) = (*stack)->next;
	first_elem->next = NULL;
	tmp_stack = sl_last_elem(*stack);
	tmp_stack->next = first_elem;
}
