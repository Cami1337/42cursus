/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:42:52 by lglauch           #+#    #+#             */
/*   Updated: 2024/03/12 16:46:10 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		fractal->mouse_x = 0;
		fractal->mouse_y = 0;
		fractal->x_offset = 1;
		fractal->y_offset = 1;
		fractal->start_x = -2;
		fractal->end_x = 2;
		fractal->start_y = -2;
		fractal->end_y = 2;
		fractal->checker = false;
		fractal_init(fractal, argv);
		mlx_scroll_hook(fractal->mlx_connection, my_scroll_func, fractal);
		mlx_key_hook(fractal->mlx_connection, close_func, fractal);\
		mlx_loop_hook(fractal->mlx_connection, get_cursor_position, fractal);
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
