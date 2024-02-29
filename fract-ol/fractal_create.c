/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:36:24 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/29 16:44:08 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <sys/types.h> //delete later ??????

t_pixel	make_mandelbrot(int x, int y)
{
	t_pixel	pixel;
	int		iter;
	int		r;
	int		g;
	int		b;

	if (x % 2 != 0 && y % 2 != 0)
		return ((t_pixel){x, y, 0});
	iter = is_mandelbrot(x, y);
	pixel.x = x;
	pixel.y = y;
	if (iter == MAX_ITER)
	{
		pixel.colour = iter;
	}
	else
	{
		r = iter % 256;
		g = (iter * iter) % 256;
		b = (iter * iter * iter) % 256;
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
				pixel = make_mandelbrot(x, y);
			else if (!ft_compare_input(argv[1], "julia", 5))
				pixel = make_julia(x, y, atof(argv[2]), atof(argv[3]));
			if (pixel.x * fractal->zoom <= WIDTH && pixel.y * fractal->zoom <= HEIGHT)
			{
				mlx_put_pixel(fractal->img, pixel.x * fractal->zoom,
					pixel.y * fractal->zoom, pixel.colour);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
