/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:28:56 by lglauch           #+#    #+#             */
/*   Updated: 2024/01/11 16:07:52 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}

// int main(int argc, char **argv)
// {
//     t_stack *stack_a = malloc(sizeof(t_stack));
//     stack_a->content = 3;
//     stack_a->next = malloc(sizeof(t_stack));
//     stack_a->next->content = 8;
//     stack_a->next->next = NULL;
// 	t_stack *stack_b = malloc(sizeof(t_stack));
//     stack_b->content = 6;
//     stack_b->next = malloc(sizeof(t_stack));
//     stack_b->next->content = 1;
//     stack_b->next->next = NULL;

//     printf("Before sa: stack_a->content = %d\n", stack_a->content);
//     sa(&stack_a);
//     printf("After sa: stack_a->content = %d\n", stack_a->content);
// 	printf("Before sb: stack_a->content = %d\n", stack_b->content);
//     sa(&stack_b);
//     printf("After sb: stack_a->content = %d\n", stack_b->content);

//     // Don't forget to free the memory you allocated
//     free(stack_a->next);
//     free(stack_a);

//     return (0);
// }