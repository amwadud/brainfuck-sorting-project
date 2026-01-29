# Brainfuck Sorting Project (push_swap — 42 School)

Small, fast, and correct: this repository contains my implementation of the push_swap project from 42 School. The goal is to sort a stack of integers using a minimal sequence of permitted operations while following the project rules and constraints.

> NOTE: This README is written for the repository named `brainfuck-sorting-project` (push_swap 42 project). Replace author/contact/license fields as needed.

---

## Table of contents

- [Subject / Goal](#subject--goal)
- [Rules & Constraints](#rules--constraints)
- [Project structure](#project-structure)
- [Dependencies / Requirements](#dependencies--requirements)
- [Build](#build)
- [Usage](#usage)
- [Examples](#examples)
- [Algorithm & Approach](#algorithm--approach)
- [Complexity & Scoring](#complexity--scoring)
- [Testing & Validation](#testing--validation)
- [Tips & Notes](#tips--notes)
- [Contributing](#contributing)
- [Authors](#authors)
- [License](#license)

---

## Subject / Goal

Implement two programs:

- `push_swap`: Given a sequence of integers, print a list of operations that sorts the stack in ascending order using only the allowed operations.
- `checker` (optional/bonus): Read the operations produced and validate whether they correctly sort the input.

The primary objective is to minimize the number of operations produced by `push_swap` while respecting memory and performance constraints set by the 42 subject.

---

## Rules & Constraints

- Input: a list of integers (via program arguments).
- Only the following operations are allowed:
  - sa, sb, ss — swap the first 2 elements of stack A, stack B, or both.
  - pa, pb — push the top element from one stack to the other.
  - ra, rb, rr — rotate stack A, stack B, or both (first element becomes last).
  - rra, rrb, rrr — reverse rotate stack A, stack B, or both (last element becomes first).
- The program must detect and handle:
  - Duplicate integers (should be considered an error).
  - Non-integer / out-of-range arguments (error).
  - Already sorted inputs (output nothing for push_swap).
- Memory and performance: follow 42 subject constraints (avoid leaks, sensible complexity).
- Allowed functions: only C standard library functions permitted by the subject (no dynamic linking of permitted external libs). See the official subject for exact allowed functions.

---

## Project structure

A suggested layout (adjust to your repo):

- srcs/
  - push_swap.c
  - parser.c
  - operations.c
  - stack_utils.c
  - sort_small.c
  - sort_general.c
- include/
  - push_swap.h
- tests/
  - testcases.sh
  - random_tests.sh
- bonus/
  - checker.c
- Makefile
- README.md
- LICENSE

---

## Dependencies / Requirements

- C compiler (tested with gcc)
- Make
- Standard 42 tooling expectations (norminette not enforced here)
- POSIX environment for Make scripts/tests

---

## Build

Run:

```bash
make
```

This produces:

- `push_swap` — the main program
- `checker` — bonus program (if implemented)

Clean:

```bash
make fclean
```

Rebuild:

```bash
make re
```

(Modify Makefile targets to match your preferred commands.)

---

## Usage

Basic usage:

```bash
./push_swap 3 2 1 5 4
# Output: sequence of operations (one per line) that, when applied, sorts the numbers
```

To test with `checker` (bonus):

```bash
./push_swap 3 2 1 5 4 | ./checker 3 2 1 5 4
# checker should respond with "OK" if the operations sort the input, "KO" otherwise
```

You can feed input from a file or script for testing large cases.

---

## Examples

Already sorted input (no output):

```bash
./push_swap 1 2 3 4 5
# (no output)
```

Small example:

```bash
./push_swap 2 1 3
# Output:
# sa
```

Larger example (sample output):

```bash
./push_swap 5 2 3 1 4
# pb
# sa
# ra
# pa
# ra
# ...
```

(Exact operations depend on your algorithm.)

---

## Algorithm & Approach

This project commonly uses a combination of techniques:

- Trivial sorts for small N:
  - N = 2: single swap if needed.
  - N = 3: few hardcoded sequences to sort in <= 3 moves.
  - N = 5 (or <= 5): push smallest elements to B, sort A, push back.
- General strategy for larger N:
  - Index compression (map values to 0..N-1 by rank).
  - Radix sort on bit positions using pb/pa for O(N log N) moves.
  - Or divide-and-conquer: partition into chunks, push chunks to B in order, then push back.
  - Greedy insertion: compute optimal rotations to move the next element.
- Heuristics to reduce moves:
  - Combine rotations (rr / rrr) whenever both stacks need rotation.
  - Calculate minimal sequence of rotations to place items.
  - Use rotation direction that minimizes total moves.

Document your chosen algorithm in source comments (why you chose it, complexity).

---

## Complexity & Scoring

- Aim to minimize the number of operations; different input sizes have recommended maximums in some schools/test suites.
- Typical complexities:
  - Radix: O(N log N) operations, good for N up to several hundreds.
  - Chunking + greedy moves: often yields fewer operations but more complex implementation.
- Use performance scripts to measure average/maximum operations over many random tests.

---

## Testing & Validation

Add tests in `tests/`:

- Unit test small helper functions.
- Integration tests:
  - Randomized inputs of size 3..500.
  - Validate `push_swap` output by applying operations to the input and verifying sorted output.
  - Confirm `checker` prints `OK` for correct sequences and `KO` otherwise.
- Example test command (simple):

```bash
# generate random list, run push_swap, apply moves, check sorted
python3 tests/run_random_test.py --size 100 --trials 100
```

(Provide helper scripts to apply operations to stacks for automatic checking.)

Memory leaks: test with valgrind (or equivalent):

```bash
valgrind --leak-check=full ./push_swap 3 2 1 4 5
```

---

## Tips & Notes

- Always handle edge cases: single number, duplicates, invalid input, extremely large or small integers (int overflow).
- Implement and test stack operations thoroughly; they are the building blocks of the solver.
- Keep the output format EXACTLY one operation per line, no trailing spaces, and only allowed operation names.
- Optimize for clarity early, then refactor for operation-count improvements.
- Use index compression to make comparisons simpler and avoid relying on numeric ranges.

---

## Contributing

If you'd like to contribute improvements, please:

- Fork the repo
- Create a feature branch: `git checkout -b feat/shorter-radix`
- Add tests demonstrating improvements
- Open a pull request with a detailed description of the change and its impact on operation count and complexity

---

## Authors

- amwadud
- 42 School — push_swap subject inspiration

---

## License

This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.
