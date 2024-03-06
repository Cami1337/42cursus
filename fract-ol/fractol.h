/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:17:26 by lglauch           #+#    #+#             */
/*   Updated: 2024/03/06 17:55:40 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1080
# define HEIGHT 1080
# define MAX_ITER 1000

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"

# include <unistd.h>
# include <stdlib.h>
# include <math.h>


typedef struct s_mandelbrot
{
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	int		iter;
}			t_mandelbrot;

typedef struct s_julia
{
	double	z_re;
	double	z_im;
	int		iter;
}			t_julia;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	colour;
}		t_pixel;

typedef struct s_fractal
{
	void		*mlx_connection;
	void		*mlx_window;
	mlx_image_t	*img;
	double		zoom;
	int			offset_x;
	int			offset_y;
	int			target_offset_x;
	int			target_offset_y;
	double		target_zoom;
	double		mouse_x;
	double		mouse_y;
	char		**argv;
}			t_fractal;

void	fractal_init(t_fractal *fractal, char **argv);
void	fractal_create(t_fractal *fractal, char **argv);
t_pixel	make_mandelbrot(int x, int y, t_fractal *fractal);
t_pixel	make_julia(int x, int y, double c_re, double c_im);
int		is_mandelbrot(int x, int y, t_fractal fractal);
int		is_julia(int x, int y, double c_re, double c_im);

//helper
int		ft_compare_input(const char *s1, const char *s2, size_t n);
int		check_julia(int argc, char **argv);
void	my_scroll_func(double xdelta, double ydelta, void *param);
void	movement(mlx_key_data_t keydata, t_fractal *fractal);
void	clear_image(t_fractal fractal);

#endif