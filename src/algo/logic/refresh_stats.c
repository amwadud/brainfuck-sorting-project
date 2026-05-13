/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_stats.c                                    */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                */
/*   Created: 2026/01/27 22:59:24 by abait-el          */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file refresh_stats.c
 * @brief Stack statistics calculation and target finding.
 * 
 * Updates index, median position, cost, and target node information
 * for all nodes in both stacks. This information is used by the
 * algorithm to determine the cheapest moves.
 */

#include "push_swap.h"

/**
 * @brief Calculates the rotation cost for each node in the stack.
 * 
 * Cost is the number of rotations needed to bring a node to the top:
 * - If index <= size/2, cost = index (rotate forward)
 * - Otherwise, cost = size - index (reverse rotate)
 * 
 * @param head Pointer to the head of the stack
 */
void	ps_calculate_costs(t_stack_node *head)
{
	size_t	size;

	size = ps_stack_size(head);
	while (head)
	{
		if (head->index <= size / 2)
			head->cost = head->index;
		else
			head->cost = size - head->index;
		head = head->next;
	}
}

/**
 * @brief Sets the index and median position for all nodes in a stack.
 * 
 * Assigns a 0-based index to each node and determines if the node
 * is in the "above median" (top half) or "below median" (bottom half)
 * of the stack.
 * 
 * @param stack Pointer to the head of the stack
 */
void	set_index_and_median(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	median = ps_stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		stack->above_median = (i <= median);
		stack = stack->next;
		i++;
	}
}

/**
 * @brief Refreshes all statistics for both stacks.
 * 
 * Updates:
 * 1. Index and median position for both stacks
 * 2. Target node in stack A for each node in stack B
 * 3. Rotation costs for both stacks
 * 
 * This function should be called before each move_cheapest operation.
 * 
 * @param a Pointer to stack A
 * @param b Pointer to stack B
 */
void	ps_refresh_stats(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*curr_b;

	curr_b = b;
	set_index_and_median(a);
	set_index_and_median(b);
	while (curr_b)
	{
		curr_b->target = ps_stack_find_target(a, curr_b);
		curr_b = curr_b->next;
	}
	ps_calculate_costs(a);
	ps_calculate_costs(b);
}
