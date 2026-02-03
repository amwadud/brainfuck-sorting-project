/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 22:23:31 by abait-el          #+#    #+#             */
/*   Updated: 2026/02/03 15:30:06 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>
#include <stdio.h>

/* static long	ps_get_stack_average(t_stack_node *s)
{
	long	sum;
	ssize_t	size;

	sum = 0;
	size = ps_stack_size(s);
	if (size == 0)
		return (0);
	while (s)
	{
		sum += s->value;
		s = s->next;
	}
	return (sum / size);
} */

static void ps_move_until_n(t_stack_node **a, t_stack_node **b, size_t n, t_bool display)
{
	long	sum;
	long	avg;
	ssize_t	size;
	t_stack_node *tmp;

	size = ps_stack_size(*a);
	if (size <= (ssize_t)n)
		return ;
	
	// 1. Calculate the average of the initial stack
	sum = 0;
	tmp = *a;
	while (tmp)
	{
		sum += tmp->value;
		tmp = tmp->next;
	}
	avg = sum / size;

	// 2. Push everything to B except n elements
	while (ps_stack_size(*a) > (ssize_t)n)
	{
		// Push to B
		ps_pb(b, a, display);
		
		// Optimization: If the pushed value is larger than the average, 
		// rotate B. This puts larger values at the bottom of B and 
		// smaller values at the top. This "semi-sorts" B.
		if ((*b)->value > avg && ps_stack_size(*b) > 1)
		{
			// If the next value in A is also going to be pushed but 
			// is smaller than average, we could potentially use rr.
			// For simplicity, we just use rb:
			ps_rb(b, display);
		}
	}
}

t_bool ps_sort(t_stack_node **a, t_bool display)
{
	t_stack_node	*b;

	if (!a || !*a || !ps_stack_size(*a))
		return (false);
	if (ps_stack_is_sorted(*a))
		return (true);
	if (ps_stack_size(*a) == 2)
		ps_sa(a, display);
	else if (ps_stack_size(*a) == 3)
		ps_sort_three(a, display);
	else
	{
		b = NULL;
		ps_move_until_n(a, &b, 3, display);
		ps_sort_three(a, display);
		while (b)
		{
			ps_refresh_stats(*a, b);
			ps_move_cheapest(a, &b);
		}
	}
	ps_final_rotate(a, display);
	return (true);
}
