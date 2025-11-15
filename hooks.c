/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:04:07 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/15 06:35:11 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** EPITECH PROJECT, 2025
** Fractol
** File description:
** Mouse and window event handlers
*/

#include "fractal.h"
#include <stdlib.h>

int	mouse_hook(int button, int x, int y, void *param)
{
	t_fractal	*f;
	double		px;
	double		py;
	double		wx;
	double		wy;

	f = (t_fractal *)param;
	px = map(x, WIDTH, f->offset_x);
	py = map(y, HEIGHT, f->offset_y);
	wx = px * f->zoom;
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

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
