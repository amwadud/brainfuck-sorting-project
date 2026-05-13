/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                */
/*   Created: 2026/02/06 05:24:13 by abait-el         */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file max.c
 * @brief Simple utility function to find the maximum of two integers.
 */

/**
 * @brief Returns the greater of two integers.
 * 
 * @param a First integer
 * @param b Second integer
 * @return The larger of a and b
 */
int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
