/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:45:44 by lglauch           #+#    #+#             */
/*   Updated: 2023/10/16 16:23:59 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		i;
	size_t		len;

	d = dst;
	s = src;
	i = 0;
	len = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && s[i] != 0)
		{
			d[i] = s[i];
			i++;
		}
		d[i] = '\0';
	}
	return (ft_strlen((char *)s));
}

// #include <stdio.h>

// int main(void)
// {
// 	char dst[20];
// 	const char src[] = "hello8884";
// 	printf("%zu", ft_strlcpy(dst, src, 10));
// }