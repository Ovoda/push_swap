/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:57:26 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/21 12:48:21 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrb(t_stack **a, t_stack **b, int print)
{
	sl_rotate_down(b);
	(void)a;
	if (print == 1)
		ft_putstr("rrb\n");
}
