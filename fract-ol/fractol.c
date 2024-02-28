/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:42:52 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/28 13:08:51 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_scroll_func(double xdelta, double ydelta, void *param)
{
    t_fractal *fractal;

    fractal = (t_fractal *)param;
    if (fractal == NULL || fractal->argv == NULL)
	{
		printf("fractal or fractal->argv is NULL\n");
        return;
	}

    printf("my_scroll_func called with xdelta: %f, ydelta: %f\n", xdelta, ydelta);

    printf("zoom before: %f\n", fractal->zoom);
    if (ydelta > 0 || xdelta > 0)
        fractal->zoom *= 1.1;
    else if (ydelta < 0 || xdelta < 0)
        fractal->zoom /= 1.1;
    printf("zoom after: %f\n", fractal->zoom);
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
		fractal_init(fractal, argv);
		mlx_scroll_hook(fractal->mlx_connection, my_scroll_func, fractal);
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


