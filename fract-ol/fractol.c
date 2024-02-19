/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:42:52 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/15 14:08:05 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Exit the program as failure.
static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void	ft_hook(void *param)
{
	const mlx_t	*mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int32_t	main(void)
{
	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42 - Fractol", true);
	if (!mlx)
		ft_error();
	/* Do stuff */
	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	// Even after the image is being displayed, we can still modify the buffer.
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

// int	main(void)
// {
// 	t_mlx	*pic_mlx;
// 	mlx_t	*mlx;

// 	pic_mlx = malloc(sizeof(t_mlx));
// 	mlx = mlx_init(1200, 1200, "Fract'ol", true);
// 	pic_mlx->texture = mlx_load_png("image-asset.png");
// 	pic_mlx->image = mlx_texture_to_image(mlx, pic_mlx->texture);
// 	mlx_image_to_window(mlx, pic_mlx->image, 0, 0);
// 	mlx_loop(mlx);
// }