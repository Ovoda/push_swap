/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:57:26 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/04 18:51:55 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrr(t_stack **a, t_stack **b, int print)
{
	sl_rotate_down(a);
	sl_rotate_down(b);
	if (print == 1)
		ft_putstr("rrr\n");
}

