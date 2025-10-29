/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 05:52:13 by bchagas-          #+#    #+#             */
/*   Updated: 2025/08/21 09:54:38 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	ft_puthex(unsigned long n, char upper)
{
	int	res;
	int	digit;

	res = 0;
	if (n > 15)
		res += ft_puthex(n / 16, upper);
	digit = n % 16;
	if (digit <= 9)
		res += ft_putchar(digit + '0');
	else
	{
		if (upper)
			res += ft_putchar(digit - 10 + 'A');
		else
			res += ft_putchar(digit - 10 + 'a');
	}
	return (res);
}
