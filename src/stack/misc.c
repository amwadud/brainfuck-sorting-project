/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                */
/*   Created: 2025/12/25 16:57:11 by abait-el          */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file misc.c
 * @brief Core stack management functions.
 * 
 * This file contains functions for creating, manipulating, and cleaning up
 * the doubly linked list that represents the stack data structure.
 * 
 * @see push_swap.h for the t_stack_node structure definition.
 */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

/**
 * @brief Adds a new node to the end of the stack.
 * 
 * This function appends a newly created node to the tail of the stack.
 * If the stack is empty, the new node becomes the head.
 * 
 * @param stack Pointer to the stack pointer (head of the stack)
 * @param new   Pointer to the new node to add
 */
void	ps_stack_pushback(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node	*last;

	if (!stack || !new)
		return ;
	new->next = NULL;
	if (!*stack)
	{
		*stack = new;
		new->prev = NULL;
		return ;
	}
	last = ps_stack_find_last(*stack);
	last->next = new;
	new->prev = last;
}

/**
 * @brief Frees all nodes in the stack and sets the pointer to NULL.
 * 
 * This function traverses the entire stack, freeing each node,
 * and finally sets the stack pointer to NULL to avoid dangling pointers.
 * 
 * @param stack_head Pointer to the stack pointer (head of the stack)
 */
void	ps_stack_clean(t_stack_node **stack_head)
{
	t_stack_node	*tmp;

	if (!stack_head)
		return ;
	while (*stack_head)
	{
		tmp = *stack_head;
		*stack_head = (*stack_head)->next;
		free(tmp);
	}
	*stack_head = NULL;
}

/**
 * @brief Creates a new stack node with the given parameters.
 * 
 * Allocates memory for a new node and initializes its fields.
 * 
 * @param val   Integer value to store in the node
 * @param index Position index in the stack (0-based)
 * @param prev  Pointer to the previous node (NULL for head)
 * @param next  Pointer to the next node (NULL for tail)
 * @return Pointer to the newly created node, or NULL on allocation failure
 */
t_stack_node	*ps_stack_new(int val, int index, t_stack_node *prev,
		t_stack_node *next)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->value = val;
	node->index = index;
	node->prev = prev;
	node->next = next;
	return (node);
}

/**
 * @brief Applies a function to each node in the stack.
 * 
 * Iterates through the stack and applies the given function to each node.
 * 
 * @param stack Pointer to the head of the stack
 * @param f    Function pointer to apply to each node
 */
void	ps_stack_iter(t_stack_node *stack, void (*f)(t_stack_node **))
{
	t_stack_node	*current;

	current = stack;
	while (current)
	{
		f(&current);
		current = current->next;
	}
}
