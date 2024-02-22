/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:42:52 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/22 16:22:25 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
