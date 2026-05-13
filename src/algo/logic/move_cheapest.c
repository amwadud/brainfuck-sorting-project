/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest.c                                    */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                */
/*   Created: 2026/01/29 03:03:35 by abait-el          */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file move_cheapest.c
 * @brief Cheapest node selection and movement execution.
 * 
 * Implements the core of the Mechanical Turk algorithm:
 * 1. Find the node in stack B with the lowest total rotation cost
 * 2. Execute rotations to bring both B's node and A's target to top
 * 3. Push the node from B to A
 */

#include "push_swap.h"
#include <limits.h>

/**
 * @brief Finds the node in stack B with the lowest total rotation cost.
 * 
 * Total cost is calculated as:
 * - If both node and target are on same side of median: max(cost_a, cost_b)
 * - Otherwise: cost_a + cost_b
 * 
 * Using max instead of sum for same-side nodes allows for simultaneous
 * rotations (rr/rrr) which are more efficient.
 * 
 * @param stack Pointer to stack B
 * @return Pointer to the cheapest node to move
 */
static t_stack_node	*ps_get_cheapest(t_stack_node *stack)
{
	t_stack_node	*curr;
	t_stack_node	*cheapest;
	long			best_cost;
	long			curr_total_cost;

	curr = stack;
	cheapest = stack;
	best_cost = LONG_MAX;
	while (curr)
	{
		if (curr->above_median == curr->target->above_median)
			curr_total_cost = max(curr->cost, curr->target->cost);
		else
			curr_total_cost = curr->cost + curr->target->cost;
		if (curr_total_cost < best_cost)
		{
			best_cost = curr_total_cost;
			cheapest = curr;
		}
		curr = curr->next;
	}
	return (cheapest);
}

/**
 * @brief Brings a specific node to the top of a stack.
 * 
 * Rotates the stack forward (ra/rb) or reverse (rra/rrb) depending
 * on whether the node is above or below the median.
 * 
 * @param stack   Pointer to the stack
 * @param node    The node to bring to top
 * @param is_a    true if stack A, false if stack B (for operation selection)
 * @param display If true, prints each operation
 */
static void	ps_stack_bring_to_top(t_stack_node **stack, t_stack_node *node,
		t_bool is_a, t_bool display)
{
	if (!stack || !*stack || !node)
		return ;
	if (node->above_median)
	{
		while (*stack != node)
		{
			if (is_a)
				ps_ra(stack, display);
			else
				ps_rb(stack, display);
		}
	}
	else
	{
		while (*stack != node)
		{
			if (is_a)
				ps_rra(stack, display);
			else
				ps_rrb(stack, display);
		}
	}
}

/**
 * @brief Rotates both stacks simultaneously to bring both nodes to top.
 * 
 * Uses rr (rotate both) when both nodes are above the median.
 * 
 * @param a         Pointer to stack A
 * @param b         Pointer to stack B
 * @param cheapest  The cheapest node from stack B
 */
void	ps_rotate_both_top(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while ((*b != cheapest) && (*a != cheapest->target))
		ps_rr(a, b, true);
}

/**
 * @brief Reverse rotates both stacks simultaneously to bring both nodes to top.
 * 
 * Uses rrr (reverse rotate both) when both nodes are below the median.
 * 
 * @param a         Pointer to stack A
 * @param b         Pointer to stack B
 * @param cheapest  The cheapest node from stack B
 */
void	ps_reverse_rotate_both_bottom(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while ((*b != cheapest) && (*a != cheapest->target))
		ps_rrr(a, b, true);
}

/**
 * @brief Moves the cheapest node from stack B to stack A.
 * 
 * The main function that orchestrates the move:
 * 1. Find the cheapest node in B
 * 2. If both cheapest and target are above median, use simultaneous rr
 * 3. If both are below median, use simultaneous rrr
 * 4. Otherwise, rotate each stack individually
 * 5. Push from B to A
 * 
 * @param a Pointer to stack A
 * @param b Pointer to stack B (will be modified)
 */
void	ps_move_cheapest(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = ps_get_cheapest(*b);
	if (cheapest->above_median && cheapest->target->above_median)
		ps_rotate_both_top(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		ps_reverse_rotate_both_bottom(a, b, cheapest);
	ps_stack_bring_to_top(b, cheapest, false, true);
	ps_stack_bring_to_top(a, cheapest->target, true, true);
	ps_pa(a, b, true);
}
