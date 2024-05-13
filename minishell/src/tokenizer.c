/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:48:06 by lglauch           #+#    #+#             */
/*   Updated: 2024/05/13 14:44:29 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_operator(char *line)
{
	int	i;

	i = 0;
	if (((line[i] == '<') && (line[i + 1] == '<')) || ((line[i] == '>') && (line[i + 1] == '>')))
		return (2);
	if (line[i] == '|' || line[i] == '<' || line[i] == '>')
		return (1);
	return (0);
}

int	is_doubleoperator(char *line)
{
	if (ft_strncmp(line, "<<", 2) == 0)
		return (1);
	if (ft_strncmp(line, ">>", 2) == 0)
		return (1);
	return (0);
}

char	**tokenizer(char *line)
{
	char	**tokens;
	int		i;
	int		j;
	int		x;
	char	c;

	tokens = calloc(1, sizeof(char *));
	if (!tokens)
		return (NULL);
	i = -1;
	j = 0;
	x = 0;
	while (line[++i] != 0)
	{
		if (line[i] == '"' || line[i] == '\'')
		{
			c = line[i];
			tokens[j] = malloc(sizeof(char));
			if (!tokens[j])
			{
				printf("problem with malloc in tokenizer");
				return(0);
			}
			while (line[i])
			{
				tokens[j][x++] = line[i];
				tokens[j] = realloc(tokens[j], (x + 2) * sizeof(char)); //write own realloc
				if (!tokens[j])
				{
					printf("problem with malloc in tokenizer");
					return(0);
				}
				if (line[i + 1] && line[i + 1] == c)
				{
					i++;
					tokens[j][x++] = line[i];
					break ;
				}
				i++;
			}
			tokens[j][x] = 0;
			j++;
			tokens = realloc(tokens, (j + 1) * sizeof(char *));
			tokens[j] = NULL;
			x = 0;
		}
		else if (line[i] != ' ')
		{
			tokens[j] = malloc(sizeof(char));
			if (!tokens[j])
			{
				printf("problem with malloc in tokenizer");
				return (0);
			}
			while (line[i] != ' ' && line[i] != 0)
			{
				tokens[j][x] = line[i++];
				tokens[j] = realloc(tokens[j], (x + 2) * sizeof(char));
				if (!tokens[j])
				{
					printf("problem with malloc in tokenizer");
					return (0);
				}
				x++;
			}
			tokens[j][x] = 0;
			j++;
			tokens = realloc(tokens, sizeof(char *) * j + 1);
			tokens[j] = NULL;
			x = 0;
		}
		else if (is_operator(line + i) != 0)
		{
			tokens[j] = malloc(sizeof(char));
			if (!tokens[j])
			{
				printf("problem with malloc in tokenizer");
				return (0);
			}
			while (line[i])
			{
				tokens[j][x] = line[i++];
				tokens[j] = realloc(tokens[j], (x + 2) * sizeof(char));
				if (!tokens[j])
				{
					printf("problem with malloc in tokenizer");
					return (0);
				}
				x++;
			}
			tokens[j][x] = 0;
			j++;
			tokens = realloc(tokens, sizeof(char *) * j + 1);
			tokens[j] = NULL;
			x = 0;
		}
	}
	tokens[j] = NULL;
	return (tokens);
}


//error checking ->error messages

//https://github.com/toni-schmitt/minishell#the-basic-functionalities-of-the-project