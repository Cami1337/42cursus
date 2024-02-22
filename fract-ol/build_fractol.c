/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:00:41 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/22 16:16:05 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "fractol.h"

// void	generate_fractol(int argc, char **argv, mlx_image_t *img)
// {
// 	if (argc == 2)
// 	{
// 		// if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
// 		// 	mandelbrot();
// 		// else if (ft_strncmp(argv[1], "julia", 6) == 0)
// 		// 	julia();
// 		// else if (ft_strncmp(argv[1], "burning_ship", 13) == 0)
// 		// 	burning_ship();
// 		// else
// 		// {
// 			ft_printf("Usage: ./fractol [mandelbrot | julia | burning_ship]\n");
// 			exit(EXIT_FAILURE);
// 		// }
// 	}
// }

// void	mandelbrot(void)
// {
// }

static void	malloc_error(void)
{
	ft_printf("Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init(WIDTH, HEIGHT, "Fract'ol", true);
	if (!fractal->mlx_connection)
		malloc_error();
	fractal->img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (!fractal->img)
	{
		mlx_close_window(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal_create(fractal);
	mlx_image_to_window(fractal->mlx_connection, fractal->img, 0, 0);
}
