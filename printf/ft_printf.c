/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:33:36 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/09 17:53:47 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(const char *conversion, va_list args)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (conversion[i] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (conversion[i] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (conversion[i] == 'p')
		count += ft_putpointer(va_arg(args, void *));
	else if (conversion[i] == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (conversion[i] == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (conversion[i] == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (conversion[i] == 'x')
		count += ft_puthexa(va_arg(args, unsigned int));
	else if (conversion[i] == 'X')
		count += ft_puthexa_upper(va_arg(args, unsigned int));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				count += ft_putchar(*format);
				format++;
			}
			else
				count += ft_check_format(format++, args);
		}
		else
			count += write(1, format++, 1);
	}
	va_end(args);
	return (count);
}
// #include <stdio.h>
// int main (void)
// {
// 	char str[20] = "54sdfdsf";
// 	printf("%u\n", -200);
// 	ft_printf("%u\n", -200);
// }