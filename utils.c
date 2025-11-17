/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 07:00:00 by auto-refact       #+#    #+#             */
/*   Updated: 2025/11/16 21:00:03 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->data + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

double	map(double value, double max_val, double offset)
{
	return (offset + (value / max_val - 0.5) * 4.0);
}

double	map_range(double value, t_range in, t_range out)
{
	if (in.max - in.min == 0)
		return (out.min);
	return (out.min + (value - in.min) * (out.max - out.min)
		/ (in.max - in.min));
}
