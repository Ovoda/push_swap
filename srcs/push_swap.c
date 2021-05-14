/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:50:47 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/04 19:21:00 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

typedef void psf(t_stack**, t_stack **, int);

int	ft_strisnum_orneg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	check_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_strisnum_orneg(argv[i]))
			return (0);
		i++;
	}
	return (1);
}


void	push_swap(t_stack *stack_a)
{
	t_stack	*sorted;



	sorted = sort_ref_stack(stack_a);
	alg_pivot(stack_a);
	
//	alg_three_less(stack_a, 1);
	
	sl_free_stack(sorted);
//	alg_simple_sa_ra(stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!check_arg(&argv[1]))
		return (ps_error());
	stack_a = sl_tab_to_stack(argv);
	if (!sl_check_error_stack(stack_a) || !stack_a)
		return (ps_error());
	if (sl_check_sorted(stack_a) && !(stack_b))
		return (0);
	push_swap(stack_a);
	return (0);
}
