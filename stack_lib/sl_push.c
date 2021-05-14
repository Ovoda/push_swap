/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:13:33 by calide-n          #+#    #+#             */
/*   Updated: 2021/04/22 12:19:12 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sl_push(t_stack **a, t_stack **b)
{
	int		tmp_first_value;
	t_stack	*elem;

	if (!(*a))
		return ;
	tmp_first_value = (*a)->value;
	elem = sl_create_elem(tmp_first_value);
	sl_remove_first_elem(a);
	sl_push_front(b, elem);
}
