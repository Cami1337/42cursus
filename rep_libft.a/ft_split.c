/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:58:03 by lglauch           #+#    #+#             */
/*   Updated: 2023/10/24 13:59:31 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	**new;
	int		substart;

	i = 0;
	count = 0;
	substart = 0;
	if (!s)
		return (0);
	if (!c)
		return ((char **)s);
	while (s[i] != 0)
	{
		if (s[i] == c)
			count++;
		i++;
	}
	new = (char **)malloc(((count + 2) * sizeof(char *)));
	if (!new)
		return (0);
	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			new[count] = (char *)malloc(i - substart + 1);
			if (!new[count])
				return (0);
			ft_strlcpy(new[count], s + substart, i - substart);
			new[count][i - substart] = '\0';
			substart = i + 1;
			count++;
		}
		i++;
	}
	new[count + 1] = NULL;
	return (new);
}

#include <stdio.h>
int main(void)
{
	prinft("")
}