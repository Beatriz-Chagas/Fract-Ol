/* ************************************************************************** */
/*                                                                            */
/*                                                     :::      ::::::::    */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                  +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 04:00:00 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/17 04:00:00 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "fractal.h"

int	key_hook(int keycode, void *param);
int	mouse_hook(int button, int x, int y, void *param);
int	motion_hook(int x, int y, void *param);
int	iterate_burning(t_complex c, int max_iter);

#endif
