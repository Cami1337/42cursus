/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:58:03 by lglauch           #+#    #+#             */
/*   Updated: 2023/10/30 17:16:17 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_substr(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] != 0)
			count++;
		while (s[i] != c && s[i] != 0)
			i++;
	}
	return (count);
}

static	char	*copy_substrings(const char *s, int start, int end)
{
	int		len;
	char	*substr;
	int		i;

	len = end - start;
	i = 0;
	substr = malloc((len + 2) * sizeof(char *));
	if (!substr)
	{
		free(substr);
		return (0);
	}
	while (i <= len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[len] = '\0';
	return (substr);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;

	return (strings);
}

