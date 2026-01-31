/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:53:37 by abait-el          #+#    #+#             */
/*   Updated: 2026/01/31 02:17:42 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	ps_stack_reverse_rotate(t_stack_node **head)
{
	t_stack_node	*tail;

	if (!head || !*head || !(*head)->next)
		return (false);
	
	tail = ps_stack_find_last(*head);
	
	// Disconnect tail from the list
	tail->prev->next = NULL; 
	
	// Attach old head after the tail
	tail->next = *head;
	tail->prev = NULL;
	
	// Set the old head's prev to the new head
	(*head)->prev = tail;
	
	// Update the head pointer
	*head = tail;
	return (true);
}

t_bool	ps_rra(t_stack_node **a, t_bool print)
{
	if (print)
		ps_puts("rra");
	return (ps_stack_reverse_rotate(a));
}

t_bool	ps_rrb(t_stack_node **b, t_bool print)
{
	if (print)
		ps_puts("rrb");
	return (ps_stack_reverse_rotate(b));
}

t_bool	ps_rrr(t_stack_node **a, t_stack_node **b, t_bool print)
{
	if (print)
		ps_puts("rrr");
	return (ps_rra(a, false) && ps_rrb(b, false));
}
