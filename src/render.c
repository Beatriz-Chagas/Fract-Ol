/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:03:30 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/20 01:23:08 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	render_row(t_fractal *f, int y)
{
	int			x;
	int			i;
	t_complex	c;
	t_complex	z;

	x = 0;
	while (x < WIDTH)
	{
	c.real = f->offset_x + map(x, WIDTH, 0.0) * f->zoom;
	c.imag = f->offset_y + map(y, HEIGHT, 0.0) * f->zoom;
		if (f->fractal_type == FRACT_JULIA)
		{
			z.real = c.real;
			z.imag = c.imag;
			i = iterate_julia(z, f->julia_c, f->max_iter);
		}
		else if (f->fractal_type == FRACT_BURNING)
			i = iterate_burning(c, f->max_iter);
		else
			i = iterate_mandelbrot(c, f->max_iter);
		pixel_put(&f->img, x, y, color_map(f, i, f->max_iter));
		x++;
	}
}

void	draw_fractal(t_fractal *f)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		render_row(f, y);
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.ptr, 0, 0);
}
