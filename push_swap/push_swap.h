/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra <intra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:34:57 by lglauch           #+#    #+#             */
/*   Updated: 2024/01/22 15:59:16 by intra            ###   ########.fr       */
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

int		check_duplicates(t_stack **stack);
int		check_digit(char *number);
int		check_size(char *number);
void	stack_push(t_stack **stack, int content);
int		check_args(int argc, char **argv, t_stack **stack);
int		split_args_number(char **split_args, t_stack **stack);
void	ft_threeargs(t_stack **stack);
void	free_stack(t_stack *stack);
int		find_max(t_stack **stack);
int		ft_strcmp(const char *s1, const char *s2);
void	lstadd_back(t_stack **lst, t_stack *n);
t_stack	*lstnew(int content);

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

int		is_sorted(t_stack **stack);

#endif