/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:50:47 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/21 14:13:46 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	analyse_buffer(char *line, t_stack **stack_a, t_stack **stack_b)
{
	static char		*cmd_list[] = {"pa", "pb", "sa", "sb",
		"ss", "ra", "rb", "rr", "rra", "rrb", "rrr", NULL};
	static t_psf	*func_list[] = {&pa, &pb, &sa, &sb,
		&ss, &ra, &rb, &rr, &rra, &rrb, &rrr, NULL};
	int				i;

	i = 0;
	if (!line || !line[0])
		return (-1);
	i = 0;
	while (cmd_list[i])
	{
		if (ft_strcmp(cmd_list[i], line) == 0)
		{
			func_list[i](stack_a, stack_b, 0);
			return (1);
		}
		i++;
	}
	return (-1);
}

int	input(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int		size;

	if (sl_check_sorted(*stack_a) && !(*stack_b))
		return (ps_ok());
	while (1)
	{
		size = get_next_line(0, &line);
		if (size == 0)
		{
			free(line);
			return (0);
		}
		if (analyse_buffer(line, stack_a, stack_b) < 0)
			ft_putstr_fd("Error\n", 2);
		else if (sl_check_sorted(*stack_a) && !(*stack_b))
		{
			free(line);
			return (ps_ok());
		}
		free(line);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_b = NULL;
	if (pre_prog(argc, argv, &stack_a) != 1)
		return (0);
	input(&stack_a, &stack_b);
	sl_free_stack(stack_a);
	if (stack_b)
		sl_free_stack(stack_b);
	return (0);
}
