/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:11:14 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/09 17:25:31 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (*s)
	{
		ft_putchar(*s);
		count++;
		s++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	if (n < 0)
	{
		if (write (1, "-", 1) == -1)
			return (-1);
		n = -n;
		count++;
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
	}
	ft_putchar(n % 10 + '0');
	return (count + 1);
}

int	ft_putpointer(void *s)
{
	uintptr_t	address;
	int			count;

	address = (uintptr_t) s;
	count = write (1, "0x", 2);
	if (count == -1)
		return (-1);
	return (ft_puthexa(address) + count);
}

int	ft_puthexa(uintptr_t n)
{
	char	*hexa;
	int		count;

	count = 0;
	hexa = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_puthexa(n / 16);
	}
	ft_putchar(hexa[n % 16]);
	return (count + 1);
}
