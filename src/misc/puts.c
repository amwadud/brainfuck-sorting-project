/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                */
/*   Created: 2025/12/25 22:19:51 by abait-el          */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file puts.c
 * @brief Output utility functions.
 * 
 * Provides simple string output functionality for printing
 * operation names to stdout.
 */

#include "push_swap.h"

/**
 * @brief Calculates the length of a string.
 * 
 * Simple strlen implementation.
 * 
 * @param str String to measure
 * @return Number of characters (excluding null terminator)
 */
static size_t	ps_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

/**
 * @brief Writes a string to stdout followed by a newline.
 * 
 * Similar to puts() from the standard library, but writes to
 * stdout explicitly and returns the number of bytes written.
 * 
 * @param str String to write (must not be NULL)
 * @return Number of bytes written (excluding newline), or -1 on error
 */
ssize_t	ps_puts(char *str)
{
	ssize_t	bytes_written;

	if (!str)
		return (-1);
	bytes_written = write(STDOUT_FILENO, str, ps_strlen(str));
	if (bytes_written < 0)
		return (-1);
	if (write(STDOUT_FILENO, "\n", 1) < 0)
		return (-1);
	return (bytes_written + 1);
}
