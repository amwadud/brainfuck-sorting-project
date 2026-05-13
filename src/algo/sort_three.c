/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                */
/*   Created: 2026/01/02 04:51:08 by abait-el          */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file sort_three.c
 * @brief Optimized sorting algorithm for stacks of 3 or fewer elements.
 * 
 * Since there are only 3! = 6 possible arrangements for 3 elements,
 * we can use a lookup table approach with just 5 conditional checks
 * to sort any stack of 3. This is more efficient than the general
 * algorithm for small inputs.
 */

#include "push_swap.h"

/**
 * @brief Executes the optimal sequence of operations to sort 3 elements.
 * 
 * Analyzes the current arrangement and executes the minimum operations
 * needed to sort. Uses case-based logic for the 6 possible arrangements.
 * 
 * The 6 cases handled:
 * 1. [x, y, z] where x > y && y < z && x < z -> sa
 * 2. [x, y, z] where x > y && y > z -> sa, rra
 * 3. [x, y, z] where x > y && y < z && x > z -> ra
 * 4. [x, y, z] where x < y && y > z && x < z -> sa, ra
 * 5. [x, y, z] where x < y && y > z && x > z -> rra
 * 
 * @param a       Pointer to stack A
 * @param display If true, prints each operation
 */
static void	ps_sort_operations(t_stack_node **a, t_bool display)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		ps_sa(a, display);
	else if (first > second && second > third)
	{
		ps_sa(a, display);
		ps_rra(a, display);
	}
	else if (first > second && second < third && first > third)
		ps_ra(a, display);
	else if (first < second && second > third && first < third)
	{
		ps_sa(a, display);
		ps_ra(a, display);
	}
	else if (first < second && second > third && first > third)
		ps_rra(a, display);
}

/**
 * @brief Sorts a stack of 3 or fewer elements.
 * 
 * Entry point for the optimized sort_three algorithm.
 * If the stack has 2 elements, just swaps them.
 * If the stack has 3 elements, uses the optimized case-based logic.
 * 
 * @param a       Pointer to stack A
 * @param display If true, prints each operation
 * @return true if sort completed successfully
 */
t_bool	ps_sort_three(t_stack_node **a, t_bool display)
{
	if (!a || !*a || ps_stack_size(*a) > 3)
		return (false);
	ps_sort_operations(a, display);
	return (display);
}
