/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 22:23:31 by abait-el          #+#    #+#             */
/*   Updated: 2026/01/29 15:48:43 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>
#include <stdio.h>

static void ps_move_until_n(t_stack_node **a, t_stack_node **b, size_t n, t_bool display)
{
	*b = NULL;
	while ((size_t)ps_stack_size(*a) > n) 
		ps_pb(b, a, display);
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
