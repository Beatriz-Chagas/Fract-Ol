/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:03:30 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/15 06:54:00 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** EPITECH PROJECT, 2025
** Fractol
** File description:
** Render functions
*/

#include "fractal.h"

void	render_row(t_fractal *f, int y)
{
	int			x;
	int			i;
	t_complex	c;
	t_complex	z;

	x = 0;
	while (x < WIDTH)
	{
		c.real = map(x, WIDTH, f->offset_x) * f->zoom;
		c.imag = map(y, HEIGHT, f->offset_y) * f->zoom;
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
		pixel_put(&f->img, x, y, color_map(i, f->max_iter, f->palette));
		x++;
	}
}

void	render_fractal(t_fractal *f)
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
void	draw_fractal(t_fractal *f)
{
	render_fractal(f);
}