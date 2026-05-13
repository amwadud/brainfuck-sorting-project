/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freematrix.c                                       */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                */
/*   Created: 2026/01/01 12:40:45 by abait-el          */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file freematrix.c
 * @brief Memory deallocation utility for string arrays.
 * 
 * Frees a NULL-terminated array of pointers and the array itself.
 */

#include "push_swap.h"
#include <stdlib.h>

/**
 * @brief Frees a NULL-terminated array of pointers and the array.
 * 
 * Iterates through the array, freeing each pointer, then frees
 * the array itself. Safe to call with NULL.
 * 
 * @param p Pointer to the array to free (NULL is safe)
 */
void	ps_freematrix(void **p)
{
	int	i;

	if (!p)
		return ;
	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p[i]);
	free(p);
}
