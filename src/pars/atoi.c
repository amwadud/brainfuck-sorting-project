/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:05:46 by abait-el          #+#    #+#             */
/*   Updated: 2026/02/05 05:16:13 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define PS_INT_MAX 2147483647L
#define PS_INT_MIN_ABS 2147483648L

static int	ps_atoi_parse_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static t_bool	ps_atoi_will_overflow(long n, int digit, int sign)
{
	if (sign == 1)
		return (n > (PS_INT_MAX - digit) / 10);
	return (n > (PS_INT_MIN_ABS - digit) / 10);
}

t_bool	ps_atoi(const char *str, int *out)
{
	long	n;
	int		sign;
	int		digit;

	if (!str || !*str)
		return (false);
	sign = ps_atoi_parse_sign(&str);
	if (!*str)
		return (false);
	n = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		digit = *str - '0';
		if (ps_atoi_will_overflow(n, digit, sign))
			return (false);
		n = n * 10 + digit;
		str++;
	}
	*out = (int)(n * sign);
	return (true);
}
