/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      ::::::::   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#++:+#++#+#++#++#++#+#*/
/*   Created: 2025/12/13 11:45:00 by abait-el          #+#    #+#             */
/*   Updated: 2026/03/17 00:00:00 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Entry point for the push_swap sorting program.
 * 
 * This program sorts a stack of integers using two stacks (a and b) with
 * a limited set of operations. It implements the "Mechanical Turk" algorithm
 * which calculates costs to determine the most efficient moves.
 * 
 * @author Abdelouadoud Ait El Haj
 * @version 1.0.0
 */

#include "push_swap.h"
#include <stdlib.h>

/**
 * @brief Prints error message and exits the program.
 * 
 * This function is called when an error occurs during initialization
 * or sorting (e.g., invalid input, duplicate numbers, overflow).
 */
static void	ps_error_and_exit(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(-1);
}

/**
 * @brief Main entry point for push_swap.
 * 
 * Expected arguments: a list of integers to sort.
 * Supported formats:
 *   - ./push_swap 3 1 5 2 (multiple arguments)
 *   - ./push_swap "3 1 5 2" (single quoted string)
 * 
 * @param argc Number of command-line arguments (including program name)
 * @param argv Array of command-line arguments
 * @return 0 on successful execution (program handles its own output)
 */
int	main(int argc, char *argv[])
{
	t_stack_node	*a;

	if (argc > 1)
	{
		a = NULL;
		/* Initialize stack from command-line arguments */
		if (!(ps_stack_init(&a, argv + 1)))
			ps_error_and_exit();
		/* Sort the stack and output operations */
		if (!ps_sort(&a, true))
			ps_error_and_exit();
		/* Clean up allocated memory */
		ps_stack_clean(&a);
	}
	return (0);
}
