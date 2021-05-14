/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:06:09 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/02 11:16:55 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sl_check_sorted(t_stack *a)
{
	t_stack	*tmp;

	if (!(a) || !(a->next))
		return (1);
	tmp = a;
	while (tmp->next)
	{
		if (tmp->next->value < tmp->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
