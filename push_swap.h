/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:34:57 by lglauch           #+#    #+#             */
/*   Updated: 2024/01/09 16:52:10 by lglauch          ###   ########.fr       */
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

void	sa(t_stack *stack_a, int print);
void	sb(t_stack *stack_a, int print);
int		check_duplicates(int argc, char **argv);
int		check_digits(int argc, char **argv);
int		check_errors(int argc, char **argv);
void	free_stack(t_stack *stack);
t_stack	*lstnew(int content);
void	lstadd_back(t_stack **lst, t_stack *n);
int		ft_strcmp(const char *s1, const char *s2);

#endif