/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_tab_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:59:52 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/21 15:46:07 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		push_tab(char **tab, t_stack **stack)
{
	int			j;
	long int	tmp;
	t_stack		*elem;

	j = 0;
	while (tab[j])
	{
		tmp = ft_atoi(tab[j]);
		if (tmp > 2147483647 || tmp < -2147483648)
			return (-1);
		elem = sl_create_elem(tmp);
		if (!elem)
			return (-1);
		sl_push_back(stack, elem);
		free(tab[j]);
		j++;
	}
	free(tab);
	return (0);
}

t_stack	*sl_tab_to_stack(char **argv)
{
	int			i;
	t_stack		*stack;
	char		**tab;

	i = 1;
	stack = NULL;
	while (argv[i])
	{
		tab = ft_split(argv[i], ' ');
		if (push_tab(tab, &stack) == -1)
		{
			sl_free_stack(stack);
			return (NULL);
		}
		i++;
	}
	return (stack);
}
