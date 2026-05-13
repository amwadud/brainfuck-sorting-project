/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 01:18:22 by abait-el          #+#    #+#             */
/*   Updated: 2026/02/09 06:16:07 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"
#include <stdlib.h>

static int	ps_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (1);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ps_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	execute_instruction(t_stack_node **a, t_stack_node **b, char *line)
{
	if (!ps_strcmp(line, "sa\n"))
		ps_sa(a, false);
	else if (!ps_strcmp(line, "sb\n"))
		ps_sb(b, false);
	else if (!ps_strcmp(line, "ss\n"))
		ps_ss(a, b, false);
	else if (!ps_strcmp(line, "pa\n"))
		ps_pa(a, b, false);
	else if (!ps_strcmp(line, "pb\n"))
		ps_pb(b, a, false);
	else if (!ps_strcmp(line, "ra\n"))
		ps_ra(a, false);
	else if (!ps_strcmp(line, "rb\n"))
		ps_rb(b, false);
	else if (!ps_strcmp(line, "rr\n"))
		ps_rr(a, b, false);
	else if (!ps_strcmp(line, "rra\n"))
		ps_rra(a, false);
	else if (!ps_strcmp(line, "rrb\n"))
		ps_rrb(b, false);
	else if (!ps_strcmp(line, "rrr\n"))
		ps_rrr(a, b, false);
	else
		ps_error_and_exit();
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*line;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	if (!ps_stack_init(&a, argv + 1))
		ps_error_and_exit();
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		execute_instruction(&a, &b, line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (ps_stack_is_sorted(a) && ps_stack_size(b) == -1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ps_stack_clean(&a);
	ps_stack_clean(&b);
	return (0);
}
