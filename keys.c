/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:03:40 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/15 06:09:38 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** EPITECH PROJECT, 2025
** Fractol
** File description:
** Keyboard event handler
*/

#include "fractal.h"
#include <stdlib.h>

int	key_hook(int keycode, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	if (keycode == 65307)
		exit(0);
	if (keycode == 32)
	{
		f->palette = (f->palette + 1) % PALETTE_COUNT;
		draw_fractal(f);
	}
	else if (keycode == 61)
		f->zoom *= 0.9;
	else if (keycode == 45)
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
