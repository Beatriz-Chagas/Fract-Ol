/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:04:07 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/17 03:35:42 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdlib.h>

/*
 * close_window
 * ----------
 * Handler simples para o evento de fechar a janela (ex: botão fechar).
 * Fecha o processo imediatamente.
 * Parâmetros:
 *  - param: não utilizado (mantido por compatibilidade com a API).
 */
int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
/*
 * Mouse and motion hooks moved to hooks_bonus.c to separate bonus features.
 */
