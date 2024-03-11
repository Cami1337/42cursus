/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:04:16 by lglauch           #+#    #+#             */
/*   Updated: 2024/03/11 18:12:12 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_func(mlx_key_data_t key_data, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (key_data.key == 256)
	{
		free(fractal);
		mlx_terminate(fractal->mlx_connection);
		exit(EXIT_SUCCESS);
	}
	if (key_data.key == MLX_KEY_SPACE && key_data.action == MLX_REPEAT)
		fractal->checker = true;
	else
		fractal->checker = false;
}

void	my_scroll_func(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (fractal == NULL || fractal->argv == NULL)
		return ;
	if ((ydelta > 0 || xdelta > 0) && fractal->zoom < 1)
	{
		fractal->zoom *= 1.1;
	}
	else if (ydelta < 0 || xdelta < 0)
	{
		fractal->zoom /= 1.1;
	}
	printf("zoom after: %f\n", fractal->zoom);
	clear_image(*fractal);
	fractal_create(fractal, fractal->argv);
	mlx_image_to_window(fractal->mlx_connection, fractal->img, 0, 0);
}

void	get_cursor_position(void *param)
{
	t_fractal	*fractal;
	int			x;
	int			y;

	fractal = (t_fractal *)param;
	x = fractal->mouse_x;
	y = fractal->mouse_y;
	if (fractal->checker == false)
		return ;
	mlx_get_mouse_pos(fractal->mlx_connection,
		&fractal->mouse_x, &fractal->mouse_y);
	if (fractal->checker == true && (fractal->mouse_x != x
			|| fractal->mouse_y != y))
	{
		clear_image(*fractal);
		fractal_create(fractal, fractal->argv);
		mlx_image_to_window(fractal->mlx_connection, fractal->img, 0, 0);
	}
}
