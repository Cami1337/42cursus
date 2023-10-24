/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:06:57 by lglauch           #+#    #+#             */
/*   Updated: 2023/10/24 17:22:11 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	digits;

	digits = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static void	int_to_string(int n, int digits, char *str)
{
	str[digits] = 0;
	digits--;
	while (n > 0)
	{
		str[digits] = (n % 10) + '0';
		digits--;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;

	digits = count_digits(n);
	str = (char *)malloc((sizeof(char) * digits) + 1);
	if (!str)
		return (ft_strdup(""));
	while (n > 0)
	{
		int_to_string(n, digits, str);
		n--;
	}
	return (str);
}
