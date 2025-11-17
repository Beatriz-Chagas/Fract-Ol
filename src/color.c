/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:04:23 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/16 22:57:54 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/*
 * palette1
 * ----------
 * Gera uma cor baseada em uma interpolação polinomial suave.
 * Parâmetros:
 *  - t: valor normalizado entre 0.0 e 1.0 que representa a posição
 *       ao longo do gradiente de cores (proporção da iteração).
 * Retorno:
 *  - Inteiro RGB (0xRRGGBB) resultante da combinação dos canais.
 * Observações:
 *  - Função estática usada apenas internamente a este ficheiro.
 */
static int	palette1(double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	if (r < 0)
			r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	return ((r << 16) | (g << 8) | b);
}

/*
 * palette2
 * ----------
 * Variante de paleta que mistura um canal vermelho decrescente com
 * componentes verdes/azuis calculados por polinômios. Recebe o mesmo
 * parâmetro normalizado `t` e retorna um inteiro RGB.
 */
static int	palette2(double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(20 * (1 - t));
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

/*
 * palette3
 * ----------
 * Paleta que usa funções seno para gerar cores cíclicas suaves no espectro.
 * O parâmetro `t` é mapeado para um ângulo e cada canal RGB aplica um
 * deslocamento de fase diferente, produzindo transições suaves e variadas.
 */
static int	palette3(double t)
{
	double	tt;
	int		r;
	int		g;
	int		b;

	tt = t * 2.0 * M_PI;
	r = (int)((sin(tt * 0.9 + 0.0) * 0.5 + 0.5) * 255);
	g = (int)((sin(tt * 0.9 + 2.0) * 0.5 + 0.5) * 255);
	b = (int)((sin(tt * 0.9 + 4.0) * 0.5 + 0.5) * 255);
	return ((r << 16) | (g << 8) | b);
}

/*
 * color_map
 * ----------
 * Calcula a cor de um pixel com base no número de iterações `i` e no
 * limite `max_iter`. Se o ponto pertence ao conjunto (i >= max_iter),
 * retorna preto. Caso contrário, normaliza `i` para [0,1] e delega para
 * uma das paletas disponíveis.
 * Parâmetros:
 *  - i: número de iterações até escapar (ou valor de parada).
 *  - max_iter: número máximo de iterações usado na geração.
 *  - palette: índice da paleta (0..PALETTE_COUNT-1).
 * Retorno:
 *  - cor no formato 0xRRGGBB.
 */
int	color_map(int i, int max_iter, int palette)
{
	double	t;

	if (i >= max_iter)
		return (0x000000);
	t = (double)i / (double)max_iter;
	if (palette == 0)
		return (palette1(t));
	if (palette == 1)
		return ((int)(255 * t) << 16 | (int)(255 * t) << 8 | (int)(255 * t));
	if (palette == 2)
		return (palette2(t));
	return (palette3(t));
}
