/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:03:53 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/17 03:35:42 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/* iterate_mandelbrot
  Calcula a iteração do conjunto de Mandelbrot para um ponto `c` no
 plano complexo. Começa com z=0 e itera z = z^2 + c até que |z| > 2
 ou até atingir `max_iter`.
 Parâmetros:
 - c: número complexo representando a coordenada no plano.
 - max_iter: número máximo de iterações permitidas.
 Retorno:
 - número de iterações realizadas antes de escapar (ou max_iter se não escapar).
 */
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

/*
 * iterate_julia
 * ----------
 * Executa as iterações do conjunto de Julia para um ponto inicial `z` e
 * parâmetro `c`. A regra de iteração é z = z^2 + c.
 * Parâmetros:
 *  - z: ponto inicial no plano complexo (coordenada do pixel).
 *  - c: parâmetro complexo que define a forma do fractal Julia.
 *  - max_iter: número máximo de iterações.
 * Retorno:
 *  - número de iterações até escapar (ou max_iter se não escapar).
 */
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
/* iterate_burning moved to iteration_bonus.c */

