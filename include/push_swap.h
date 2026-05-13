/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                */
/*   Created: 2025/12/12 05:22:35 by abait-el          */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file push_swap.h
 * @brief Header file for the push_swap sorting algorithm project.
 * 
 * This project implements an efficient sorting algorithm using two stacks
 * with a limited set of operations. The algorithm uses the "Mechanical Turk"
 * approach with cost calculation to minimize the number of operations.
 * 
 * @author Abdelouadoud Ait El Haj
 * @version 1.0.0
 */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

/**
 * @brief Boolean type for true/false values.
 */
typedef enum e_bool
{
	false = 0,
	true = 1
}						t_bool;

/**
 * @brief Structure representing a node in the stack.
 * 
 * The stack is implemented as a doubly linked list, allowing O(1)
 * operations for push, pop, swap, and rotate.
 */
typedef struct s_stack_node	t_stack_node;

/**
 * @brief Node structure for the doubly linked list stack.
 */
struct						s_stack_node
{
	int						value;          /**< The integer value stored */
	size_t					index;          /**< Current position index (0-based) */
	size_t					cost;           /**< Rotation cost to bring to top */
	t_bool					above_median;  /**< true if node is in top half of stack */
	t_stack_node			*prev;          /**< Pointer to previous node */
	t_stack_node			*next;          /**< Pointer to next node */
	t_stack_node			*target;        /**< Target position in other stack */
};

/* ************************************************************************** */
/*                               Stack Utilities                              */
/* ************************************************************************** */

/**
 * @brief Creates a new stack node with the given parameters.
 * @param val   Integer value to store
 * @param index Position index in the stack
 * @param prev  Pointer to previous node
 * @param next  Pointer to next node
 * @return New node, or NULL on allocation failure
 */
t_stack_node				*ps_stack_new(int val, int index,
								t_stack_node *prev, t_stack_node *next);

/**
 * @brief Adds a new node to the end of the stack.
 * @param stack Pointer to the stack
 * @param new   New node to add
 */
void						ps_stack_pushback(t_stack_node **stack,
								t_stack_node *new);

/**
 * @brief Frees all nodes in the stack.
 * @param stack_head Pointer to the stack to clean
 */
void						ps_stack_clean(t_stack_node **stack_head);

/**
 * @brief Returns the number of nodes in the stack.
 * @param stack Pointer to the stack
 * @return Number of nodes, or -1 if NULL
 */
ssize_t						ps_stack_size(t_stack_node *stack);

/**
 * @brief Finds a node with a specific value.
 * @param stack Stack to search
 * @param n     Value to find
 * @return Node with the value, or NULL if not found
 */
t_stack_node				*ps_stack_find(t_stack_node *stack, int n);

/**
 * @brief Finds the node with the smallest value.
 * @param stack Stack to search
 * @return Node with smallest value, or NULL if empty
 */
t_stack_node				*ps_stack_find_smallest(t_stack_node *stack);

/**
 * @brief Finds the last node in the stack.
 * @param stack Stack to search
 * @return Last node, or NULL if empty
 */
t_stack_node				*ps_stack_find_last(t_stack_node *stack);

/**
 * @brief Checks if the stack is sorted in ascending order.
 * @param stack Stack to check
 * @return true if sorted (or empty), false otherwise
 */
t_bool						ps_stack_is_sorted(t_stack_node *stack);

/**
 * @brief Finds the node with the minimum value.
 * @param stack Stack to search
 * @return Node with minimum value, or NULL if empty
 */
t_stack_node				*ps_stack_min(t_stack_node *stack);

/**
 * @brief Finds the node with the maximum value.
 * @param stack Stack to search
 * @return Node with maximum value, or NULL if empty
 */
t_stack_node				*ps_stack_max(t_stack_node *stack);

/**
 * @brief Finds a node by its index.
 * @param stack Stack to search
 * @param index Index to find
 * @return Node at that index, or NULL if not found
 */
t_stack_node				*ps_stack_find_index(t_stack_node *stack,
								int index);

/**
 * @brief Applies a function to each node in the stack.
 * @param stack Stack to iterate
 * @param f     Function to apply to each node
 */
void						ps_stack_iter(t_stack_node *stack,
								void (*f)(t_stack_node **));

/* ************************************************************************** */
/*                               Operations                                   */
/* ************************************************************************** */

/**
 * @brief Swaps the top two elements of stack A (sa).
 * @param a     Pointer to stack A
 * @param print Whether to print the operation
 * @return true if successful
 */
t_bool						ps_sa(t_stack_node **a, t_bool should_print);

/**
 * @brief Swaps the top two elements of stack B (sb).
 * @param b     Pointer to stack B
 * @param print Whether to print the operation
 * @return true if successful
 */
t_bool						ps_sb(t_stack_node **b, t_bool should_print);

/**
 * @brief Swaps the top two elements of both stacks A and B (ss).
 * @param a     Pointer to stack A
 * @param b     Pointer to stack B
 * @param print Whether to print the operation
 * @return true if both swaps successful
 */
t_bool						ps_ss(t_stack_node **a,
								t_stack_node **b, t_bool should_print);

/**
 * @brief Pushes top element from stack B to stack A (pa).
 * @param a     Pointer to stack A (destination)
 * @param b     Pointer to stack B (source)
 * @param print Whether to print the operation
 * @return true if successful
 */
t_bool						ps_pa(t_stack_node **a,
								t_stack_node **b, t_bool should_print);

/**
 * @brief Pushes top element from stack A to stack B (pb).
 * @param b     Pointer to stack B (destination)
 * @param a     Pointer to stack A (source)
 * @param print Whether to print the operation
 * @return true if successful
 */
