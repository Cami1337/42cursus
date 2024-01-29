/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:46:32 by lglauch           #+#    #+#             */
/*   Updated: 2024/01/29 17:01:38 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack **stack)
{
	t_stack	*current;
	int		index;
	int		min;

	min = get_min(stack);
	current = *stack;
	index = 0;
	while (current && current->content != min)
	{
		current = current->next;
		index++;
	}
	return (index);
}

int	size_stack(t_stack **stack)
{
	t_stack	*current;
	int		size;

	size = 0;
	current = *stack;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
}

int	get_min(t_stack **stack)
{
	t_stack	*current;
	int		min_value;
	int		i;

	current = *stack;
	min_value = current->content;
	i = 0;
	while (current)
	{
		if (current->content < min_value)
		{
			min_value = current->content;
		}
		current = current->next;
		i++;
	}
	return (min_value);
}
