/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_stackdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 12:27:28 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/02 12:31:16 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*sl_stackdup(t_stack *stack)
{
	t_stack	*dup;
	t_stack	*tmp;
	t_stack	*elem;

	dup = NULL;
	elem = NULL;
	if (!stack)
		return (NULL);
	tmp = stack;
	while (tmp)
	{
		elem = sl_create_elem(tmp->value);
		sl_push_back(&dup, elem);
		tmp = tmp->next;
	}
	return (dup);
}
