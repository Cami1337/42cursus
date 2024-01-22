/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:29:31 by lglauch           #+#    #+#             */
/*   Updated: 2024/01/22 14:12:38 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = *stack;
	while (current != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->content > checker->content)
			{
				return (0);
			}
			checker = checker->next;
		}
		current = current->next;
	}
	return (1);
}

void	ft_threeargs(t_stack **stack)
{
	int		max;
	t_stack	*current;

	current = *stack;
	max = find_max(stack);
	if (current->content == max)
	{
		ra(stack);
	}
	else if (current->next->content == max)
	{
		rra(stack);
	}
	else if (current->content > current->next->content)
	{
		sa(stack);
	}
}
