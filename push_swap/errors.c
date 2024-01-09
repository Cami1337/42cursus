/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:31:56 by lglauch           #+#    #+#             */
/*   Updated: 2024/01/09 16:36:11 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digits(int argc, char **argv)
{
	int		i;
	int		x;

	x = 1;
	while (argc > x)
	{
		i = 0;
		while (argv[x][i] != '\0')
		{
			if (argv[x][i] < 48 || argv[x][i] > 57)
			{
				ft_printf("Error digits\n");
				return (1);
			}
			i++;
			ft_printf("value i:%d\n", i);
		}
		x++;
		ft_printf("value x:%d\n", x);
	}
	ft_printf("Digits good\n");
	return (0);
}

int	check_duplicates(int argc, char **argv)
{
	int	i;
	int	x;
	int	z;

	x = 1;
	while (argc > x)
	{
		z = i + 1;
		while (argc > z)
		{
			if (argv[x] == argv[z])
			{
				ft_printf("Error duplicates\n");
				return (1);
			}
			z++;
		}
		x++;
	}
	ft_printf("Duplicates good\n");
	return (0);
}

int	check_errors(int argc, char **argv)
{
	if (check_duplicates(argc, argv) == 1 || check_digits(argc, argv) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
