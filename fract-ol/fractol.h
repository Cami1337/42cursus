/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:17:26 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/22 14:53:15 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1200
# define HEIGHT 1200

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"

# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_fractal
{
	void	*mlx_connection;
	void	*mlx_window;
	t_img	*img;
}			t_fractal;

void	fractal_init(t_fractal *fractal);

//helper
int		ft_compare_input(const char *s1, const char *s2, size_t n);
int		check_julia(int argc, char **argv);

#endif