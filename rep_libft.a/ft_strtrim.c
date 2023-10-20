/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:10:13 by lglauch           #+#    #+#             */
/*   Updated: 2023/10/20 16:42:19 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		sstart;
	int		send;
	char	*ptr;
	int		newlen;

	sstart = 0;
	send = ft_strlen(s1) - 1;
	ptr = (char *)s1;
	if (!s1)
		return (0);
	if (s1 == set)
	{
		if (s1[sstart] == ' ' || s1[sstart] == '\t' || s1[sstart] == '\n')
			sstart++;
		if ((size_t)sstart == ft_strlen(s1))
			return (ft_strdup(""));
		if (sstart > 0)
		{
			ptr[0] = ptr[sstart];
		}
		if (s1[send] == ' ' || s1[send] == '\t' || s1[send] == '\n')
			send--;
	}
	newlen = send - sstart + 1;
	ptr = (char *)malloc(newlen);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1 + sstart, newlen);
	ptr[newlen] = '\0';
	return (ptr);
}
