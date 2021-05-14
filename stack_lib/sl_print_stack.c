/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:41:12 by calide-n          #+#    #+#             */
/*   Updated: 2021/04/21 14:51:11 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sl_print_stack(t_stack *stack)
{
	t_stack	*tmp_stack;

	tmp_stack = stack;
	while (tmp_stack)
	{
		ft_putnbr_fd(tmp_stack->value, 1);
		if (tmp_stack->next)
			ft_putstr(" ");
		else
			ft_putstr("\n");
		tmp_stack = tmp_stack->next;
	}
}
