/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_morefunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:44:16 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/09 17:25:18 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	ft_putchar((n % 10) + '0');
	return (count + 1);
}

int	ft_puthexa_upper(uintptr_t n)
{
	char	*hexa;
	int		count;

	count = 0;
	hexa = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += ft_puthexa_upper(n / 16);
	}
	ft_putchar(hexa[n % 16]);
	return (count + 1);
}
