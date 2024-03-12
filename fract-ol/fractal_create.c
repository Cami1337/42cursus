/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:36:24 by lglauch           #+#    #+#             */
/*   Updated: 2024/03/12 17:36:17 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// t_pixel	make_mandelbrot(int x, int y, t_fractal *fractal)
// {
// 	t_pixel	pixel;
// 	int		iter;
// 	int		r;
// 	int		g;
// 	int		b;

// 	iter = is_mandelbrot(x, y, *fractal);
// 	pixel.x = x;
// 	pixel.y = y;
// 	if (iter == MAX_ITER)
// 	{
// 		pixel.colour = iter;
// 	}
// 	else
// 	{
// 		r = (iter % 8) * 32;
// 		g = (iter % 16) * 16;
// 		b = (iter % 32) * 8;
// 		pixel.colour = (r << 16) | (g << 8) | b;
// 	}
// 	return (pixel);
// }
t_pixel	make_mandelbrot(int x, int y, t_fractal *fractal)
{
    t_pixel	pixel;
    int		iter;
    int		r;
    int		g;
    int		b;

    double real = fractal->start_x + ((double)x / WIDTH) * (fractal->end_x - fractal->start_x);
    double imag = fractal->start_y + ((double)y / HEIGHT) * (fractal->end_y - fractal->start_y);
    iter = is_mandelbrot(real, imag, *fractal);
    pixel.x = x;
    pixel.y = y;
    if (iter == MAX_ITER)
    {
        pixel.colour = 0x000000; // Set to black
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

t_pixel	make_julia(int x, int y, t_fractal *fractal)
{
	t_pixel	pixel;
	int		iter;
	int		r;
	int		g;
	int		b;

	fractal->c_re_julia = fractal->mouse_x / 1000.0;
	fractal->c_im_julia = fractal->mouse_y / 1000.0;
	fractal->x_julia = fractal->start_x + ((double)x / WIDTH) * (fractal->end_x - fractal->start_x);
    fractal->y_julia = fractal->start_y + ((double)y / HEIGHT) * (fractal->end_y - fractal->start_y);
	iter = is_julia(fractal->x_julia, fractal->y_julia,
			fractal->c_re_julia, fractal->c_im_julia);
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
				pixel = make_julia(x, y, fractal);
			if (x * fractal->zoom <= WIDTH && y * fractal->zoom <= HEIGHT)
			{
				mlx_put_pixel(fractal->img, pixel.x * fractal->x_offset,
							pixel.y * fractal->y_offset, pixel.colour);
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
