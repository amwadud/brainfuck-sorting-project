/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                    */
/*   Created: 2026/01/01 12:46:18 by abait-el          */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file string.c
 * @brief Simple string utility functions.
 */

#include "push_swap.h"

/**
 * @brief Locates the first occurrence of a character in a string.
 * 
 * A simplified implementation of strchr.
 * 
 * @param s String to search
 * @param c Character to find
 * @return Pointer to the first occurrence of c, or NULL if not found
 */
char	*ps_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		++s;
	}
	if (*s == c)
		return (s);
	return (NULL);
}
