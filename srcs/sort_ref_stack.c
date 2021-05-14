/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ref_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 12:15:15 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/04 18:52:21 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*sort_ref_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*res;
	int		max;

	res = NULL;
	tmp = NULL;
	tmp = sl_stackdup(stack);
	while (tmp)
	{
		max = sl_get_max(tmp);
		while (tmp->value != max)
			ra(&tmp, NULL, 0);
		pb(&tmp, &res, 0);
	}
	sl_free_stack(tmp);
	return (res);
}
