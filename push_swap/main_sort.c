/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:00:49 by lglauch           #+#    #+#             */
/*   Updated: 2024/01/29 17:32:45 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_stack_k(t_stack **stack_a, t_stack **stack_k)
{
	t_stack	*current;
	t_stack	*new;

	current = *stack_a;
	*stack_k = NULL;
	while (current)
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			return ;
		new->content = current->content;
		new->next = *stack_k;
		*stack_k = new;
		current = current->next;
	}
}

void	bubble_sort(t_stack **stack_k)
{
	t_stack	*current;
	t_stack	*tmp;
	int		swap;

	swap = 0;
	while (!is_sorted(stack_k))
	{
		current = *stack_k;
		while (current && current->next)
		{
			tmp = current->next;
			if (current->content > tmp->content)
			{
				swap = current->content;
				current->content = tmp->content;
				tmp->content = swap;
			}
			current = current->next;
		}
	}
}

t_stack	*get_block_index(t_stack **stack, int index)
{
	int		i;
	t_stack	*current;

	current = *stack;
	i = 0;
	while (current && i < index)
	{
		current = current->next;
		i++;
	}
	return (current);
}

void	sort_blocks(t_stack **stack_a, t_stack **stack_b,
					t_stack **stack_k, int size)
{
	t_stack	*current;
	int		count;

	count = 0;
	current = get_block_index(stack_k, size);
	while (*stack_a && count < size)
	{
		if ((*stack_a)->content <= current->content)
		{
			pb(stack_a, stack_b);
			count++;
		}
		else
		{
			ra(stack_a);
		}
	}
}

void	sort_all(t_stack **stack_a, t_stack **stack_b, t_stack **stack_k)
{
	int		size;
	int		num;

	make_stack_k(stack_a, stack_k);
	bubble_sort(stack_k);
	size = size_stack(stack_a);
	while (*stack_a)
	{
		num += size;
		if (size <= 100)
			sort_blocks(stack_a, stack_b, stack_k, num / 4);
		else
			sort_blocks(stack_a, stack_b, stack_k, num / 8);
	}
	//sort stack b und push to stack a
}

