/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:52:14 by abait-el          #+#    #+#             */
/*   Updated: 2026/01/29 06:00:10 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	ps_stack_swap(t_stack_node **head)
{
	if (!head || !*head || !(*head)->next)
		return (false);

	t_stack_node *fst = *head;
	t_stack_node *sec = fst->next;
	fst->next = sec->next;
	if (sec->next)
		sec->next->prev = fst;
	sec->prev = NULL;
	sec->next = fst;
	fst->prev = sec;
	*head = sec;
	return (true);
}

t_bool	ps_sa(t_stack_node **a, t_bool print)
{
	if (print)
		ps_puts("sa");
	return (ps_stack_swap(a));
}

t_bool	ps_sb(t_stack_node **b, t_bool print)
{
	if (print)
		ps_puts("sb");
	return (ps_stack_swap(b));
}

t_bool	ps_ss(t_stack_node **a, t_stack_node **b, t_bool print)
{
	if (print)
		ps_puts("ss");
	return (ps_sa(a, false) && ps_sb(b, false));
}
