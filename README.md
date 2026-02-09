*This project has been created as part of the 42 curriculum by abait-el.*

## Description
**Push_swap** is a highly efficient C program designed to sort a stack of integers using two stacks (`a` and `b`) and a restricted set of instructions. The goal is to generate the shortest possible sequence of operations to transform an unordered stack into an ascendingly sorted one.

The project focuses on algorithmic complexity and optimization. It implements a variation of the **"Mechanical Turk"** (or Turkish) algorithm, which utilizes cost-calculation to determine the most efficient movement for each element.

### Key Features:
- **Doubly Linked List:** Stacks are implemented as doubly linked lists to allow $O(1)$ operations for pushing and swapping.
- **Cost Optimization:** For larger sets, the program calculates the number of moves required for every element in stack `b` to reach its correct position in stack `a` and picks the "cheapest" one.
- **Robust Parsing:** Handles both multiple arguments (e.g., `./push_swap 1 2 3`) and quoted strings (e.g., `./push_swap "1 2 3"`).
- **Error Handling:** Validates for non-integer inputs, integer overflows, and duplicate values.

## Instructions

### Installation & Compilation
The project includes a `Makefile` that complies with the 42 Norm. To compile the program, run:

```bash
make
```
This will produce the `push_swap` executable.

### Execution
The program takes a list of integers as an argument. The first argument is at the top of the stack.

**Single argument format:**
```bash
./push_swap "3 4 1 2 5"
```

**Multiple arguments format:**
```bash
./push_swap 3 4 1 2 5
```

### Operations
The program outputs a sequence of instructions such as:
- `sa`, `sb`, `ss`: Swap the top two elements.
- `pa`, `pb`: Push from one stack to another.
- `ra`, `rb`, `rr`: Rotate the stack (shift up).
- `rra`, `rrb`, `rrr`: Reverse rotate the stack (shift down).

## Technical Choices
1. **The Algorithm:** 
   - If the stack size is $\le 3$, a specialized `ps_sort_three` logic is used.
   - For larger stacks, elements are pushed to stack `b` (using an average-based pre-sort to keep smaller numbers at the bottom of `b`).
   - A `target` node is assigned in stack `a` for every node in stack `b`.
   - The "cheapest" node is calculated by summing the rotation costs of the node in `b` and its target in `a`.
   - Simultaneous rotations (`rr`, `rrr`) are prioritized to minimize the total instruction count.
2. **Data Structure:** Each node (`t_stack_node`) stores its value, current index, cost, a boolean for median position, and a pointer to its target in the opposing stack.

## Resources
- **Algorithms:** Concepts of the "Mechanical Turk" sorting algorithm and general complexity theory ($O(n^2)$ vs $O(n \log n)$).
- **AI Usage:** 
    - AI was used as a brainstorming tool to design the initial parsing logic (specifically the `ps_split_fn` and `ps_atoi` overflow protection).
    - It assisted in reviewing the logic for simultaneous rotations (`ps_rotate_both_top` and `ps_reverse_rotate_both_bottom`) to ensure no redundant operations were performed.
    - All AI-generated suggestions were manually refactored to comply with the 42 Norm and verified through peer-testing to ensure full understanding of the implementation.
