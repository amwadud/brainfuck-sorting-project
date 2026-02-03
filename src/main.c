/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 11:45:00 by abait-el          #+#    #+#             */
/*   Updated: 2026/02/03 02:03:58 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

#if PRINT_VALS == 1
static void ps_print_node_value(t_stack_node **node)
{
	if (node && *node)
		printf("%d\n", (*node)->value);
}
#endif /* if PRINT_VALS */

static void ps_error_and_exit()
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(-1);
}

int	main(int argc, char *argv[])
{
	t_stack_node	*a;

	if (argc > 1)
	{
		a = NULL;
		if (!(ps_stack_init(&a, argv + 1)))
			ps_error_and_exit();
		if (!ps_sort(&a, true))
			ps_error_and_exit();
#if PRINT_VALS == 1
 		ps_stack_iter(a, ps_print_node_value);
#endif /* if PRINT_VALS */
		ps_stack_clean(&a);
	}
}
