/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_error_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 10:25:13 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/02 10:42:26 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sl_check_error_stack(t_stack *stack)
{
	t_stack	*slow;
	t_stack	*fast;

	slow = stack;
	while (slow)
	{
		if (slow->next)
		{
			fast = slow->next;
			while (fast)
			{
				if (fast->value == slow->value)
					return (0);
				fast = fast->next;
			}
		}
		slow = slow->next;
	}
	return (1);
}
