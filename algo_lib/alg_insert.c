/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:25:10 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/21 11:56:10 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	insert_empty_b_min_max(t_stack **a, t_stack **b)
{
	int	size;
	int	index_max;
	int	index_min;
	int	min;

	size = sl_get_size(*b);
	index_max = sl_get_index(*b, sl_get_max(*b));
	index_min = sl_get_index(*b, sl_get_min(*b));
	if ((size - index_min < index_min && size - index_min < index_min) ||
			(size - index_max < index_max && size - index_max < index_min))
	{
		index_max = size - index_max;
		index_min = size - index_min;
		while (index_max-- > 0 && index_min-- > 0)
			rrb(a, b, 1);
	}
	else
		while (index_max-- && index_min--)
			rb(a, b, 1);
	min = sl_get_min(*b);
	pa(a, b, 1);
	if ((*a)->value == min)
		ra(a, b, 1);
}

void	alg_insert(t_stack *a)
{
	int		size;
	t_stack	*b;
	int		min;

	size = sl_get_size(a);
	b = NULL;
	min = sl_get_min(a);
	while (size--)
		pb(&a, &b, 1);
	while (b)
		insert_empty_b_min_max(&a, &b);
	while ((a)->value != min)
		ra(&a, NULL, 1);
}
