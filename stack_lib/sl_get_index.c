/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_get_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:43:26 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/18 19:51:59 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sl_get_index(t_stack *stack, int elem)
{
	int		index;
	t_stack	*tmp_stack;

	index = 0;
	tmp_stack = stack;
	while (tmp_stack)
	{
		if (tmp_stack->value == elem)
			return (index);
		index++;
		tmp_stack = tmp_stack->next;
	}
	return (-1);
}
