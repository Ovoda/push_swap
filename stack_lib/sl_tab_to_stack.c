/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_tab_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:59:52 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/02 11:44:52 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*sl_tab_to_stack(char **argv)
{
	int			i;
	int			j;
	long int	tmp;	
	t_stack	*stack;
	t_stack	*elem;
	char		**tab;

	i = 1;
	stack = NULL;
	while (argv[i])
	{
		j = 0;
		tab = ft_split(argv[i], ' ');
		while(tab[j])
		{
			tmp = ft_atoi(tab[j]);
			if (tmp > 2147483647 || tmp < -2147483648)
				return (NULL);
			elem = sl_create_elem(tmp);
			if (!elem)
				return (NULL);
			sl_push_back(&stack, elem);
			free(tab[j]);
			j++;
		}
		free(tab);
		i++;
	}
	return (stack);
}
