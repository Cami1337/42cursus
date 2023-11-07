/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:33:36 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/07 16:23:37 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_check_format(const char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = 0;
	while (*format)
	{
		if (format[i] == '%')
			i++;
		if (format[i] == '&')
		{
			ft_putchar('%');
			return (-1);
		}
		if (format[i])
	}
	va_end(args);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = 0;
	if (format[i] == '%')
	{
		if (format[i + 1] == '\0')
			write(1, "\0", 1);
	}
	va_end(args);
}
