/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 03:03:35 by abait-el          #+#    #+#             */
/*   Updated: 2026/02/06 05:23:29 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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

void	ps_rotate_both_top(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while ((*b != cheapest) && (*a != cheapest->target))
		ps_rr(a, b, true);
}

void	ps_reverse_rotate_both_bottom(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while ((*b != cheapest) && (*a != cheapest->target))
		ps_rrr(a, b, true);
}

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
