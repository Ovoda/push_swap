/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:37:06 by calide-n          #+#    #+#             */
/*   Updated: 2021/04/21 17:11:39 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sl_free_stack(t_stack *stack)
{
	t_stack	*tmp_stack;

	if (!stack)
		return ;
	while (stack)
	{
		tmp_stack = stack;
		stack = stack->next;
		free(tmp_stack);
	}
}
