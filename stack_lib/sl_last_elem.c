/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_last_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:37:06 by calide-n          #+#    #+#             */
/*   Updated: 2021/04/21 17:19:56 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*sl_last_elem(t_stack *stack)
{
	t_stack	*tmp_stack;

	tmp_stack = stack;
	while (tmp_stack->next)
		tmp_stack = tmp_stack->next;
	return (tmp_stack);
}
