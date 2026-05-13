# Push Swap

A highly efficient C program that sorts a stack of integers using two stacks (`a` and `b`) with a restricted set of instructions. Part of the 42 curriculum.

## Overview

**Push Swap** is designed to generate the shortest possible sequence of operations to transform an unordered stack into an ascendingly sorted one. The project implements a variation of the **"Mechanical Turk"** (or Turkish) algorithm, which uses cost-calculation to determine the most efficient movement for each element.

## Features

- **Optimized Sorting Algorithm**: Uses the Mechanical Turk approach with cost calculation
- **Efficient Data Structure**: Doubly linked lists provide O(1) operations for push, pop, and swap
- **Cost Optimization**: Calculates rotation costs to minimize total operations
- **Simultaneous Rotations**: Uses `rr` and `rrr` to reduce operation count when possible
- **Robust Input Handling**: Supports both multiple arguments and space-separated strings
- **Comprehensive Error Checking**: Validates for non-integers, overflow, and duplicates
- **Well-Documented Code**: Extensive comments explaining each function's purpose

## Project Structure

```
brainfuck-sorting-project/
├── include/
│   └── push_swap.h          # Main header with all function declarations
├── src/
│   ├── algo/
│   │   ├── init.c            # Stack initialization from arguments
│   │   ├── sort_three.c      # Optimized sorting for 3 elements
│   │   └── logic/
│   │       ├── push_swap.c   # Main sorting algorithm
│   │       ├── refresh_stats.c   # Cost/target calculation
│   │       ├── move_cheapest.c   # Execute cheapest move
│   │       ├── best_target.c     # Find optimal target position
│   │       └── ps_final_rotate.c # Final rotation to position smallest
│   ├── misc/
│   │   ├── puts.c            # String output
│   │   ├── string.c          # String utilities
│   │   ├── max.c             # Max function
│   │   └── freematrix.c      # Memory cleanup
│   ├── oper/
│   │   ├── swap.c            # sa, sb, ss operations
│   │   ├── push.c            # pa, pb operations
│   │   ├── rotate.c          # ra, rb, rr operations
│   │   └── reverse_rotate.c  # rra, rrb, rrr operations
│   ├── pars/
│   │   ├── atoi.c            # Safe string-to-int conversion
│   │   └── split_fn.c        # String splitting
│   ├── stack/
│   │   ├── misc.c            # Stack creation and cleanup
│   │   └── queries.c         # Stack queries (find, min, max, etc.)
│   └── main.c                # Program entry point
├── bonus/
│   ├── checker_bonus.c       # Input validator/checker
│   ├── get_next_line.c       # Line reading utility
│   └── ...
├── Makefile                  # Build configuration
└── README.md                 # This file
```

## Building

### Prerequisites

- GCC or compatible C compiler
- Make

### Compilation

```bash
make        # Build push_swap
make bonus  # Build the checker program
make clean  # Remove object files
make fclean # Remove all generated files
make re     # Rebuild from scratch
```

## Usage

### Running Push Swap

The program accepts integers as input in two formats:

```bash
# Multiple arguments
./push_swap 3 4 1 2 5

# Single quoted string
./push_swap "3 4 1 2 5"
```

### Output

The program outputs a sequence of stack operations, one per line:

```
sa
pb
ra
...
```

### Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap top two elements of stack A |
| `sb` | Swap top two elements of stack B |
| `ss` | Swap top two elements of both stacks |
| `pa` | Push top element from B to A |
| `pb` | Push top element from A to B |
| `ra` | Rotate stack A (top becomes bottom) |
| `rb` | Rotate stack B (top becomes bottom) |
| `rr` | Rotate both stacks |
| `rra` | Reverse rotate stack A (bottom becomes top) |
| `rrb` | Reverse rotate stack B (bottom becomes top) |
| `rrr` | Reverse rotate both stacks |

### Validation with Checker

The bonus `checker` program reads operations from stdin and validates that they correctly sort the stack:

```bash
./push_swap 3 1 2 | ./checker 3 1 2
```

## Algorithm

### Mechanical Turk Approach

1. **Small Stacks (≤3 elements)**: Uses specialized sort_three logic with at most 2 operations
2. **Push to Stack B**: Elements are pushed from A to B until only 3 remain in A
3. **Cost Calculation**: For each element in B, calculates:
   - Rotation cost to bring it to top of B
   - Rotation cost to bring its target to top of A
4. **Move Cheapest**: Moves the element with lowest total cost
5. **Repeat**: Continues until B is empty
6. **Final Rotation**: Rotates A so smallest element is at top

### Optimization Techniques

- **Average-Based Pre-Sort**: When pushing to B, uses average to keep smaller elements at bottom
- **Simultaneous Rotations**: Uses `rr`/`rrr` when both nodes are on same side of median
- **Smart Cost Calculation**: Uses `max()` for same-side costs to enable simultaneous rotations

## Data Structure

The stack is implemented as a doubly linked list with the following node structure:

```c
typedef struct s_stack_node {
    int             value;      // Stored integer
    size_t          index;      // Current position
    size_t          cost;       // Rotation cost to top
    t_bool          above_median;  // Top half flag
    t_stack_node    *prev;      // Previous node
    t_stack_node    *next;      // Next node
    t_stack_node    *target;    // Target in other stack
} t_stack_node;
```

## Error Handling

The program handles and reports errors for:
- Non-integer inputs
- Integer overflow (both positive and negative)
- Duplicate values
- Empty arguments

On error, it outputs `Error\n` to stderr and exits.

## Technical Details

- **Language**: C99
- **Compilation Flags**: `-Wall -Wextra -Werror`
- **Norm**: Compliant with 42 Norm
- **Dependencies**: Standard C library only (no external libraries)

## License

MIT License - See LICENSE file for details.

## Author

Abdelouadoud Ait El Haj (abait-el)
