/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                */
/*   Created: 2025/12/25 16:53:37 by abait-el          */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file reverse_rotate.c
 * @brief Stack reverse rotation operations.
 * 
 * Implements the reverse rotation operations (rra, rrb, rrr) which shift
 * all elements down by one position. The bottom element moves to the top.
 */

#include "push_swap.h"

/**
 * @brief Internal function to reverse rotate a stack (shift down).
 * 
 * Takes the tail and moves it to the head, making the second-to-last
 * element the new tail.
 * 
 * @param head Pointer to the stack pointer (will be modified)
 * @return true if reverse rotation succeeded, false if stack has less than 2 nodes
 */
static t_bool	ps_stack_reverse_rotate(t_stack_node **head)
{
	t_stack_node	*tail;

	if (!head || !*head || !(*head)->next)
		return (false);
	tail = ps_stack_find_last(*head);
	tail->prev->next = NULL;
	tail->next = *head;
	tail->prev = NULL;
	(*head)->prev = tail;
	*head = tail;
	return (true);
}

/**
 * @brief Reverse rotates stack A (shifts down all elements).
 * 
 * Operation: rra
 * Effect: Last element moves to the top, all others shift down
 * 
 * @param a     Pointer to stack A
 * @param print If true, prints the operation name
 * @return true if reverse rotation succeeded
 */
t_bool	ps_rra(t_stack_node **a, t_bool print)
{
	if (print)
		ps_puts("rra");
	return (ps_stack_reverse_rotate(a));
}

/**
 * @brief Reverse rotates stack B (shifts down all elements).
 * 
 * Operation: rrb
 * Effect: Last element moves to the top, all others shift down
 * 
 * @param b     Pointer to stack B
 * @param print If true, prints the operation name
 * @return true if reverse rotation succeeded
 */
t_bool	ps_rrb(t_stack_node **b, t_bool print)
{
	if (print)
		ps_puts("rrb");
	return (ps_stack_reverse_rotate(b));
}

/**
 * @brief Reverse rotates both stacks A and B simultaneously.
 * 
 * Operation: rrr
 * Effect: Performs rra and rrb simultaneously
 * 
 * @param a     Pointer to stack A
 * @param b     Pointer to stack B
 * @param print If true, prints the operation name
 * @return true if both reverse rotations succeeded
 */
t_bool	ps_rrr(t_stack_node **a, t_stack_node **b, t_bool print)
{
	if (print)
		ps_puts("rrr");
	return (ps_rra(a, false) && ps_rrb(b, false));
}
