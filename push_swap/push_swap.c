/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:02:55 by lglauch           #+#    #+#             */
/*   Updated: 2024/01/29 16:01:48 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp != NULL)
	{
		printf("%d ", temp->content);
		temp = temp->next;
	}
	printf("\n");
}

t_stack	*push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_k;
	int		arg_count;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	arg_count = check_args(argc, argv, &stack_a);
	if (is_sorted(&stack_a) == 1)
		return (0);
	while (arg_count == 3 && !is_sorted(&stack_a))
	{
		ft_threeargs(&stack_a);
	}
	while (arg_count == 5 && !is_sorted(&stack_a))
	{
		ft_fiveargs(&stack_a, &stack_b);
	}
	make_stack_k (&stack_a, &stack_k);//add algo
	bubble_sort(&stack_k);
	print_stack(stack_k); //remove later
	free_stack(stack_a);
	free_stack(stack_b);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = push_swap(argc, argv);
	return (0);
}
