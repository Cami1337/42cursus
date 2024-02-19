/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:17:26 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/15 14:07:29 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 256
# define HEIGHT 256

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"

/* Main MLX handle, carries important data in regards to the program.
 * @param window The window itself.
 * @param context Abstracted opengl data.
 * @param width The width of the window.
 * @param height The height of the window.
 * @param delta_time The time difference between the previous frame and the current frame.
 */

typedef struct s_mlx
{
	void			*window;
	void			*context;
	int32_t			width;
	int32_t			height;
	double			delta_time;
	mlx_texture_t	*texture;
	mlx_image_t		*image;
}	t_mlx;

#endif