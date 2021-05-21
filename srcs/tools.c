/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:01:02 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/21 14:52:13 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	pre_prog(int argc, char **argv, t_stack **a)
{
	if (argc < 2)
		return (0);
	if (!check_arg(&argv[1]))
		return (ps_error());
	*a = sl_tab_to_stack(argv);
	if (*a && !sl_check_error_stack(*a))
	{
		sl_free_stack(*a);
		return (ps_error());
	}
	if (!(*a))
		return (ps_error());
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
