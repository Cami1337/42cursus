/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:17:26 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/22 16:27:59 by lglauch          ###   ########.fr       */
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

typedef struct s_pixel
{
	int	x;
	int	y;
	int	colour;
}		t_pixel;

typedef struct s_fractal
{
	void		*mlx_connection;
	void		*mlx_window;
	mlx_image_t	*img;
}			t_fractal;

void	fractal_init(t_fractal *fractal);
void	fractal_create(t_fractal *fractal);
t_pixel	make_pixel(int x, int y);

//helper
int		ft_compare_input(const char *s1, const char *s2, size_t n);
int		check_julia(int argc, char **argv);

#endif