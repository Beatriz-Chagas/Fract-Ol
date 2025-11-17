/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:03:30 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/16 22:57:54 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/*
 * render_row
 * ----------
 * Renderiza uma linha (y) do buffer de imagem, calculando para cada x a
 * correspondente coordenada no plano complexo, selecionando o algoritmo
 * de iteração conforme o tipo de fractal e escrevendo a cor no pixel.
 * Parâmetros:
 *  - f: estado do fractal (inclui zoom, offsets, parâmetros Julia, etc.).
 *  - y: índice da linha (pixel) a ser renderizada.
 */
void	render_row(t_fractal *f, int y)
{
	int			x;
	int			i;
	t_complex	c;
	t_complex	z;

	x = 0;
	while (x < WIDTH)
	{
		c.real = map(x, WIDTH, f->offset_x) * f->zoom;
		c.imag = map(y, HEIGHT, f->offset_y) * f->zoom;
		if (f->fractal_type == FRACT_JULIA)
		{
			z.real = c.real;
			z.imag = c.imag;
			i = iterate_julia(z, f->julia_c, f->max_iter);
		}
		else if (f->fractal_type == FRACT_BURNING)
			i = iterate_burning(c, f->max_iter);
		else
			i = iterate_mandelbrot(c, f->max_iter);
		pixel_put(&f->img, x, y, color_map(i, f->max_iter, f->palette));
		x++;
	}
}

/*
 * render_fractal
 * ----------
 * Percorre todas as linhas da imagem e chama `render_row` para cada uma.
 * Ao final, envia a imagem renderizada para a janela usando MLX.
 */
void	render_fractal(t_fractal *f)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		render_row(f, y);
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.ptr, 0, 0);
}

/*
 * draw_fractal
 * ----------
 * Função de alto nível para desenhar o fractal. Atualmente delega para
 * `render_fractal`, mas existe como ponto único de entrada caso seja
 * desejável adicionar efeitos ou renderização incremental no futuro.
 */
void	draw_fractal(t_fractal *f)
{
	render_fractal(f);
}