t_bool						ps_pb(t_stack_node **b,
								t_stack_node **a, t_bool should_print);

/**
 * @brief Rotates stack A (ra) - shifts up, top becomes bottom.
 * @param a     Pointer to stack A
 * @param print Whether to print the operation
 * @return true if successful
 */
t_bool						ps_ra(t_stack_node **a, t_bool should_print);

/**
 * @brief Rotates stack B (rb) - shifts up, top becomes bottom.
 * @param b     Pointer to stack B
 * @param print Whether to print the operation
 * @return true if successful
 */
t_bool						ps_rb(t_stack_node **b, t_bool should_print);

/**
 * @brief Rotates both stacks A and B (rr).
 * @param a     Pointer to stack A
 * @param b     Pointer to stack B
 * @param print Whether to print the operation
 * @return true if successful
 */
t_bool						ps_rr(t_stack_node **a,
								t_stack_node **b, t_bool should_print);

/**
 * @brief Reverse rotates stack A (rra) - shifts down, bottom becomes top.
 * @param a     Pointer to stack A
 * @param print Whether to print the operation
 * @return true if successful
 */
t_bool						ps_rra(t_stack_node **a, t_bool should_print);

/**
 * @brief Reverse rotates stack B (rrb) - shifts down, bottom becomes top.
 * @param b     Pointer to stack B
 * @param print Whether to print the operation
 * @return true if successful
 */
t_bool						ps_rrb(t_stack_node **b, t_bool should_print);

/**
 * @brief Reverse rotates both stacks A and B (rrr).
 * @param a     Pointer to stack A
 * @param b     Pointer to stack B
 * @param print Whether to print the operation
 * @return true if successful
 */
t_bool						ps_rrr(t_stack_node **a,
								t_stack_node **b, t_bool should_print);

/* ************************************************************************** */
/*                               Parsing Utilities                            */
/* ************************************************************************** */

/**
 * @brief Splits a string into tokens using a separator function.
 * @param s        String to split
 * @param is_sep   Function that returns true for separator characters
 * @return Array of tokens (NULL-terminated), or NULL on failure
 */
char						**ps_split_fn(char const *s, int (*is_sep)(char));

/**
 * @brief Safely converts a string to an integer with overflow checking.
 * @param str String to convert
 * @param out Pointer to store the result
 * @return true if conversion successful, false on error or overflow
 */
t_bool						ps_atoi(const char *str, int *out);

/* ************************************************************************** */
/*                               Misc Utilities                               */
/* ************************************************************************** */

/**
 * @brief Writes a string to stdout followed by a newline.
 * @param s String to write
 * @return Bytes written, or -1 on error
 */
ssize_t						ps_puts(char *s);

/**
 * @brief Finds first occurrence of a character in a string.
 * @param s String to search
 * @param c Character to find
 * @return Pointer to the character, or NULL if not found
 */
char						*ps_strchr(char *s, char c);

/**
 * @brief Frees a NULL-terminated array of pointers.
 * @param p Array to free
 */
void						ps_freematrix(void **p);

/**
 * @brief Returns the maximum of two integers.
 * @param a First integer
 * @param b Second integer
 * @return The larger value
 */
int							max(int a, int b);

/* ************************************************************************** */
/*                                  Algorithm                                 */
/* ************************************************************************** */

/**
 * @brief Finds the target position in stack A for a node from stack B.
 * @param head Target stack (A)
 * @param node Node to find target for (from B)
 * @return The target node in stack A
 */
t_stack_node				*ps_stack_find_target(t_stack_node *head,
								t_stack_node *node);

/**
 * @brief Initializes a stack from command-line arguments.
 * @param stack Pointer to stack to initialize
 * @param vals  Command-line arguments
 * @return true if initialization successful
 */
t_bool						ps_stack_init(t_stack_node **stack, char **vals);

/**
 * @brief Sets the index for all nodes in a stack.
 * @param node Pointer to the stack
 * @return true if successful
 */
t_bool						ps_stack_setindex(t_stack_node **node);

/**
 * @brief Sets the cost for all nodes in a stack.
 * @param node Pointer to the stack
 * @return true if successful
 */
t_bool						ps_stack_setcost(t_stack_node **node);

/**
 * @brief Sorts a stack of 3 or fewer elements.
 * @param a       Pointer to stack A
 * @param display Whether to print operations
 * @return true if successful
 */
t_bool						ps_sort_three(t_stack_node **a, t_bool display);

/**
 * @brief Main sorting function.
 * @param a       Pointer to stack A
 * @param display Whether to print operations
 * @return true if sorting successful
 */
t_bool						ps_sort(t_stack_node **a, t_bool display);

/**
 * @brief Sets the above_median flag for all nodes.
 * @param a Pointer to the stack
 * @return true if successful
 */
t_bool						ps_setup_above_median(t_stack_node **a);

/**
 * @brief Refreshes statistics for both stacks.
 * @param a Pointer to stack A
 * @param b Pointer to stack B
 */
void						ps_refresh_stats(t_stack_node *a, t_stack_node *b);

/**
 * @brief Moves the cheapest node from stack B to stack A.
 * @param a Pointer to stack A
 * @param b Pointer to stack B
 */
void						ps_move_cheapest(t_stack_node **a,
								t_stack_node **b);

/**
 * @brief Performs final rotation to position smallest at top.
 * @param a       Pointer to stack A
 * @param display Whether to print operations
 */
void						ps_final_rotate(t_stack_node **a, t_bool display);

#endif /* !PUSH_SWAP_H */
