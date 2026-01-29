/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:52:55 by abait-el          #+#    #+#             */
/*   Updated: 2026/01/29 18:04:41 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	ps_stack_push(t_stack_node **from, t_stack_node **to)
{
	t_stack_node *node;

	if (!from || !*from || !to)
		return (false);
	node = *from;
	*from = node->next;
	if (*from)
		(*from)->prev = NULL;
	node->next = *to;
	if (*to)
		(*to)->prev = node;
	node->prev = NULL;
	*to = node;
	return (true);
}

t_bool	ps_pa(t_stack_node **a, t_stack_node **b, t_bool print)
{
	if (print)
		ps_puts("pa");
	return (ps_stack_push(b, a));
}

t_bool	ps_pb(t_stack_node **b, t_stack_node **a, t_bool print)
{
	if (print)
		ps_puts("pb");
	return (ps_stack_push(a, b));
}
