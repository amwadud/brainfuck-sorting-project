/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                */
/*   Created: 2025/12/13 12:05:46 by abait-el          */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file atoi.c
 * @brief Safe string-to-integer conversion with overflow protection.
 * 
 * This implementation validates input and prevents integer overflow,
 * unlike the standard atoi() function which has undefined behavior
 * on overflow.
 */

#include "push_swap.h"

#define PS_INT_MAX 2147483647L
#define PS_INT_MIN_ABS 2147483648L

/**
 * @brief Parses an optional sign character from the string.
 * 
 * Handles both '+' and '-' characters. Advances the string pointer
 * past the sign if found.
 * 
 * @param str Pointer to the string pointer (will be advanced)
 * @return 1 for positive, -1 for negative
 */
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

/**
 * @brief Checks if adding a digit would cause integer overflow.
 * 
 * Uses careful arithmetic to detect potential overflow before it happens.
 * 
 * @param n     Current accumulated value
 * @param digit The digit (0-9) to add
 * @param sign  The sign of the number (1 or -1)
 * @return true if adding this digit would overflow, false otherwise
 */
static t_bool	ps_atoi_will_overflow(long n, int digit, int sign)
{
	if (sign == 1)
		return (n > (PS_INT_MAX - digit) / 10);
	return (n > (PS_INT_MIN_ABS - digit) / 10);
}

/**
 * @brief Converts a string to an integer with overflow protection.
 * 
 * This function safely converts a string to an integer, checking for:
 * - Valid integer format (optional sign followed by digits)
 * - Integer overflow (both positive and negative)
 * - Empty or NULL input
 * 
 * @param str The string to convert
 * @param out Pointer to store the resulting integer
 * @return true if conversion succeeded, false on error (invalid format or overflow)
 */
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
