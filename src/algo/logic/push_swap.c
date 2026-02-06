/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 22:23:31 by abait-el          #+#    #+#             */
/*   Updated: 2026/02/06 05:27:52 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>
#include <stdio.h>

static void	ps_basic_move_until_n(t_stack_node **a, t_stack_node **b, size_t n,
		t_bool display)
{
	while (ps_stack_size(*a) > (ssize_t)n)
		ps_pb(b, a, display);
}

static void	ps_calculate_sum_avg(t_stack_node *a, long *sum, long *avg)
{
	ssize_t			size;
	t_stack_node	*tmp;

	*sum = 0;
	*avg = 0;
	size = ps_stack_size(a);
	if (size == 0)
		return ;
	tmp = a;
	while (tmp)
	{
		*sum += tmp->value;
		tmp = tmp->next;
	}
	*avg = *sum / size;
}

static void	ps_move_until_n(t_stack_node **a, t_stack_node **b, size_t n,
		t_bool display)
{
	long	sum;
	long	avg;
	ssize_t	size;

	size = ps_stack_size(*a);
	if (size <= 50)
	{
		ps_basic_move_until_n(a, b, n, display);
		return ;
	}
	if (size <= (ssize_t)n)
		return ;
	ps_calculate_sum_avg(*a, &sum, &avg);
	while (ps_stack_size(*a) > (ssize_t)n)
	{
		ps_pb(b, a, display);
		if ((*b)->value > avg && ps_stack_size(*b) > 1)
			ps_rb(b, display);
	}
}

t_bool	ps_sort(t_stack_node **a, t_bool display)
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
