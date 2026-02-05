/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 06:16:46 by abait-el          #+#    #+#             */
/*   Updated: 2026/02/05 06:16:46 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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

t_stack_node	*ps_stack_find_target(t_stack_node *head, t_stack_node *node)
{
	t_stack_node	*best_match;

	best_match = find_best_match_above_target(head, node);
	if (!best_match)
		best_match = find_best_match_below_target(head);
	return (best_match);
}
