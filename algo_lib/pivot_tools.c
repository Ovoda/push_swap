/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:49:15 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/21 13:52:58 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_var	check_rr_or_r(t_var var, int index_b)
{
	if (var.index_a > var.size_a / 2)
	{
		var.total_a = var.size_a - var.index_a;
		var.is_rra = 1;
	}
	else
		var.total_a = var.index_a;
	if (index_b > var.size_b / 2)
	{
		var.total_b = var.size_b - index_b;
		var.is_rrb = 1;
	}
	else
		var.total_b = index_b;
	return (var);
}

t_var	count_rr_rrr(t_var var, int index_b)
{
	var = check_rr_or_r(var, index_b);
	var.total_rr = 0;
	if ((var.is_rra == 0 && var.is_rrb == 0) ||
			(var.is_rra == 1 && var.is_rrb == 1))
	{
		if (var.total_a > var.total_b)
			var.total_rr = var.total_b;
		else
			var.total_rr = var.total_a;
		var.total_a -= var.total_rr;
		var.total_b -= var.total_rr;
	}
	return (var);
}
