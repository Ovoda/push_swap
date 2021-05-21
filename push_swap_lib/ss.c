/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:57:26 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/21 12:48:34 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ss(t_stack **a, t_stack **b, int print)
{
	sl_swap_first_two(a);
	sl_swap_first_two(b);
	if (print == 1)
		ft_putstr("ss\n");
}
