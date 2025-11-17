/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:04:01 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/17 03:39:13 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <string.h>

/*
 * init_fractal
 * ----------
 * Inicializa a estrutura `t_fractal` com valores padrão e configura a
 * janela/porta de imagem do MLX. Também interpreta argumentos da linha
 * de comando para selecionar o tipo de fractal (por exemplo, "julia")
 * e, opcionalmente, os valores reais/imag do parâmetro c para Julia.
 * Parâmetros:
 *  - f: ponteiro para a estrutura que será inicializada.
 *  - ac, av: argumentos da linha de comando (usados para escolher fractal
 *            e parâmetros de Julia se fornecidos).
 * Comportamento:
 *  - Define zoom, offsets, iterações, paleta e parâmetros de Julia.
 *  - Cria a janela e a imagem usando a biblioteca MiniLibX.
 */
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
	if (ac >= 2 && ft_strcmp (av[1], "julia") == 0)
	{
		double tmp;

		f->fractal_type = FRACT_JULIA;
		if (ac == 4)
		{
			if (ft_atof(av[2], &tmp) == 0)
				f->julia_c.real = tmp;
			if (ft_atof(av[3], &tmp) == 0)
				f->julia_c.imag = tmp;
		}
	}
	else if (ac >= 2 && (strcmp(av[1], "burning") == 0
			|| strcmp(av[1], "burningship") == 0))
		f->fractal_type = FRACT_BURNING;
}
