/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:37:06 by calide-n          #+#    #+#             */
/*   Updated: 2021/04/21 14:51:52 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*sl_create_elem(int value)
{
	t_stack	*elem;

	elem = (t_stack*)malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->next = NULL;
	return (elem);
}
