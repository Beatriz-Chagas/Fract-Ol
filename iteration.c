/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:03:53 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/16 21:04:35 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	iterate_mandelbrot(t_complex c, int max_iter)
{
	t_complex	z;
	int			i;
	double		temp;

	z.real = 0;
	z.imag = 0;
	i = 0;
	while (i < max_iter)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp;
		if ((z.real * z.real + z.imag * z.imag) > 4)
			break ;
		i++;
	}
	return (i);
}

int	iterate_julia(t_complex z, t_complex c, int max_iter)
{
	int		i;
	double	temp;

	i = 0;
	while (i < max_iter)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp;
		if ((z.real * z.real + z.imag * z.imag) > 4)
			break ;
		i++;
	}
	return (i);
}

int	iterate_burning(t_complex c, int max_iter)
{
	t_complex	z;
	int			i;
	double		temp;
	double		zr;
	double		zi;

	z.real = 0;
	z.imag = 0;
	i = 0;
	while (i < max_iter)
	{
		zr = fabs(z.real);
		zi = fabs(z.imag);
		temp = zr * zr - zi * zi + c.real;
		z.imag = 2 * zr * zi + c.imag;
		z.real = temp;
		if ((z.real * z.real + z.imag * z.imag) > 4)
			break ;
		i++;
	}
	return (i);
}
