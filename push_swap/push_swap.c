/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:02:55 by lglauch           #+#    #+#             */
/*   Updated: 2024/01/22 14:14:13 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack_a)
{
    t_stack *temp = stack_a;

    while (temp != NULL)
    {
        printf("%d ", temp->content);
        temp = temp->next;
    }

    printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	check_args(argc, argv, &stack_a);
	if (is_sorted(&stack_a) == 1)
		return (0);
	while (argc == 4 && !is_sorted(&stack_a))
	{
		ft_threeargs(&stack_a);
	}
	print_stack(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
