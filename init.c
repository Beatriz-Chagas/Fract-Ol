/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:04:01 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/16 21:04:27 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <string.h>

void	init_fractal(t_fractal *f, int ac, char **av)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	f->img.ptr = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->img.data = mlx_get_data_addr(f->img.ptr, &f->img.bpp,
			&f->img.line_len, &f->img.endian);
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->max_iter = 50;
	f->palette = 0;
	f->julia_c.real = 0.0;
	f->julia_c.imag = 0.0;
	f->fractal_type = FRACT_MANDEL;
	if (ac >= 2 && strcmp(av[1], "julia") == 0)
	{
		f->fractal_type = FRACT_JULIA;
		if (ac == 4)
		{
			f->julia_c.real = atof(av[2]);
			f->julia_c.imag = atof(av[3]);
		}
	}
	else if (ac >= 2 && (strcmp(av[1], "burning") == 0
			|| strcmp(av[1], "burningship") == 0 || strcmp(av[1], "ship") == 0))
		f->fractal_type = FRACT_BURNING;
}
