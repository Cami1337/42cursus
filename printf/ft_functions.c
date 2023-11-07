/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:11:14 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/07 16:20:32 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s[i] != 0)
		while (s[i] != 0)
			i++;
	return (i);
}

int	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, (ft_strlen(s)));
	return (0);
}

