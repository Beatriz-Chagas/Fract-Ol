/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 03:05:00 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/20 01:42:16 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include <stdlib.h>

int	key_press(int keycode, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	if (keycode == 65307)
		exit(0);
	if (keycode == 65505 || keycode == 65506)
		f->shift_held = 1;
	else if (keycode == 32)
		f->palette = (f->palette + 1) % PALETTE_COUNT;
	else if (keycode == 61 || keycode == 65451)
		f->zoom *= 0.9;
	else if (keycode == 45 || keycode == 65453)
		f->zoom *= 1.1;
	else if (keycode == 65361)
		f->offset_x -= 0.4 * f->zoom;
	else if (keycode == 65363)
		f->offset_x += 0.4 * f->zoom;
	else if (keycode == 65362)
		f->offset_y -= 0.4 * f->zoom;
	else if (keycode == 65364)
		f->offset_y += 0.4 * f->zoom;
	draw_fractal(f);
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	if (keycode == 65505 || keycode == 65506)
		f->shift_held = 0;
	return (0);
}
