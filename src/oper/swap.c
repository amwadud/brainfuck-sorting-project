/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                */
/*   Created: 2025/12/25 16:52:14 by abait-el          */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file swap.c
 * @brief Stack swap operations.
 * 
 * Implements the swap operations (sa, sb, ss) which exchange the positions
 * of the top two elements in one or both stacks.
 */

#include "push_swap.h"

/**
 * @brief Internal function to swap the first two nodes of a stack.
 * 
 * Takes the head and its next node, rearranges pointers to swap them.
 * The former second node becomes the new head.
 * 
 * @param head Pointer to the stack pointer (head will be modified)
 * @return true if swap succeeded, false if stack has less than 2 nodes
 */
static t_bool	ps_stack_swap(t_stack_node **head)
{
	t_stack_node	*fst;
	t_stack_node	*sec;

	if (!head || !*head || !(*head)->next)
		return (false);
	fst = *head;
	sec = fst->next;
	fst->next = sec->next;
	if (sec->next)
		sec->next->prev = fst;
	sec->prev = NULL;
	sec->next = fst;
	fst->prev = sec;
	*head = sec;
	return (true);
}

/**
 * @brief Swaps the top two elements of stack A.
 * 
 * Operation: sa
 * Effect: First element becomes second, second becomes first
 * 
 * @param a     Pointer to stack A
 * @param print If true, prints the operation name
 * @return true if swap succeeded
 */
t_bool	ps_sa(t_stack_node **a, t_bool print)
{
	if (print)
		ps_puts("sa");
	return (ps_stack_swap(a));
}

/**
 * @brief Swaps the top two elements of stack B.
 * 
 * Operation: sb
 * Effect: First element becomes second, second becomes first
 * 
 * @param b     Pointer to stack B
 * @param print If true, prints the operation name
 * @return true if swap succeeded
 */
t_bool	ps_sb(t_stack_node **b, t_bool print)
{
	if (print)
		ps_puts("sb");
	return (ps_stack_swap(b));
}

/**
 * @brief Swaps the top two elements of both stacks A and B.
 * 
 * Operation: ss
 * Effect: Performs sa and sb simultaneously
 * 
 * @param a     Pointer to stack A
 * @param b     Pointer to stack B
 * @param print If true, prints the operation name
 * @return true if both swaps succeeded
 */
t_bool	ps_ss(t_stack_node **a, t_stack_node **b, t_bool print)
{
	if (print)
		ps_puts("ss");
	return (ps_sa(a, false) && ps_sb(b, false));
}
