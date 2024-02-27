/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:42:52 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/27 18:56:33 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_scroll_func(double xdelta, double ydelta, void *param)
{
    t_fractal *fractal;

    fractal = (t_fractal *)param;
    if (fractal == NULL || fractal->argv == NULL)
        return;

    printf("my_scroll_func called with xdelta: %f, ydelta: %f\n", xdelta, ydelta);

    printf("zoom before: %f\n", fractal->zoom);
    if (ydelta > 0 || xdelta > 0)
        fractal->zoom *= 1.1;
    else if (ydelta < 0 || xdelta < 0)
        fractal->zoom /= 1.1;
    printf("zoom after: %f\n", fractal->zoom);
    fractal_create(fractal, fractal->argv);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_compare_input(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !check_julia(argc, argv)))
	{
		fractal_init(&fractal, argv);
		mlx_scroll_hook(fractal.mlx_connection, my_scroll_func, &fractal);
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
