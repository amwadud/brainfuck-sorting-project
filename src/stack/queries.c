/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queries.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:55:45 by abait-el          #+#    #+#             */
/*   Updated: 2026/01/27 20:08:04 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *ps_stack_find(t_stack_node *stack, int n)
{
	while (stack)
	{
		if (stack->value == n)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack_node	*ps_stack_find_smallest(t_stack_node *stack)
{
	t_stack_node	*smallest;

	if (!stack)
		return (NULL);
	smallest = stack;
	while (stack)
	{
		if (stack->value < smallest->value)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

t_stack_node	*ps_stack_find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_bool	ps_stack_is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

ssize_t	ps_stack_size(t_stack_node *stack)
{
	ssize_t	size;

	if (!stack)
		return (-1);
	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
