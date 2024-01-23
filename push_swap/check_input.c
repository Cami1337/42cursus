/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:56:47 by intra             #+#    #+#             */
/*   Updated: 2024/01/23 13:29:48 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_args_number(char **split_args, t_stack **stack)
{
	int	i;
	int	arg_count;

	i = 0;
	arg_count = 0;
	while (split_args[i] != NULL)
	{
		if (!check_digit(split_args[i]) || !check_size(split_args[i]))
		{
			ft_printf("Error\n");
			exit(1);
		}
		stack_push(stack, ft_atoi(split_args[i]));
		i++;
		arg_count++;
	}
	return (arg_count);
}

int	check_args(int argc, char **argv, t_stack **stack)
{
	int		x;
	char	**split_args;
	int		arg_count;

	x = 1;
	arg_count = 0;
	while (argc > x)
	{
		split_args = ft_split(argv[x], ' ');
		arg_count += split_args_number(split_args, stack);
		x++;
	}
	if (!check_duplicates(stack))
	{
		ft_printf("Error\n");
		exit(1);
	}
	ft_printf("Args: %d\n", arg_count);
	return (arg_count);
}