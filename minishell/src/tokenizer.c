/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:48:06 by lglauch           #+#    #+#             */
/*   Updated: 2024/05/07 13:46:08 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	count_words(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (line)
		count = 1;
	while (line[i])
	{
		if (line[i] != ' ')
			i++;
		else
		{
			count++;
			i++;
		}
	}
	return (count);
}

char	**tokenizer(char *line)
{
	char	**tokens;
	int		i;
	int		j;
	int		x;
	// char	c;
	int		word_number;

	word_number = count_words(line);
	tokens = malloc(sizeof(char *) * (word_number + 1));
	if (!tokens)
		return (NULL);
	i = -1;
	j = 0;
	x = 0;
	while (line[++i] != 0)
	{
		// if (line[i] == '"' || line[i] == '\'')
		// {
		// 	c = line[i];
		// 	tokens[j] = malloc(sizeof(char));
		// 	if (!tokens[j])
		// 	{
		// 		printf("problem with malloc in tokenizer");
		// 		return(0);
		// 	}
		// 	while (line[i])
		// 	{
		// 		tokens[j][x++] = line[i];
		// 		tokens[j] = realloc(tokens[j], (x + 2) * sizeof(char)); //write own realloc
		// 		if (!tokens[j])
		// 		{
		// 			printf("problem with malloc in tokenizer");
		// 			return(0);
		// 		}
		// 		if (line[i++] == c)
		// 			break ;
		// 	}
		// 	tokens[j][x] = 0;
		// }
		if (line[i] != ' ')
		{
			tokens[j] = malloc(sizeof(char));
			if (!tokens[j])
			{
				printf("problem with malloc in tokenizer");
				return(0);
			}
			while (line[i] != ' ' && line[i] != 0)
			{
				tokens[j][x] = line[i++];
				tokens[j] = realloc(tokens[j], (x + 2) * sizeof(char));
				if (!tokens[j])
				{
					printf("problem with malloc in tokenizer");
					return(0);
				}
				x++;
			}
			tokens[j][x] = 0;
			j++;
			x = 0;
		}
	}
	tokens[j] = NULL;
	return (tokens);
}


//error checking ->error messages

//