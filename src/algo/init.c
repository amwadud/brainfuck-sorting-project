/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                */
/*   Created: 2026/01/01 20:11:33 by abait-el          */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init.c
 * @brief Stack initialization and input parsing.
 * 
 * Handles parsing command-line arguments and building the initial stack.
 * Supports both space-separated strings and multiple arguments.
 */

#include "push_swap.h"

/**
 * @brief Creates a new node with the given value and adds it to the stack.
 * 
 * Checks for duplicates before adding.
 * 
 * @param stack Pointer to the stack pointer
 * @param value The integer value to add
 * @return true if node was added successfully, false on error or duplicate
 */
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

/**
 * @brief Processes an array of string tokens and adds them to the stack.
 * 
 * Converts each token to an integer and adds to the stack.
 * Frees the token array before returning.
 * 
 * @param stack  Pointer to the stack pointer
 * @param tokens Array of string tokens to process
 * @return true if all tokens processed successfully
 */
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

/**
 * @brief Checks if a character is a whitespace character.
 * 
 * @param c Character to check
 * @return true if c is a whitespace character
 */
static int	ps_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

/**
 * @brief Checks if a string contains only whitespace characters.
 * 
 * @param s String to check
 * @return true if string is empty or contains only whitespace
 */
static t_bool	ps_is_strempty(char *s)
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

/**
 * @brief Initializes a stack from command-line arguments.
 * 
 * Parses the argument list which can be in two formats:
 * - Multiple arguments: ./push_swap 1 2 3
 * - Single string: ./push_swap "1 2 3"
 * 
 * Validates for:
 * - Non-integer inputs
 * - Integer overflow
 * - Duplicate values
 * 
 * @param stack Pointer to the stack pointer (will be initialized)
 * @param vals  Array of string arguments
 * @return true if initialization succeeded, false on error
 */
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
