/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 20:11:33 by abait-el          #+#    #+#             */
/*   Updated: 2026/01/08 06:01:39 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	push_token(t_stack_node **stack, int value)
{
	t_stack_node	*node;

	if (ps_stack_find(*stack, value))
		return (false);
	node = ps_stack_new(value, 0, NULL, NULL);
	if (!node)
	{
		ps_stack_clean(stack);
		return (false);
	}
	ps_stack_pushback(stack, node);
	return (true);
}

static t_bool	process_tokens(t_stack_node **stack, char **tokens)
{
	int	j;
	int	value;

	j = 0;
	while (tokens[j])
	{
		if (!ps_atoi(tokens[j], &value) || !push_token(stack, value))
		{
			ps_freematrix((void **)tokens);
			return (false);
		}
		j++;
	}
	ps_freematrix((void **)tokens);
	return (true);
}

static int	ps_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static	t_bool	ps_is_strempty(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ps_is_space(s[i]))
			return (false);
		i++;
	}
	return (true);
}

t_bool	ps_stack_init(t_stack_node **stack, char **vals)
{
	int		i;
	int		value;
	char	**tokens;

	i = 0;
	while (vals[i])
	{
		if (ps_is_strempty(vals[i]))
			return (ps_stack_clean(stack), false);
		if (ps_strchr(vals[i], ' '))
		{
			tokens = ps_split_fn(vals[i], ps_is_space);
			if (!tokens || !process_tokens(stack, tokens))
				return (ps_stack_clean(stack), false);
		}
		else
		{
			if (!ps_atoi(vals[i], &value) || !push_token(stack, value))
				return (ps_stack_clean(stack), false);
		}
		i++;
	}
	return (true);
}
