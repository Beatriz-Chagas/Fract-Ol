/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:27:48 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/20 01:40:50 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 1000
# define HEIGHT 1000
# define PALETTE_COUNT 4
# define FRACT_MANDEL 0
# define FRACT_JULIA 1
# define FRACT_BURNING 2
# define MAX_ITER 100
# define MESSAGE "Type: ./fractol [fractal] (mandelbrot/julia/burningship)\n"

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
	int			shift_held;
}	t_fractal;

typedef struct s_atof_state
{
	const char	*p;
	double		result;
	double		sign;
	double		decimal_place;
}t_atof_state;

// Rendering Functions
void	draw_fractal(t_fractal *f);
void	render_fractal(t_fractal *f);
void	render_row(t_fractal *f, int y);
// Iterations for Fractals
int		iterate_mandelbrot(t_complex c, int max_iter);
int		iterate_julia(t_complex z, t_complex c, int max_iter);
// Utilities
void	pixel_put(t_img *img, int x, int y, int color);
double	map(double value, double max_val, double offset);
double	map_range(double value, t_range in, t_range out);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atof_parse_integer(t_atof_state *st);
int		ft_atof_parse_fraction(t_atof_state *st);
int		ft_atof_parse_number(const char *s, double *out);
int		ft_atof(const char *s, double *out);
char	*ft_atof_skip(const char *s, double *sign);

int		ft_putstr(char *s);
void	arg_message(void);
// Initialization and Hooks
void	init_fractal(t_fractal *f, int ac, char **av);
int		key_press(int keycode, void *param);
int		key_release(int keycode, void *param);
int		close_window(void *param);
// Color Mapping
int		color_map(int i, int max_iter, int palette);
#endif
