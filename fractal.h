/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:27:48 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/16 19:26:16 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000
# define PALETTE_COUNT 4
# define FRACT_MANDEL 0
# define FRACT_JULIA 1
# define FRACT_BURNING 2
# define MESSAGE "Usage: ./fractol [fractal] [julia_real julia_imag]\n"

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_img
{
	void	*ptr;
	char	*data;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_range
{
	double	min;
	double	max;
}	t_range;

typedef struct s_fractal
{
	void		*mlx;
	void		*win;
	t_img		img;
	double		zoom;
	double		offset_x;
	double		offset_y;
	int			max_iter;
	t_complex	julia_c;
	int			palette;
	int			fractal_type;
}	t_fractal;

void	draw_fractal(t_fractal *f);
void	render_fractal(t_fractal *f);
void	render_row(t_fractal *f, int y);
int		iterate_mandelbrot(t_complex c, int max_iter);
int		iterate_julia(t_complex z, t_complex c, int max_iter);
int		iterate_burning(t_complex c, int max_iter);
void	pixel_put(t_img *img, int x, int y, int color);
double	map(double value, double max_val, double offset);
double	map_range(double value, t_range in, t_range out);
void	init_fractal(t_fractal *f, int ac, char **av);
int		key_hook(int keycode, void *param);
int		mouse_hook(int button, int x, int y, void *param);
int		motion_hook(int x, int y, void *param);
int		close_window(void *param);
int		color_map(int i, int max_iter, int palette);

#endif
