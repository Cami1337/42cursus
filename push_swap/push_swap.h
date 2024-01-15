/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:34:57 by lglauch           #+#    #+#             */
/*   Updated: 2024/01/15 16:00:27 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
# include "libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

int		check_duplicates(char **str, int current_index);
int		check_digits(int argc, char **argv);
void	check_args(int argc, char **argv, t_stack **stack);
void	free_stack(t_stack *stack);
t_stack	*lstnew(int content);
void	lstadd_back(t_stack **lst, t_stack *n);
int		ft_strcmp(const char *s1, const char *s2);
void	convert_arguments(int argc, char **argv);

void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	reverserotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif