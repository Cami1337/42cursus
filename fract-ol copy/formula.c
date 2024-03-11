/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:25:23 by lglauch           #+#    #+#             */
/*   Updated: 2024/03/11 15:38:06 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_mandelbrot
{
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	int		iter;
}			t_mandelbrot;

int	is_mandelbrot(int x, int y, t_fractal fractal)
{
	t_mandelbrot	mandelbrot;
	int				iter;
	double			tmp;

	iter = 0;
	mandelbrot.z_re = 0;
	mandelbrot.z_im = 0;
	mandelbrot.c_re = (x * fractal.zoom - WIDTH / 2.0) * 4.0 / WIDTH - 0.5;
	mandelbrot.c_im = (y * fractal.zoom - HEIGHT / 2.0) * 4.0 / HEIGHT + 0.3;
	while (mandelbrot.z_re * mandelbrot.z_re + mandelbrot.z_im * mandelbrot.z_im
		<= 4 && iter < MAX_ITER)
	{
		tmp = mandelbrot.z_re * mandelbrot.z_re - mandelbrot.z_im
			* mandelbrot.z_im + mandelbrot.c_re;
		mandelbrot.z_im = 2 * mandelbrot.z_re * mandelbrot.z_im
			+ mandelbrot.c_im;
		mandelbrot.z_re = tmp;
		iter++;
	}
	return (iter);
}

typedef struct s_julia
{
	double	z_re;
	double	z_im;
	int		iter;
}			t_julia;

int	is_julia(int x, int y, double c_re, double c_im)
{
	int		iter;
	t_julia	julia;
	double	tmp;

	julia.z_re = (x - WIDTH / 2.0) * 4.0 / WIDTH;
	julia.z_im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
	iter = 0;
	while (julia.z_re * julia.z_re + julia.z_im * julia.z_im <= 4
		&& iter < MAX_ITER)
	{
		tmp = julia.z_re * julia.z_re - julia.z_im * julia.z_im + c_re;
		julia.z_im = 2 * julia.z_re * julia.z_im + c_im;
		julia.z_re = tmp;
		iter++;
	}
	return (iter);
}
