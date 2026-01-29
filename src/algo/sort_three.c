/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 04:51:08 by abait-el          #+#    #+#             */
/*   Updated: 2026/01/16 08:23:10 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ps_sort_three(t_stack_node **a, t_bool display)
{
	int	first;
	int	second;
	int	third;

	if (!a || !*a || ps_stack_size(*a) > 3)
		return (false);
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
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
	return (display);
}