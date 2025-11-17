/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:03:40 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/17 03:35:42 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdlib.h>

/*
 * key_hook
 * ----------
 * Trata eventos de teclado para controlar a visualização do fractal.
 * Suporta:
 *  - ESC (65307): sai do programa.
 *  - Espaço (32): alterna entre paletas de cores.
 *  - '+' (61) e '-' (45): aproximam/afastam o zoom.
 *  - Setas: deslocam o centro da visualização (offsets X/Y).
 * Parâmetros:
 *  - keycode: código da tecla pressionada (código X11 usado pelo MLX).
 *  - param: ponteiro para t_fractal (estado usado e atualizado).
 * Retorno:
 *  - retorna 0 (compatível com a assinatura exigida pelo MLX).
 */
/* Key handling moved to keys_bonus.c to separate bonus features */

