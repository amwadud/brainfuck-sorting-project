/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:49:50 by abait-el          #+#    #+#             */
/*   Updated: 2026/01/30 10:49:50 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ps_sort_three(t_stack_node **a, t_bool display)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*a)->value;
	middle = (*a)->next->value;
	bottom = (*a)->next->next->value;
	if (top > middle && middle < bottom && top < bottom)
		ps_sa(a, display);
	else if (top > middle && middle > bottom)
	{
		ps_sa(a, display);
		ps_rra(a, display);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ps_ra(a, display);
	else if (top < middle && middle > bottom && top < bottom)
	{
		ps_sa(a, display);
		ps_ra(a, display);
	}
	else if (top < middle && middle > bottom && top > bottom)
		ps_rra(a, display);
	return (true);
}
