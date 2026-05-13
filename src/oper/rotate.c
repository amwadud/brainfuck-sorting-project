/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                */
/*   Created: 2025/12/25 16:52:45 by abait-el          */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file rotate.c
 * @brief Stack rotation operations.
 * 
 * Implements the rotation operations (ra, rb, rr) which shift all
 * elements up by one position. The top element moves to the bottom.
 */

#include "push_swap.h"

/**
 * @brief Internal function to rotate a stack (shift up).
 * 
 * Takes the head and moves it to the tail, making the second
 * element the new head.
 * 
 * @param head Pointer to the stack pointer (will be modified)
 * @return true if rotation succeeded, false if stack has less than 2 nodes
 */
static t_bool	ps_stack_rotate(t_stack_node **head)
{
	t_stack_node	*top;
	t_stack_node	*tail;

	if (!head || !*head || !(*head)->next)
		return (false);
	top = *head;
	tail = ps_stack_find_last(*head);
	*head = top->next;
	(*head)->prev = NULL;
	top->next = NULL;
	top->prev = tail;
	tail->next = top;
	return (true);
}

/**
 * @brief Rotates stack A (shifts up all elements).
 * 
 * Operation: ra
 * Effect: First element moves to the bottom, all others shift up
 * 
 * @param a     Pointer to stack A
 * @param print If true, prints the operation name
 * @return true if rotation succeeded
 */
t_bool	ps_ra(t_stack_node **a, t_bool print)
{
	if (print)
		ps_puts("ra");
	return (ps_stack_rotate(a));
}

/**
 * @brief Rotates stack B (shifts up all elements).
 * 
 * Operation: rb
 * Effect: First element moves to the bottom, all others shift up
 * 
 * @param b     Pointer to stack B
 * @param print If true, prints the operation name
 * @return true if rotation succeeded
 */
t_bool	ps_rb(t_stack_node **b, t_bool print)
{
	if (print)
		ps_puts("rb");
	return (ps_stack_rotate(b));
}

/**
 * @brief Rotates both stacks A and B simultaneously.
 * 
 * Operation: rr
 * Effect: Performs ra and rb simultaneously
 * 
 * @param a     Pointer to stack A
 * @param b     Pointer to stack B
 * @param print If true, prints the operation name
 * @return true if both rotations succeeded
 */
t_bool	ps_rr(t_stack_node **a, t_stack_node **b, t_bool print)
{
	if (print)
		ps_puts("rr");
	return (ps_ra(a, false) && (ps_rb(b, false)));
}
