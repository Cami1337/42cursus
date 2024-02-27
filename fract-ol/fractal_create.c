/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:36:24 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/27 15:31:04 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <sys/types.h> //delete later ??????



t_pixel	make_mandelbrot(int x, int y)
{
    t_pixel	pixel;
    double c_re = (x - WIDTH / 2.0) * 4.0 / WIDTH - 0.5;
    double c_im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT + 0.3;
    double z_re = 0, z_im = 0;
    int iter = 0;
	int MAX_ITER = 1000;

    while (z_re * z_re + z_im * z_im <= 4 && iter < MAX_ITER)
    {
        double z_re_new = z_re * z_re - z_im * z_im + c_re;
        z_im = 2 * z_re * z_im + c_im;
        z_re = z_re_new;
        iter++;
    }
    pixel.x = x;
    pixel.y = y;
    if (iter == MAX_ITER)
    {
        pixel.colour = iter; // Mandelbrot set, color black
    }
    else
    {
        int r = iter % 256;
        int g = (iter * iter) % 256;
        int b = (iter * iter * iter) % 256;

        // Assuming pixel.colour is a 32-bit int with format 0xRRGGBB
        pixel.colour = (r << 16) | (g << 8) | b;
    }

    return (pixel);
}

t_pixel	make_julia(int x, int y)
{
	t_pixel	pixel;
	double c_re = -0.7;
	double c_im = 0.27015;
	double z_re = (x - WIDTH / 2.0) * 4.0 / WIDTH;
	double z_im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT + 0.3;
	int iter = 0;
	int MAX_ITER = 1000;

	while (z_re * z_re + z_im * z_im <= 4 && iter < MAX_ITER)
	{
		double z_re_new = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = z_re_new;
		iter++;
	}
	pixel.x = x;
	pixel.y = y;
	if (iter == MAX_ITER)
		pixel.colour = iter;
	else
	{
		int r = iter % 256;
		int g = (iter * iter) % 256;
		int b = (iter * iter * iter) % 256;
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
				pixel = make_julia(x, y);
			mlx_put_pixel(fractal->img, pixel.x, pixel.y, pixel.colour);
			x++;
		}
		x = 0;
		y++;
	}
}
// t_pixel	make_pixel(int x, int y)
// {
// 	t_pixel	pixel;

// 	pixel.x = 0;
// 	pixel.y = 0;
// 	//if pixel is mandelbrot set pixel colour to mandelbrot

// 	//if pixel is not mandelbrot set pixel colour to black
// 	return (pixel);
// }