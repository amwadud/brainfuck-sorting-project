/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>       +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 05:22:35 by abait-el          #+#    #+#             */
/*   Updated: 2026/02/06 05:24:24 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef enum e_bool
{
	false = 0,
	true = 1
}							t_bool;

typedef struct s_stack_node	t_stack_node;
struct						s_stack_node
{
	int						value;
	size_t					index;
	size_t					cost;
	t_bool					above_median;
	t_stack_node			*prev;
	t_stack_node			*next;
	t_stack_node			*target;
};

/* ************************************************************************** */
/*                               Stack Utilities                              */
/* ************************************************************************** */

t_stack_node				*ps_stack_new(int val, int index,
								t_stack_node *prev, t_stack_node *next);
void						ps_stack_pushback(t_stack_node **stack,
								t_stack_node *new);
void						ps_stack_clean(t_stack_node **stack_head);
ssize_t						ps_stack_size(t_stack_node *stack);
t_stack_node				*ps_stack_find(t_stack_node *stack, int n);
t_stack_node				*ps_stack_find_smallest(t_stack_node *stack);
t_stack_node				*ps_stack_find_last(t_stack_node *stack);
t_bool						ps_stack_is_sorted(t_stack_node *stack);
t_stack_node				*ps_stack_min(t_stack_node *stack);
t_stack_node				*ps_stack_max(t_stack_node *stack);
t_stack_node				*ps_stack_max(t_stack_node *stack);
t_stack_node				*ps_stack_find_index(t_stack_node *stack,
								int index);
void						ps_stack_iter(t_stack_node *stack,
								void (*f)(t_stack_node **));

/* ************************************************************************** */
/*                               Operations                                   */
/* ************************************************************************** */

/* Stack-specific wrappers */
t_bool						ps_sa(t_stack_node **stack_a, t_bool should_print);
t_bool						ps_sb(t_stack_node **stack_b, t_bool should_print);
t_bool						ps_ss(t_stack_node **stack_a,
								t_stack_node **stack_b, t_bool should_print);

t_bool						ps_pa(t_stack_node **stack_a,
								t_stack_node **stack_b, t_bool should_print);
t_bool						ps_pb(t_stack_node **stack_b,
								t_stack_node **stack_a, t_bool should_print);

t_bool						ps_ra(t_stack_node **stack_a, t_bool should_print);
t_bool						ps_rb(t_stack_node **stack_b, t_bool should_print);
t_bool						ps_rr(t_stack_node **stack_a,
								t_stack_node **stack_b, t_bool should_print);

t_bool						ps_rra(t_stack_node **stack_a, t_bool should_print);
t_bool						ps_rrb(t_stack_node **stack_b, t_bool should_print);
t_bool						ps_rrr(t_stack_node **stack_a,
								t_stack_node **stack_b, t_bool should_print);

/* ************************************************************************** */
/*                               Parsing Utilities                            */
/* ************************************************************************** */

char						**ps_split_fn(char const *s, int (*is_sep)(char));
t_bool						ps_atoi(const char *str, int *out);

/* ************************************************************************** */
/*                               Misc Utilities                               */
/* ************************************************************************** */

ssize_t						ps_puts(char *s);
char						*ps_strchr(char *s, char c);
void						ps_freematrix(void **p);
int							max(int a, int b);

/* ************************************************************************** */
/*                                  Algorithm                                 */
/* ************************************************************************** */

t_stack_node				*ps_stack_find_target(t_stack_node *head,
								t_stack_node *node);
t_bool						ps_stack_init(t_stack_node **stack, char **vals);
t_bool						ps_stack_setindex(t_stack_node **node);
t_bool						ps_stack_setcost(t_stack_node **node);
t_bool						ps_sort_three(t_stack_node **a, t_bool display);
t_bool						ps_sort(t_stack_node **a, t_bool display);
t_bool						ps_setup_above_median(t_stack_node **a);
void						ps_refresh_stats(t_stack_node *a, t_stack_node *b);
void						ps_move_cheapest(t_stack_node **a,
								t_stack_node **b);
void						ps_final_rotate(t_stack_node **a, t_bool display);

#endif /* !PUSH_SWAP_H */
