/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_target.c                                      */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                */
/*   Created: 2026/02/05 06:16:46 by abait-el          */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file best_target.c
 * @brief Target node finding algorithm.
 * 
 * Determines the optimal target position in stack A for each element
 * in stack B. The target is the node in A that should come immediately
 * after B's element when the stack is sorted.
 */

#include "push_swap.h"
#include <limits.h>

/**
 * @brief Finds the smallest value in stack A that is greater than node's value.
 * 
 * This is the ideal target position for an element: the first element
 * in A that is larger than the element from B.
 * 
 * @param head Pointer to stack A
 * @param node The node from stack B to find target for
 * @return Pointer to the best match, or NULL if none found
 */
static t_stack_node	*find_best_match_above_target(t_stack_node *head,
		t_stack_node *node)
{
	t_stack_node	*curr;
	t_stack_node	*best_match;
	long			best_val;

	curr = head;
	best_match = NULL;
	best_val = LONG_MAX;
	while (curr)
	{
		if (curr->value > node->value && curr->value < best_val)
		{
			best_val = curr->value;
			best_match = curr;
		}
		curr = curr->next;
	}
	return (best_match);
}

/**
 * @brief Finds the smallest value in stack A.
 * 
 * Used as fallback when no element in A is greater than the element from B.
 * This handles the case where the element should go at the beginning.
 * 
 * @param head Pointer to stack A
 * @return Pointer to the smallest node
 */
static t_stack_node	*find_best_match_below_target(t_stack_node *head)
{
	t_stack_node	*curr;
	t_stack_node	*best_match;
	long			best_val;

	curr = head;
	best_match = NULL;
	best_val = LONG_MAX;
	while (curr)
	{
		if (curr->value < best_val)
		{
			best_val = curr->value;
			best_match = curr;
		}
		curr = curr->next;
	}
	return (best_match);
}

/**
 * @brief Finds the target position in stack A for a node from stack B.
 * 
 * The target is determined as follows:
 * 1. Find the smallest value in A that is greater than the node's value
 * 2. If no such value exists (node is larger than all in A), use the
 *    smallest value in A as target
 * 
 * @param head Pointer to stack A
 * @param node The node from stack B to find target for
 * @return Pointer to the target node in stack A
 */
t_stack_node	*ps_stack_find_target(t_stack_node *head, t_stack_node *node)
{
	t_stack_node	*best_match;

	best_match = find_best_match_above_target(head, node);
	if (!best_match)
		best_match = find_best_match_below_target(head);
	return (best_match);
}
