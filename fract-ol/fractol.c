/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:42:52 by lglauch           #+#    #+#             */
/*   Updated: 2024/03/06 18:01:11 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_func(mlx_key_data_t key_data, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (key_data.key == 256)
	{
		mlx_terminate(fractal->mlx_connection);
		free(fractal);
		exit(EXIT_SUCCESS);
	}
	else if (key_data.key == MLX_KEY_W && fractal->offset_y > 24)
		fractal->offset_y -= 25;
	else if (key_data.key == MLX_KEY_A && fractal->offset_x > 24)
		fractal->offset_x -= 25;
	else if (key_data.key == MLX_KEY_S && fractal->offset_y < 350)
		fractal->offset_y += 25;
	else if (key_data.key == MLX_KEY_D && fractal->offset_x < 300)
		fractal->offset_x += 25;
	printf("offset_x: %d, offset_y: %d\n", fractal->offset_x, fractal->offset_y);
	clear_image(*fractal);
	fractal_create(fractal, fractal->argv);
	mlx_image_to_window(fractal->mlx_connection, fractal->img, 0, 0);
}

void	my_scroll_func(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (fractal == NULL || fractal->argv == NULL)
		return ;
	if (ydelta > 0 || xdelta > 0)
	{
		fractal->target_zoom *= 1.1;
		fractal->target_offset_x = fractal->mouse_x;
		fractal->target_offset_y = fractal->mouse_y;
	}
	else if (ydelta < 0 || xdelta < 0)
	{
		fractal->target_zoom /= 1.1;
		fractal->target_offset_x = fractal->mouse_x;
		fractal->target_offset_y = fractal->mouse_y;
	}
	clear_image(*fractal);
	fractal_create(fractal, fractal->argv);
	mlx_image_to_window(fractal->mlx_connection, fractal->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if ((argc == 2 && !ft_compare_input(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !check_julia(argc, argv)))
	{
		fractal = malloc(sizeof(t_fractal));
		if (fractal == NULL)
			return (EXIT_FAILURE);
		fractal->zoom = 1;
		fractal->offset_y = 0;
		fractal->offset_x = 0;
		fractal->target_zoom = 1;
		fractal->target_offset_x = 0;
		fractal->target_offset_y = 0;
		fractal_init(fractal, argv);
		mlx_scroll_hook(fractal->mlx_connection, my_scroll_func, fractal);
		mlx_key_hook(fractal->mlx_connection, close_func, fractal);
		mlx_loop(fractal->mlx_connection);
		mlx_terminate(fractal->mlx_connection);
		free(fractal);
	}
	else
	{
		ft_printf("\nInvalid Input\n\nUse: ./fractol [mandelbrot |\
					julia <value> <value> | burning_ship]\n\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
