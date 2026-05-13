/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                */
/*   Created: 2025/12/25 16:52:55 by abait-el          */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file push.c
 * @brief Stack push/pop operations.
 * 
 * Implements the push operations (pa, pb) which move the top element
 * from one stack to the top of another stack.
 */

#include "push_swap.h"

/**
 * @brief Internal function to push the top node from one stack to another.
 * 
 * Removes the head from the source stack and makes it the head of
 * the destination stack.
 * 
 * @param from Pointer to the source stack
 * @param to   Pointer to the destination stack
 * @return true if push succeeded, false if source is empty
 */
static t_bool	ps_stack_push(t_stack_node **from, t_stack_node **to)
{
	t_stack_node	*node;

	if (!from || !*from || !to)
		return (false);
	node = *from;
	*from = node->next;
	if (*from)
		(*from)->prev = NULL;
	node->next = *to;
	if (*to)
		(*to)->prev = node;
	node->prev = NULL;
	*to = node;
	return (true);
}

/**
 * @brief Pushes the top element from stack B to stack A.
 * 
 * Operation: pa
 * Effect: The top of B becomes the top of A
 * 
 * @param a     Pointer to stack A (destination)
 * @param b     Pointer to stack B (source)
 * @param print If true, prints the operation name
 * @return true if push succeeded
 */
t_bool	ps_pa(t_stack_node **a, t_stack_node **b, t_bool print)
{
	if (print)
		ps_puts("pa");
	return (ps_stack_push(b, a));
}

/**
 * @brief Pushes the top element from stack A to stack B.
 * 
 * Operation: pb
 * Effect: The top of A becomes the top of B
 * 
 * @param b     Pointer to stack B (destination)
 * @param a     Pointer to stack A (source)
 * @param print If true, prints the operation name
 * @return true if push succeeded
 */
t_bool	ps_pb(t_stack_node **b, t_stack_node **a, t_bool print)
{
	if (print)
		ps_puts("pb");
	return (ps_stack_push(a, b));
}
