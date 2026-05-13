/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                */
/*   Created: 2025/12/25 22:23:31 by abait-el          */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file push_swap.c
 * @brief Main sorting algorithm implementation.
 * 
 * Implements the "Mechanical Turk" sorting algorithm:
 * 1. For stacks of size <= 2: use simple swap or sort_three
 * 2. For larger stacks:
 *    - Push elements to stack B (keeping small elements at bottom)
 *    - Calculate costs for each element in B to find its target in A
 *    - Move the "cheapest" element (least rotations needed)
 *    - Repeat until B is empty
 *    - Final rotation to position smallest element at top
 */

#include "push_swap.h"

/**
 * @brief Simple implementation that pushes all elements to stack B.
 * 
 * Used for small stacks (size <= 50).
 * 
 * @param a       Pointer to stack A
 * @param b       Pointer to stack B
 * @param n       Target size to reduce stack A to
 * @param display If true, prints each operation
 */
static void	ps_basic_move_until_n(t_stack_node **a, t_stack_node **b, size_t n,
		t_bool display)
{
	while (ps_stack_size(*a) > (ssize_t)n)
		ps_pb(b, a, display);
}

/**
 * @brief Calculates the average value of elements in the stack.
 * 
 * Used to determine pivot for pushing elements to stack B.
 * 
 * @param a Pointer to stack A
 * @return Average value, or 0 if stack is empty
 */
static long	ps_calculate_avg(t_stack_node *a)
{
	ssize_t			size;
	long			sum;
	t_stack_node	*tmp;

	sum = 0;
	size = ps_stack_size(a);
	if (size == 0)
		return (0);
	tmp = a;
	while (tmp)
	{
		sum += tmp->value;
		tmp = tmp->next;
	}
	return (sum / size);
}

/**
 * @brief Moves elements from stack A to stack B until n elements remain.
 * 
 * For stacks larger than 50, uses the average-based pivot to keep
 * smaller elements near the bottom of stack B (better for final sort).
 * Also rotates stack B when pushing elements above average to optimize.
 * 
 * @param a       Pointer to stack A
 * @param b       Pointer to stack B
 * @param n       Target size to reduce stack A to
 * @param display If true, prints each operation
 */
static void	ps_move_until_n(t_stack_node **a, t_stack_node **b, size_t n,
		t_bool display)
{
	ssize_t	size;
	long	avg;

	size = ps_stack_size(*a);
	if (size <= 50)
	{
		ps_basic_move_until_n(a, b, n, display);
		return ;
	}
	if (size <= (ssize_t)n)
		return ;
	avg = ps_calculate_avg(*a);
	while (ps_stack_size(*a) > (ssize_t)n)
	{
		ps_pb(b, a, display);
		if ((*b)->value > avg && ps_stack_size(*b) > 1)
			ps_rb(b, display);
	}
}

/**
 * @brief Main sorting function that orchestrates the algorithm.
 * 
 * Entry point for the sorting algorithm. Handles different stack sizes:
 * - 0-1 elements: already sorted
 * - 2 elements: single swap
 * - 3 elements: optimized sort_three
 * - 4+ elements: Mechanical Turk algorithm
 * 
 * @param a       Pointer to stack A
 * @param display If true, prints each operation
 * @return true if sorting completed successfully
 */
t_bool	ps_sort(t_stack_node **a, t_bool display)
{
	t_stack_node	*b;

	if (!a || !*a || !ps_stack_size(*a))
		return (false);
	if (ps_stack_is_sorted(*a))
		return (true);
	if (ps_stack_size(*a) == 2)
		ps_sa(a, display);
	else if (ps_stack_size(*a) == 3)
		ps_sort_three(a, display);
	else
	{
		b = NULL;
		/* Push elements from A to B, keeping only 3 in A */
		ps_move_until_n(a, &b, 3, display);
		/* Sort the remaining 3 elements in A */
		ps_sort_three(a, display);
		/* Move elements back to A in optimal order */
		while (b)
		{
			ps_refresh_stats(*a, b);
			ps_move_cheapest(a, &b);
		}
	}
	/* Final rotation to position smallest at top */
	ps_final_rotate(a, display);
	return (true);
}
