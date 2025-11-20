/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:04:23 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/20 01:32:59 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	palette1(double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	if (r < 0)
			r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	return ((r << 16) | (g << 8) | b);
}

static int	palette2(double t)
{
	double	tt;
	int		r;
	int		g;
	int		b;

	tt = t * 2.0 * M_PI;
	r = (int)((sin(tt * 0.9 + 0.0) * 0.5 + 0.5) * 255);
	g = (int)((sin(tt * 0.9 + 2.0) * 0.5 + 0.5) * 255);
	b = (int)((sin(tt * 0.9 + 4.0) * 0.5 + 0.5) * 255);
	return ((r << 16) | (g << 8) | b);
}

static int lerp(int a, int b, double t)
{
	int r = ((a >> 16) & 0xFF) * (1 - t) + ((b >> 16) & 0xFF) * t;
	int g = ((a >> 8) & 0xFF) * (1 - t) + ((b >> 8) & 0xFF) * t;
	int b2 = (a & 0xFF) * (1 - t) + (b & 0xFF) * t;

	return (r << 16) | (g << 8) | b2;
}
int pick_palette(int palette, double t)
{
	if (palette == 0)
		return palette1(t);
	if (palette == 1)
		return ((int)(255 * t) << 16 | (int)(255 * t) << 8 | (int)(255 * t));
	else
		return palette2(t);
}

int color_map(t_fractal *f, int i, int max_iter)
{
	double t;
	int c1;
	int c2;

	if (i >= max_iter)
		return (0x000000);

	t = (double)i / (double)max_iter;

	if (!f->is_transitioning)
		return pick_palette(f->palette, t);

	c1 = pick_palette(f->old_palette, t);
	c2 = pick_palette(f->target_palette, t);

	return lerp(c1, c2, f->transition_t);
}
