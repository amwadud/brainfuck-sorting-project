/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_final_rotate.c                                  */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                */
/*   Created: 2026/01/29 05:29:53 by abait-el          */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ps_final_rotate.c
 * @brief Final rotation to position the smallest element at the top.
 * 
 * After all elements have been moved back to stack A, this function
 * rotates the stack so that the smallest element is at the top (index 0).
 * This is required because push_swap expects the first argument to be
 * at the top of the stack.
 */

#include "push_swap.h"

/**
 * @brief Rotates stack A to position the smallest element at the top.
 * 
 * Finds the node with the smallest value and rotates the stack
 * to bring it to the top using the minimum number of rotations.
 * 
 * @param a       Pointer to stack A
 * @param display If true, prints each operation
 */
void	ps_final_rotate(t_stack_node **a, t_bool display)
{
	t_stack_node	*min_node;
	size_t			size;
	size_t			min_index;

	if (!a || !*a)
		return ;
	min_node = ps_stack_find_smallest(*a);
	size = ps_stack_size(*a);
	min_index = min_node->index;
	if (min_index <= size / 2)
	{
		while (*a != min_node)
			ps_ra(a, display);
	}
	else
	{
		while (*a != min_node)
			ps_rra(a, display);
	}
}
