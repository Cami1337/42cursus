/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:31:13 by lglauch           #+#    #+#             */
/*   Updated: 2024/03/04 15:31:02 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	movement(mlx_key_data_t keydata, t_fractal *fractal)
{
	if (keydata.key == MLX_KEY_W)
		fractal->offset_y -= 10;
	else if (keydata.key == MLX_KEY_S)
		fractal->offset_y += 10;
	else if (keydata.key == MLX_KEY_A)
		fractal->offset_x -= 10;
	else if (keydata.key == MLX_KEY_D)
		fractal->offset_x += 10;
}
