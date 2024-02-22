/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:36:24 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/22 16:28:32 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_create(t_fractal *fractal)
{
	u_int32_t	x;
	u_int32_t	y;
	t_pixel		pixel;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			pixel = make_pixel(x, y);
			mlx_put_pixel(fractal->img, pixel.x, pixel.y, pixel.colour);
			x++;
		}
		x = 0;
		y++;
	}
}

t_pixel	make_pixel(int x, int y)
{
	t_pixel	pixel;

	pixel.x = 0;
	pixel.y = 0;
	return (pixel);
}