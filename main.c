/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:03:34 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/15 06:52:01 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main(int ac, char **av)
{
	t_fractal	f;

	if (ac < 2)
	{
		write(2, MESSAGE, 63);
		return (1);
	}
	init_fractal(&f, ac, av);
	draw_fractal(&f);
	mlx_key_hook(f.win, key_hook, &f);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_hook(f.win, 17, 0, close_window, &f);
	mlx_loop(f.mlx);
}
