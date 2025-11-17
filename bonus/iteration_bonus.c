/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 03:10:00 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/17 07:09:31 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include <math.h>

// z = real(z) + i*imag(z) + c 
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
