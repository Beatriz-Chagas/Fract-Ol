/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 03:00:00 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/19 23:54:36 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include <stdlib.h>

int	mouse_hook(int button, int x, int y, void *param)
{
	t_fractal	*f;
	double		px;
	double		py;
	double		wx;
	double		wy;

	f = (t_fractal *)param;
	px = (double)x / (double)WIDTH;
	py = (double)y / (double)HEIGHT;
	px = (px - 0.5) * 4.0;
	py = (py - 0.5) * 4.0;
	wx = px * f->zoom + f->offset_x;
	wy = py * f->zoom + f->offset_y;
	if (button == 4)
		f->zoom *= 0.9;
	else if (button == 5)
		f->zoom *= 1.1;
	else
		return (0);
	f->offset_x = wx - px * f->zoom;
	f->offset_y = wy - py * f->zoom;
	draw_fractal(f);
	return (0);
}

int	motion_hook(int x, int y, void *param)
{
	t_fractal	*f;
	double		nx;
	double		ny;

	f = (t_fractal *)param;
	if ((f->fractal_type != FRACT_JULIA) || (!f->shift_held))
		return (0);
	nx = (double)x / (double)WIDTH;
	ny = (double)y / (double)HEIGHT;
	nx = (nx - 0.5) * 4.0 * f->zoom + f->offset_x;
	ny = (ny - 0.5) * 4.0 * f->zoom + f->offset_y;
	f->julia_c.real = nx;
	f->julia_c.imag = ny;
	draw_fractal(f);
	return (0);
}
