/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queries.c                                          */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                */
/*   Created: 2025/12/25 16:55:45 by abait-el          */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file queries.c
 * @brief Stack query and search functions.
 * 
 * This file contains utility functions for querying stack properties such as
 * finding nodes by value, finding min/max values, checking if sorted, etc.
 */

#include "push_swap.h"

/**
 * @brief Finds a node with a specific value in the stack.
 * 
 * Traverses the stack from head to tail looking for a node with
 * the specified value.
 * 
 * @param stack Pointer to the head of the stack
 * @param n     The value to search for
 * @return Pointer to the first node with the value, or NULL if not found
 */
t_stack_node	*ps_stack_find(t_stack_node *stack, int n)
{
	while (stack)
	{
		if (stack->value == n)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/**
 * @brief Finds the node with the smallest value.
 * 
 * Traverses the stack and returns a pointer to the node containing
 * the minimum value.
 * 
 * @param stack Pointer to the head of the stack
 * @return Pointer to the node with smallest value, or NULL if empty
 */
t_stack_node	*ps_stack_find_smallest(t_stack_node *stack)
{
	t_stack_node	*smallest;

	if (!stack)
		return (NULL);
	smallest = stack;
	while (stack)
	{
		if (stack->value < smallest->value)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

/**
 * @brief Finds the last node in the stack.
 * 
 * Traverses to the tail of the stack and returns it.
 * 
 * @param stack Pointer to the head of the stack
 * @return Pointer to the last node, or NULL if empty
 */
t_stack_node	*ps_stack_find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/**
 * @brief Checks if the stack is sorted in ascending order.
 * 
 * Traverses the stack and compares each node with its next node.
 * 
 * @param stack Pointer to the head of the stack
 * @return true if sorted (or empty), false otherwise
 */
t_bool	ps_stack_is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

/**
 * @brief Calculates the number of nodes in the stack.
 * 
 * Traverses the stack and counts all nodes.
 * 
 * @param stack Pointer to the head of the stack
 * @return Number of nodes, or -1 if stack is NULL
 */
ssize_t	ps_stack_size(t_stack_node *stack)
{
	ssize_t	size;

	if (!stack)
		return (-1);
	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

/**
 * @brief Finds the node with the maximum value.
 * 
 * Traverses the stack and returns a pointer to the node containing
 * the maximum value.
 * 
 * @param stack Pointer to the head of the stack
 * @return Pointer to the node with maximum value, or NULL if empty
 */
t_stack_node	*ps_stack_max(t_stack_node *stack)
{
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	while (stack)
	{
		if (stack->value > max_node->value)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

/**
 * @brief Finds a node by its index in the stack.
 * 
 * Traverses the stack looking for a node at the specified index.
 * 
 * @param stack Pointer to the head of the stack
 * @param index The index to search for (0-based)
 * @return Pointer to the node at that index, or NULL if not found
 */
t_stack_node	*ps_stack_find_index(t_stack_node *stack, int index)
{
	while (stack)
	{
		if ((int)stack->index == index)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/**
 * @brief Finds the node with the minimum value.
 * 
 * Traverses the stack and returns a pointer to the node containing
 * the minimum value. (Alias for ps_stack_find_smallest)
 * 
 * @param stack Pointer to the head of the stack
 * @return Pointer to the node with minimum value, or NULL if empty
 */
t_stack_node	*ps_stack_min(t_stack_node *stack)
{
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	while (stack)
	{
		if (stack->value < min_node->value)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}
