/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:22:02 by lglauch           #+#    #+#             */
/*   Updated: 2023/10/17 14:40:18 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			j;

	j = 0;
	while (s[j] != 0)
	{
		if (s[j] == (char)c)
		{
			return ((char *)&s[j]);
		}
		j++;
	}
	if ((char)c == 0)
		return ((char *)&s[j]);
	return (NULL);
}
// #include <stdio.h>
// int main ()
// {
//   char str[] = "This is a sample string";
//   char * pch;
//   printf ("Looking for the 's' character in \"%s\"...\n",str);
//   pch=ft_strchr(str,'s');
//   while (pch!=NULL)
//   {
//     printf ("found at %ld\n",pch-str+1);
//     pch=ft_strchr(pch+1,'s');
//   }
//   return 0;
// }