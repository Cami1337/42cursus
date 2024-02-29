/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:42:52 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/29 15:23:52 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_scroll_func(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (fractal == NULL || fractal->argv == NULL)
	{
		printf("fractal or fractal->argv is NULL\n");
		return ;
	}
	if (ydelta > 0 || xdelta > 0)
	{
		fractal->zoom *= 1.025;
		fractal->offset -= 10;
	}
	else if (ydelta < 0 || xdelta < 0)
	{
		fractal->zoom /= 1.025;
		fractal->offset += 10;
	}
	printf("zoom after: %f\n", fractal->zoom);
	printf("offset after: %d\n", fractal->offset);
	ft_memset(fractal->img->pixels, 0, WIDTH * HEIGHT);
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
		{
			printf("malloc failed\n");
			return (EXIT_FAILURE);
		}
		fractal->zoom = 1;
		fractal->offset = 0;
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