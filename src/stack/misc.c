/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:57:11 by abait-el          #+#    #+#             */
/*   Updated: 2026/02/06 05:09:25 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

void	ps_stack_pushback(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node	*last;

	if (!stack || !new)
		return ;
	new->next = NULL;
	if (!*stack)
	{
		*stack = new;
		new->prev = NULL;
		return ;
	}
	last = ps_stack_find_last(*stack);
	last->next = new;
	new->prev = last;
}

void	ps_stack_clean(t_stack_node **stack_head)
{
	t_stack_node	*tmp;

	if (!stack_head)
		return ;
	while (*stack_head)
	{
		tmp = *stack_head;
		*stack_head = (*stack_head)->next;
		free(tmp);
	}
	*stack_head = NULL;
}

t_stack_node	*ps_stack_new(int val, int index, t_stack_node *prev,
		t_stack_node *next)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->value = val;
	node->index = index;
	node->prev = prev;
	node->next = next;
	return (node);
}

void	ps_stack_iter(t_stack_node *stack, void (*f)(t_stack_node **))
{
	t_stack_node	*current;

	current = stack;
	while (current)
	{
		f(&current);
		current = current->next;
	}
}
