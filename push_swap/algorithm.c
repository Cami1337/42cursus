/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:46:32 by lglauch           #+#    #+#             */
/*   Updated: 2024/01/23 17:28:30 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_stack *stack)
{
	return (stack == NULL);
}

void	sort_alg(t_stack **stack_a, t_stack **stack_b)
{
	int		max;
	t_stack	*head;

	if (!stack_a)
		return ;
	while (!is_empty(*stack_a))
	{
		max = find_max(stack_a);
		head = *stack_a;
		while (head && head->content != max)
		{
			ra(stack_a);
			head = *stack_a;
		}
		pb(stack_a, stack_b);
	}
	printf("stack_a: dsgpsgdf\n");
	while ((*stack_b))
	{
		pa(stack_b, stack_a);
		*stack_b = (*stack_b)->next;
	}
	printf("fnished\n");
}
