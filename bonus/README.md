# c-line-reader-function | get-next-line project

Tiny, focused C function to read the next line from a file descriptor — simple, portable, and easy to drop into small projects.

Tagline: A single-purpose C function to fetch the next line from any file descriptor (includes newline when present).

Note: This repository contains an implementation done as a 42 School project. See "42 Project constraints" below.

---

## Overview

`c-line-reader-function` provides a compact, well-documented implementation pattern for a function that returns the next line read from a file descriptor each time it is called. It is intended as a minimal utility you can include in exercises, small projects, or as a teaching/reference implementation.

This README describes the function's behavior, usage, compilation, testing hints, and common implementation notes.

## Key features

- Returns the next line from a given `int fd` as a `malloc`'d `char *`.
- Includes the newline character `\n` when one is present in the input.
- Works with arbitrary line lengths by reading in chunks (`BUFFER_SIZE`) and growing buffers as needed.
- Supports independent state per file descriptor (so multiple fds can be read interleaved).
- Minimal external dependencies — easy to understand and adapt.

## 42 Project constraints

This implementation was created as part of the 42 School subject for `get_next_line`. If you are using this for the 42 project, keep in mind:

- Follow the official subject/documentation from 42 for exact rules and evaluation criteria.
- Typical constraints (verify with your subject version):
  - Use only allowed functions; typically `read`, `malloc`, `free`, and functions you implement yourself (string helpers). Avoid disallowed libc functions unless explicitly permitted.
  - The function should behave correctly for multiple file descriptors simultaneously.
  - Use a `BUFFER_SIZE` macro to control the read chunk size (compile-time).
  - Return a `malloc`'d string that the caller must `free`.
  - No memory leaks; pass valgrind tests.
  - Respect any coding style rules (Norminette or project-specific style) required by your school.
- Always cross-check the exact allowed functions and requirements for your campus/subject, as they can change.

## Function prototype

A widely used prototype:

```c
char *get_next_line(int fd);
```

This function:
- Returns a pointer to a malloc-allocated, null-terminated string containing the next line (including the trailing `\n` if present).
- Returns `NULL` on EOF (no bytes left) or on error.
- The caller owns the returned pointer and must `free()` it.

(You may prefer a different internal name to avoid confusion with other repos; adjust README and code accordingly.)

## Compilation

Typical compile command:

```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c -o gnl_test
```

- `BUFFER_SIZE` controls how many bytes are read per `read()` call. Test with small and large values (1, 2, 32, 1024).
- Use `-D BUFFER_SIZE=<n>` to vary the buffer size at compile time.

If you provide a Makefile, include targets:
- `all` — build the binary or library
- `clean` — remove object files
- `fclean` — remove binaries and built files
- `re` — rebuild

## Usage example

Example program to print each line of a file:

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char *get_next_line(int fd);

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0) { perror("open"); return 1; }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // line already includes '\n' when present
        free(line);
    }

    close(fd);
    return 0;
}
```

Compile:

```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c example.c -o example
```

Run:

```sh
./example
```

## Behavior details & guarantees

- Returns each line (including `\n`) as a fresh `malloc`'d string.
- The last line is returned even if the file does not end with a newline.
- On EOF (no remaining data), returns `NULL`.
- On read error, returns `NULL`. Implementation should free any temporaries and avoid leaks.
- Supports multiple simultaneous file descriptors by maintaining separate internal state per `fd`.

## Implementation notes and hints

- Keep a per-fd "remainder" (static buffer or small map keyed by `fd`) to hold bytes read but not yet returned.
- Read into a local buffer of size `BUFFER_SIZE`, append to the remainder, then extract up to and including the first `\n`. Keep leftover bytes for the next call.
- Helper functions to implement/include:
  - `ft_strlen`, `ft_strchr`, `ft_strdup`, `ft_strjoin` (or equivalents)
  - `extract_line` — takes the remainder and returns the next line (including `\n`)
  - `update_remainder` — updates leftover after extracting a line
- Careful with off-by-one when allocating for `\0`.
- Avoid reading one byte at a time; use `read(fd, buf, BUFFER_SIZE)`.

## Edge cases to test

- Files with a final newline and files without a final newline.
- Very long lines that exceed `BUFFER_SIZE` many times.
- `BUFFER_SIZE = 1` and other small values.
- Multiple file descriptors opened and read in interleaved fashion.
- Invalid `fd` values (like `-1`) and read errors.
- Memory leaks and invalid frees (verify with valgrind).

Example test scenario (interleaved fds):
- open `a.txt` and `b.txt`
- call `get_next_line(fd_a)` → line A1
- call `get_next_line(fd_b)` → line B1
- call `get_next_line(fd_a)` → line A2
- ... verify correct interleaving and that no data is mixed.

## Memory checking

Use valgrind:

```sh
valgrind --leak-check=full --show-leak-kinds=all ./example
```

Ensure no leaks and no invalid reads/writes in all tested scenarios.

## Naming & packaging suggestions

You picked `c-line-reader-function`. A few alternative repo-friendly names you might prefer:
- `c-line-reader` (shorter)
- `next-line-reader`
- `line-reader-c`
- `c-line-utils` (if you plan to add helpers)
- `tiny-line-lib` (if you want tiny-lib vibe)

For the function name inside the code, `get_next_line` is conventional. If you want to avoid confusion with other repos or the POSIX `getline`, you can use `cnlr_getline` or `clrf_get_next_line` as a prefix.

Suggested short repo description:
- "Minimal C function to read the next line from a file descriptor — small, portable, and testable. (42 project)"

## Contributing

- Keep changes small and focused.
- Add tests for each edge case and `BUFFER_SIZE` variation.
- Document any API changes in the README.
- If submitting pull requests, include a short description and test cases.

## License

Pick a license (MIT, BSD, or your institution’s preferred license). Example short statement:

```
MIT License — see LICENSE file.
```

## Author

- amwadud — 42 School student
