/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:11:33 by lglauch           #+#    #+#             */
/*   Updated: 2024/03/19 17:38:26 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft/libft.h"
#include "lib/printf/ft_printf.h"

int	main(void)
{
	int	pid;

	if (pid <= 0)
		return (0);
	printf("Server PID: %d\n", pid);
}