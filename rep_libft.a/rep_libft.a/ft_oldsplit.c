/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oldsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:58:03 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/01 15:49:05 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// static int	ft_count_substr(char const *s, char c)
// {
// 	int	count;

// 	count = 0;
// 	while (*s)
// 	{
// 		if (*s != c)
//         {
//             count++;
//             while (*s && *s != c)
//                 s++;
//         }
//         s++;
//     }
//     return (count);
// }

// static char	*ft_strndup(const char *s1, size_t n)
// {
//     char    *copy;

// 	copy = (char *)malloc(n + 1);
//     if (!copy)
//         return (NULL);
//     ft_memcpy(copy, s1, n);
//     copy[n] = '\0';
//     return (copy);
// }

// void	ft_free_substrings(char **substrings)
// {
//     if (!substrings)
//         return;
//     while (*substrings)
//         free(*substrings++);
//     free(substrings);
// }

// char	**ft_split(char const *s, char c)
// {
//     int 		count;
// 	int			i;
// 	char		**substrings;
// 	const char	*start;

// 	start = s;
// 	count = ft_count_substr(s, c);
// 	i = 0;
//     if (!s || count == 0)
//         return (NULL);
// 	substrings = (char **)malloc(sizeof(char *) * (count + 1));
//     if (!substrings)
//         return (NULL);
//     while (*s)
//     {
//         if (*s != c)
//         {
//             while (*s && *s != c)
//                 s++;

//             substrings[i] = ft_strndup(start, s - start);
//             if (!substrings[i])
//             {
//                 while (i > 0)
//                     free(substrings[--i]);
//                 free(substrings);
//                 return (NULL);
//             }
//             i++;
//         }
//         else
//             s++;
//     }

//     substrings[i] = NULL;
//     return (substrings);
// }
