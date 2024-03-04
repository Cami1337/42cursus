/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:36:24 by lglauch           #+#    #+#             */
/*   Updated: 2024/03/04 17:05:22 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pixel	make_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_pixel	pixel;
	int		iter;
	int		r;
	int		g;
	int		b;

	iter = is_mandelbrot(x, y, *fractal);
	pixel.x = x;
	pixel.y = y;
	if (iter == MAX_ITER)
	{
		pixel.colour = iter;
	}
	else
	{
		r = (iter % 8) * 32;
		g = (iter % 16) * 16;
		b = (iter % 32) * 8;
		pixel.colour = (r << 16) | (g << 8) | b;
	}
	return (pixel);
}

t_pixel	make_julia(int x, int y, double c_re, double c_im)
{
	t_pixel	pixel;
	int		iter;
	int		r;
	int		g;
	int		b;

	iter = is_julia(x, y, c_re, c_im);
	pixel.x = x;
	pixel.y = y;
	if (iter == MAX_ITER)
		pixel.colour = iter;
	else
	{
		r = iter % 256;
		g = (iter * iter) % 256;
		b = (iter * iter * iter) % 256;
		pixel.colour = (r << 16) | (g << 8) | b;
	}
	return (pixel);
}

void	fractal_create(t_fractal *fractal, char **argv)
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
			if (!ft_compare_input(argv[1], "mandelbrot", 10))
				pixel = make_mandelbrot(x, y, fractal);
			else if (!ft_compare_input(argv[1], "julia", 5))
				pixel = make_julia(x, y, atof(argv[2]), atof(argv[3]));
			if (x * fractal->zoom + fractal->offset_x <= WIDTH && y * fractal->zoom + fractal->offset_y <= HEIGHT)
			{
				mlx_put_pixel(fractal->img, pixel.x + fractal->offset_x,
					pixel.y + fractal->offset_y, pixel.colour);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	clear_image(t_fractal fractal)
{
	u_int32_t	x;
	u_int32_t	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			mlx_put_pixel(fractal.img, x, y, 0);
			x++;
		}
		x = 0;
		y++;
	}
}
