/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_remove_first_elem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:13:33 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/21 14:36:17 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sl_remove_first_elem(t_stack **stack)
{
	t_stack	*tmp_first;

	if (!(*stack))
		return ;
	if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
		return ;
	}
	tmp_first = *stack;
	(*stack) = (*stack)->next;
	if (tmp_first != NULL)
		free(tmp_first);
}
