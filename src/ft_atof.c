/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 03:16:10 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/17 03:39:14 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
/*
 * ft_atof_skip
 * ----------
 * Salta espaços iniciais e extrai o sinal (+/-) da string.
 * Retorna um ponteiro para o primeiro caractere após o sinal,
 * e armazena o valor do sinal (1.0 ou -1.0) em *sign.
 */
const char	*ft_atof_skip(const char *s, double *sign)
{
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	*sign = 1.0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			*sign = -1.0;
		s++;
	}
	return (s);
}

/*
 * ft_atof_parse_integer
 * ----------
 * Converte a parte inteira de uma string. Atualiza st->result e st->p.
 * Retorna 1 se encontrou pelo menos um dígito, 0 caso contrário.
 */
int	ft_atof_parse_integer(t_atof_state *st)
{
	int	has_digits;

	has_digits = 0;
	while (*st->p >= '0' && *st->p <= '9')
	{
		st->result = st->result * 10.0 + (*st->p - '0');
		has_digits = 1;
		st->p++;
	}
	return (has_digits);
}

// ft_atof_parse_fraction
// Converte a parte fracionária de uma string (após o ponto).
// Retorna 1 se encontrou dígitos fracionários, 0 caso contrário.
int	ft_atof_parse_fraction(t_atof_state *st)
{
	int	has_digits;

	has_digits = 0;
	if (*st->p == '.')
		st->p++;
	while (*st->p >= '0' && *st->p <= '9')
	{
		st->result += (*st->p - '0') * st->decimal_place;
		st->decimal_place *= 0.1;
		has_digits = 1;
		st->p++;
	}
	return (has_digits);
}

/*
 ft_atof_parse_number
 Wrapper que usa ft_atof_parse_integer e ft_atof_parse_fraction.
 Retorna 0 em sucesso (com resultado em *out).
 */
int	ft_atof_parse_number(const char *s, double *out)
{
	t_atof_state	st;
	int				int_digits;
	int				frac_digits;

	if (!s || !out)
		return (-1);
	st.p = s;
	st.result = 0.0;
	st.sign = 1.0;
	st.decimal_place = 0.1;
	int_digits = ft_atof_parse_integer(&st);
	frac_digits = ft_atof_parse_fraction(&st);
	if (!int_digits && !frac_digits)
		return (-1);
	*out = st.result;
	return (0);
}

/*
 * ft_atof
 * ----------
 * Wrapper que usa ft_atof_skip e ft_atof_parse_number.
 * Converte string para double com verificação de erro.
 */
int	ft_atof(const char *s, double *out)
{
	double	sign;
	double	num;

	if (!s || !out)
		return (-1);
	s = ft_atof_skip(s, &sign);
	if (ft_atof_parse_number(s, &num) != 0)
		return (-1);
	*out = sign * num;
	return (0);
}
