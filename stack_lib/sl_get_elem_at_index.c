/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_get_elem_at_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:43:26 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/21 11:40:26 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sl_get_elem_at_index(t_stack *stack, int index)
{
	t_stack	*tmp_stack;

	tmp_stack = stack;
	while (index--)
	{
		if (tmp_stack)
			tmp_stack = tmp_stack->next;
		else
			return (0);
	}
	return (tmp_stack->value);
}
