/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 02:57:17 by abait-el          #+#    #+#             */
/*   Updated: 2026/01/30 10:59:44 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Assigns a rank (0 to size-1) to each node's index member.
 * This is essential for the chunk algorithm to work.
 */
static void	ps_assign_ranks(t_stack_node *a)
{
	t_stack_node	*curr;
	t_stack_node	*compare;
	int				rank;

	curr = a;
	while (curr)
	{
		rank = 0;
		compare = a;
		while (compare)
		{
			if (curr->value > compare->value)
				rank++;
			compare = compare->next;
		}
		curr->index = rank;
		curr = curr->next;
	}
}

/**
 * Handles small stacks of 3.
 */
t_bool	ps_sort_three(t_stack_node **a, t_bool display)
{
	int	first = (*a)->value;
	int	second = (*a)->next->value;
	int	third = (*a)->next->next->value;

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
	return (true);
}

/**
 * Phase 2: Push everything from B back to A.
 * Always finds the maximum value in B and rotates it to the top.
 */
static void	ps_back_to_a(t_stack_node **a, t_stack_node **b, t_bool display)
{
	t_stack_node	*max_node;
	ssize_t			size;
	ssize_t			pos;

	while (*b)
	{
		max_node = ps_stack_max(*b);
		size = ps_stack_size(*b);
		
		// Find position of max_node to decide rotation direction
		pos = 0;
		t_stack_node *tmp = *b;
		while (tmp != max_node)
		{
			pos++;
			tmp = tmp->next;
		}

		if (pos <= size / 2)
		{
			while (*b != max_node)
				ps_rb(b, display);
		}
		else
		{
			while (*b != max_node)
				ps_rrb(b, display);
		}
		ps_pa(a, b, display);
	}
}

/**
 * The Chunks Algorithm (Butterfly)
 */
t_bool	ps_sort(t_stack_node **a, t_bool display)
{
	t_stack_node	*b = NULL;
	int				i = 0;
	int				range;
	int				size = ps_stack_size(*a);

	if (!a || !*a || ps_stack_is_sorted(*a))
		return (true);

	// Step 1: Pre-process indices
	ps_assign_ranks(*a);

	// Step 2: Determine chunk size (range) based on total size
	if (size <= 100)
		range = 15; // Optimal for 100
	else
		range = 35; // Optimal for 500

	// Step 3: Phase 1 (A -> B)
	while (*a)
	{
		if ((*a)->index <= (size_t)i)
		{
			ps_pb(&b, a, display);
			ps_rb(&b, display); // Push to bottom of B
			i++;
		}
		else if ((*a)->index <= (size_t)i + range)
		{
			ps_pb(&b, a, display); // Stay at top of B
			i++;
		}
		else
			ps_ra(a, display);
	}

	// Step 4: Phase 2 (B -> A)
	ps_back_to_a(a, &b, display);

	return (true);
}
