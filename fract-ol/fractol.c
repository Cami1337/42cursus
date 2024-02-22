/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:42:52 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/22 14:49:52 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "MLX42/include/MLX42/MLX42.h"

// Exit the program as failure.
// static void	ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// Print the window width and height.
// static void	ft_hook(void *param)
// {
// 	const mlx_t	*mlx = param;
// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_compare_input(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !check_julia(argc, argv)))
	{
		fractal_init(&fractal);
		// fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
		mlx_terminate(fractal.mlx_connection);
	}
	else
	{
		ft_printf("\nInvalid Input\n\nUse: ./fractol [mandelbrot |\
					julia <value> <value> | burning_ship]\n\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

// int	main(int argc, char **argv)
// {
// 	// mlx_image_t		*img;
// 	// mlx_t			*mlx;

// 	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10))
// 		|| (argc == 4 && ft_strncmp(argv[1], "julia", 5)))
// 	{
		
// 	}
// 	else
// 	{
// 		ft_printf("Usage: ./fractol [mandelbrot | julia | burning_ship]\n");
// 		return (EXIT_FAILURE);
// 	}
// 	// mlx_set_setting(MLX_MAXIMIZED, true);
// 	// mlx = mlx_init(WIDTH, HEIGHT, "42 - Fractol", true);
// 	// if (!mlx)
// 	// 	ft_error();
// 	// img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	// if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
// 	// 	ft_error();
// 	// generate_fractol(argc, argv, img);
// 	// mlx_image_to_window(mlx, img, 100, 100);
// 	// mlx_loop(mlx);
// 	// mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }