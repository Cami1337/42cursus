/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:38:18 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/09 17:35:41 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_putchar(char c);
size_t	ft_strlen(const char *s);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putpointer(void *s);
int		ft_puthexa(uintptr_t n);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_puthexa_upper(uintptr_t n);
int		ft_printf(const char *format, ...);
int		ft_check_format(const char *conversion, va_list args);

#endif