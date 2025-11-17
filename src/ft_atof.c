/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 03:16:10 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/17 07:31:50 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/*
 * Implementação em 5 funções pequenas (4 estáticas + ft_atof).
 * Não usa struct nem funções externas.
 */
/*
 * New implementation: apenas DUAS funções neste arquivo.
 * - ft_atof_helper (static): faz o parsing, avança o ponteiro e retorna 0/-1.
 * - ft_atof (pública): valida argumentos e chama o helper.
 */

/*
 * ft_skip_ws
 *	Pula espaços em branco e retorna ponteiro avançado.
 */
static const char	*ft_skip_ws(const char *s)
{
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r'
			|| *s == '\f' || *s == '\v'))
		s++;
	return (s);
}

/*
 * ft_extract_sign
 *	Retorna 1.0 ou -1.0 e avança o ponteiro quando houver '+'/'-'.
 */
static double	ft_extract_sign(const char **ps)
{
	double	sign;

	sign = 1.0;
	if (**ps == '+' || **ps == '-')
	{
		if (**ps == '-')
			sign = -1.0;
		(*ps)++;
	}
	return (sign);
}

/*
 * ft_parse_integer
 *	Acumula dígitos inteiros em *res e avança *ps; retorna 1 se encontrou dígitos.
 */
static int	ft_parse_integer(const char **ps, double *res)
{
	int	found;

	found = 0;
	while (**ps >= '0' && **ps <= '9')
	{
		*res = *res * 10.0 + (**ps - '0');
		found = 1;
		(*ps)++;
	}
	return (found);
}

/*
 * ft_parse_fraction
 *	Lê parte fracionária após '.' e acumula em *res; retorna 1 se houve dígitos.
 */
static int	ft_parse_fraction(const char **ps, double *res)
{
	double	place;

	if (**ps != '.')
		return (0);
	(*ps)++;
	place = 0.1;
	while (**ps >= '0' && **ps <= '9')
	{
		*res += (**ps - '0') * place;
		place *= 0.1;
		(*ps)++;
	}
	return (1);
}

/*
 * ft_atof
 *	Valida parâmetros, usa helpers e preenche *out com o valor convertido.
 */
int	ft_atof(const char *s, double *out)
{
	const char	*p;
	double		val;
	double		sign;
	int			has_int;
	int			has_frac;

	if (!s || !out)
		return (-1);
	p = ft_skip_ws(s);
	sign = ft_extract_sign(&p);
	val = 0.0;
	has_int = ft_parse_integer(&p, &val);
	has_frac = ft_parse_fraction(&p, &val);
	if (!has_int && !has_frac)
		return (-1);
	*out = sign * val;
	return (0);
}
