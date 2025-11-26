/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:04:23 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/23 22:04:24 by bchagas-         ###   ########.fr       */
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
	int	r;
	int	g;
	int	b;

	r = (int)(255.0 * (0.8 + 0.2 * t));int	ft_strcmp(const char *s1, const char *s2)

	g = (int)(255.0 * (0.2 + 0.8 * (t * t)));
	b = (int)(50.0 * (1.0 - t));
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	return ((r << 16) | (g << 8) | b);
}

static int	palette3(double t)
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

int	color_map(int i, int max_iter, int palette)
{
	double	t;

	if (i >= max_iter)
		return (0x000000);
	t = (double)i / (double)max_iter;
	if (palette == 0)
		return (palette1(t));
	if (palette == 1)
		return ((int)(255 * t) << 16 | (int)(255 * t) << 8 | (int)(255 * t));
	if (palette == 2)
		return (palette2(t));
	return (palette3(t));
}
