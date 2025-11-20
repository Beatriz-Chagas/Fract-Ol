/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:04:01 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/19 23:04:38 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <string.h>

static void	parse_cli_fractal_args(t_fractal *f, int ac, char **av);

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
	f->max_iter = MAX_ITER;
	f->palette = 0;
	f->julia_c.real = 0.0;
	f->julia_c.imag = 0.0;
	f->fractal_type = FRACT_MANDEL;
	f->shift_held = 0;
	parse_cli_fractal_args(f, ac, av);
}

static void	parse_cli_fractal_args(t_fractal *f, int ac, char **av)
{
	double	tmp;

	if (ac >= 2 && ft_strcmp(av[1], "julia") == 0)
	{
		f->fractal_type = FRACT_JULIA;
		if (ac == 4)
		{
			if (ft_atof(av[2], &tmp) == 0)
				f->julia_c.real = tmp;
			if (ft_atof(av[3], &tmp) == 0)
				f->julia_c.imag = tmp;
		}
	}
	else if (ac >= 2 && (strcmp(av[1], "burningship") == 0))
		f->fractal_type = FRACT_BURNING;
}

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
