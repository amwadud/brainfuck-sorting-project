/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_final_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 05:29:53 by abait-el          #+#    #+#             */
/*   Updated: 2026/01/29 05:29:53 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_final_rotate(t_stack_node **a, t_bool display)
{
	t_stack_node	*min_node;
	size_t			size;
	size_t			min_index;

	if (!a || !*a)
		return ;
	min_node = ps_stack_find_smallest(*a);
	size = ps_stack_size(*a);
	min_index = min_node->index;
	if (min_index <= size / 2)
	{
		while (*a != min_node)
			ps_ra(a, display);
	}
	else
	{
		while (*a != min_node)
			ps_rra(a, display);
	}
}
