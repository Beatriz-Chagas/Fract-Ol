/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:03:34 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/20 00:54:11 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	arg_message(void)
{
	ft_putstr("Write one of the options:\n" );
	ft_putstr("./fractol mandelbrot\n");
	ft_putstr("./fractol julia <x decimal> <y decimal>\n");
	ft_putstr("./fractol burningship\n");
}

int	main(int ac, char **av)
{
	t_fractal	f;

	if (ac < 2)
	{
		arg_message();
		return (1);
	}
	if (!(ft_strcmp(av[1], "mandelbrot") == 0
			|| ft_strcmp(av[1], "julia") == 0
			|| ft_strcmp(av[1], "burningship") == 0))
	{
		arg_message();
		return (1);
	}
	init_fractal(&f, ac, av);
	draw_fractal(&f);
	mlx_hook(f.win, 2, 1L << 0, key_press, &f);
	mlx_hook(f.win, 3, 1L << 1, key_release, &f);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_hook(f.win, 6, 1L << 6, motion_hook, &f);
	mlx_hook(f.win, 17, 0, close_window, &f);
	mlx_loop(f.mlx);
}
