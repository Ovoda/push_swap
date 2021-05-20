/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_get_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 10:59:05 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/20 14:44:46 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sl_get_last(t_stack *stack)
{
	t_stack	*tmp_stack;

	tmp_stack = stack;
	while (tmp_stack->next)
		tmp_stack = tmp_stack->next;
	return (tmp_stack->value);
}
