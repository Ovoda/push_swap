/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_swap_first_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:13:33 by calide-n          #+#    #+#             */
/*   Updated: 2021/04/22 12:06:56 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sl_swap_first_two(t_stack **stack)
{
	int	tmp_first_value;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp_first_value = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp_first_value;
}
