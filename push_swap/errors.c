/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:31:56 by lglauch           #+#    #+#             */
/*   Updated: 2024/01/15 16:32:08 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (ft_isdigit(number[i]) == 0)
			return (0);
		i++;
	}
	printf("correct digit\n");
	return (1);
}

int	check_duplicates(char **str, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
        if (ft_strcmp(str[i], str[index]) == 0)
            return (0);
        i++;
    }
	printf("correct duplicates\n");
    return (1);
}

int	check_size(char *number)
{
	int	len;

	len = ft_strlen(number);
	if (len > 11)
		return (0);
	if (len == 11 && number[0] != '-')
		return (0);
	if (len == 11 && number[0] == '-' && ft_strcmp(number, "-2147483648") > 0)
		return (0);
	if (len == 10 && number[0] != '-' && ft_strcmp(number, "2147483647") > 0)
		return (0);
	return (1);
}

void	stack_push(t_stack **stack, int content)
{
	t_stack	*new;

	new = lstnew(content);
	if (new == NULL)
		return ;
	lstadd_back(stack, new);
}

void	check_args(int argc, char **argv, t_stack **stack)
{
	int		x;
	int		i;
	char	**split_args;

	x = 1;
	while (argc > x)
	{
		split_args = ft_split(argv[x], ' ');
		i = 0;
		while (split_args[i] != NULL)
		{
			if (!check_digit(split_args[i])
				|| !check_duplicates(split_args, i)
				|| !check_size(split_args[i]))
			{
				printf("Error\n");
				exit(1);
			}
			stack_push(stack, ft_atoi(split_args[i]));
			i++;
		}
		x++;
	}
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
