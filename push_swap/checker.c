/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:01:40 by lglauch           #+#    #+#             */
/*   Updated: 2024/01/11 15:29:26 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void test_check_digits()
// {
//     t_stack *stack_a = NULL;
//     t_stack *new;

//     // Add some elements to the stack
//     new = lstnew('1');
//     lstadd_back(&stack_a, new);
//     new = lstnew('2');
//     lstadd_back(&stack_a, new);
//     new = lstnew('2');
//     lstadd_back(&stack_a, new);
// 	new = lstnew('5');
//     lstadd_back(&stack_a, new);
// 	new = lstnew('y');
//     lstadd_back(&stack_a, new);

//     // Call check_digits and print the result
//     int result = check_digits(stack_a);
//     ft_printf("check_digits returned %d\n", result);
// 	ft_printf("check duplicates returned %d\n", check_duplicates(stack_a));

//     // Clean up
//     free_stack(stack_a);
// }

// int	check_digits(int argc, char **argv)
// {
// 	int		i;
// 	int		x;
// 	int		value;

// 	x = 1;
// 	while (argc > x)
// 	{
// 		i = 0;
// 		while (argv[x][i] != '\0')
// 		{
// 			value = ft_atoi(argv[x]);
// 			if (argv[x][i] < 48 || argv[x][i] > 57 || 
// 				value > INT_MAX || value < INT_MIN)
// 			{
// 				ft_printf("Error digits\n");
// 				return (1);
// 			}
// 			i++;
// 			ft_printf("value i:%d\n", i);
// 		}
// 		x++;
// 		ft_printf("value x:%d\n", x);
// 	}
// 	ft_printf("Digits good\n");
// 	return (0);
// }

// int	check_duplicates(int argc, char **argv)
// {
// 	int	i;
// 	int	x;
// 	int	z;

// 	x = 1;
// 	while (argc > x)
// 	{
// 		z = x + 1;
// 		while (argc > z)
// 		{
// 			if (ft_strcmp(argv[x], argv[z]) == 0)
// 			{
// 				ft_printf("Error duplicates\n");
// 				return (1);
// 			}
// 			z++;
// 		}
// 		x++;
// 	}
// 	ft_printf("Duplicates good\n");
// 	return (0);
// }

// int main(int argc, char **argv)
// {
//     check_digits(argc, argv);
// 	check_duplicates(argc, argv);
//     return 0;
// }

