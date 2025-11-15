/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 07:00:00 by auto-refact       #+#    #+#             */
/*   Updated: 2025/11/15 06:41:22 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/*
** Put a 0xRRGGBB color into the image buffer at (x,y).
*/
void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->data + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

/*
** Map screen coordinate (0..max_val) to complex plane (-2..2 scaled by zoom).
** Used to convert pixel x,y to complex plane coordinates.
*/
double	map(double value, double max_val, double offset)
{
	return (offset + (value / max_val - 0.5) * 4.0);
}

/*
** Map value from range [in.min, in.max] to [out.min, out.max].
** Uses t_range struct to keep function to 3 arguments max.
*/
double	map_range(double value, t_range in, t_range out)
{
	if (in.max - in.min == 0)
		return (out.min);
	return (out.min + (value - in.min) * (out.max - out.min)
		/ (in.max - in.min));
}
