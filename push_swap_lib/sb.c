/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:57:26 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/21 12:48:31 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb(t_stack **a, t_stack **b, int print)
{
	(void)a;
	sl_swap_first_two(b);
	if (print == 1)
		ft_putstr("sb\n");
}
