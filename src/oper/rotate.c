/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:52:45 by abait-el          #+#    #+#             */
/*   Updated: 2026/02/05 05:23:02 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	ps_stack_rotate(t_stack_node **head)
{
	t_stack_node *top;
	t_stack_node *tail;

	if (!head || !*head || !(*head)->next)
		return (false);
	top = *head;
	tail = ps_stack_find_last(*head);
	*head = top->next;
	(*head)->prev = NULL;
	top->next = NULL;
	top->prev = tail;
	tail->next = top;
	return (true);
}

t_bool	ps_ra(t_stack_node **a, t_bool print)
{
	if (print)
		ps_puts("ra");
	return (ps_stack_rotate(a));
}

t_bool	ps_rb(t_stack_node **b, t_bool print)
{
	if (print)
		ps_puts("rb");
	return (ps_stack_rotate(b));
}

t_bool	ps_rr(t_stack_node **a, t_stack_node **b, t_bool print)
{
	if (print)
		ps_puts("rr");
	return ps_ra(a, false) && (ps_rb(b, false));
}
