/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_stats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 22:59:24 by abait-el          #+#    #+#             */
/*   Updated: 2026/02/05 06:12:45 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>
#include <limits.h>

void	ps_calculate_costs(t_stack_node *head) 
{
	size_t	size;

	size = ps_stack_size(head);
	while (head)
	{
		if (head->index <= size / 2)
			head->cost = head->index;
		else
			head->cost = size - head->index;
		head = head->next;
	}
}

void set_index_and_median(t_stack_node *stack)
{
	int i = 0;
	int median = ps_stack_size(stack) / 2;

	while (stack)
	{
		stack->index = i;
		stack->above_median = (i <= median);
		stack = stack->next;
		i++;
	}
}

void	ps_refresh_stats(t_stack_node *a, t_stack_node *b)
{
	t_stack_node *curr_b;

	curr_b = b;
	set_index_and_median(a);
	set_index_and_median(b);
	while (curr_b)
	{
		curr_b->target = ps_stack_find_target(a, curr_b);
		curr_b = curr_b->next;
	}
	ps_calculate_costs(a); 
	ps_calculate_costs(b); 
}
