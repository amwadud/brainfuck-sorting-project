/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 11:45:00 by abait-el          #+#    #+#             */
/*   Updated: 2026/01/30 10:25:10 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

#if PRINT_VALS == 1
static void ps_print_node_value(t_stack_node **node)
{
	if (node && *node)
		printf("%d\n", (*node)->value);
}
#endif /* if PRINT_VALS */

int	main(int argc, char *argv[])
{
	t_stack_node *a;

	if (argc > 1)
	{
		a = NULL;
		if (!(ps_stack_init(&a, argv + 1)))
		{
			write(STDERR_FILENO, "Error\n", 6);
			return (-1);
		}
		if (!ps_sort(&a, true))
		{
			write(STDERR_FILENO, "Error\n", 6);
			return (-1);
		}
#if PRINT_VALS == 1
 		ps_stack_iter(a, ps_print_node_value);
#endif /* if PRINT_VALS */
		ps_stack_clean(&a);
	}
}
