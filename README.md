<i>This project has been created as part of the 42 curriculum by **agiron-f**</i>

# GET_NEXT_LINE
## Description

**get_next_line** is a fundamental project in the 42 curriculum. The goal is to write a function that returns a line read from a file descriptor (`fd`), one line at a time, each time it is called.

The function handles reading from files, standard input, or pipes, regardless of the line length or the `BUFFER_SIZE` defined at compile time. Unread data between function calls is preserved using a **static variable** (`stash`), with strict zero-leak dynamic memory management.

---

## Features

- Reads one line at a time from any valid file descriptor.
- Works seamlessly with files, standard input (`stdin`), and pipes.
- Supports configurable compile-time `BUFFER_SIZE` (e.g. 1, 42, 9999, 1000000).
- Preserves unread data across successive calls using static storage.
- Includes trailing newline `\n` when present in the file.
- Strict dynamic memory management with 0 memory leaks.
- Fully compliant with 42 Norminette ($\le 25$ lines per function, $\le 5$ functions per file).

---

## Function Prototype

```c
char	*get_next_line(int fd);
```

### Return Value

- **The line read**: A null-terminated string containing the next line, including `\n` if present.
- **NULL**: If there is nothing more to read (EOF reached), an invalid file descriptor is supplied, or an error occurs.

---

## Allowed Functions

- `read`
- `malloc`
- `free`

---

## Project Structure

```text
.
├── get_next_line.c        # Main function, read loop, line extraction and stash cleanup
├── get_next_line_utils.c  # Helper functions (ft_strlen, search_newline, ft_strjoin)
├── get_next_line.h        # Header file with prototypes and default BUFFER_SIZE
└── README.md              # Project documentation
```

### Files and Functions Breakdown

| File                    | Function         | Description                                                                 |
| :---------------------- | :--------------- | :-------------------------------------------------------------------------- |
| `get_next_line.c`       | `get_next_line`  | Validates input, coordinates reading, extracts and returns the line.        |
| `get_next_line.c`       | `read_and_stash` | Reads from `fd` in chunks of `BUFFER_SIZE` until a `\n` or EOF is reached.  |
| `get_next_line.c`       | `extract_line`   | Allocates and isolates the line (up to and including `\n`) from the stash.  |
| `get_next_line.c`       | `clear_stash`    | Trims the extracted line from the stash, preserving remaining unread bytes. |
| `get_next_line_utils.c` | `ft_strlen`      | Calculates the length of a string.                                          |
| `get_next_line_utils.c` | `search_newline` | Checks whether a string contains a newline character (`\n`).                |
| `get_next_line_utils.c` | `ft_strjoin`     | Concatenates new buffer content to the stash, freeing the old stash.        |

---

## Algorithm

Each call to `get_next_line(fd)` performs the following steps:

1. **Read (`read_and_stash`)**: Reads from the file descriptor in blocks of `BUFFER_SIZE` bytes into a temporary buffer until a newline (`\n`) is encountered or end-of-file (EOF) is reached.
2. **Store (`ft_strjoin`)**: Concurrently concatenates the read buffer into the persistent static variable (`stash`) and frees the previous stash allocation.
3. **Extract (`extract_line`)**: Allocates memory for the line (from index 0 up to and including `\n`, plus `\0`) and returns it to the caller.
4. **Preserve (`clear_stash`)**: Frees the processed line from the stash and allocates a new string containing only the remaining unread characters for subsequent calls.

---

## Compilation

The project can be compiled with any `BUFFER_SIZE` specified at compile time using the `-D` flag:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

> [!NOTE]
> If `BUFFER_SIZE` is not specified, `get_next_line.h` defines a default fallback of `BUFFER_SIZE 42`.

---

## Usage Example

Create a `main.c` file:

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

Run the program:

```bash
./gnl
```

---

## Memory Management & Leak Checking

Every line returned by `get_next_line` is dynamically allocated and **must be freed by the caller**. The internal `stash` is automatically freed when EOF is reached or if an error occurs.

To verify memory safety using **Valgrind**:

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./gnl
```

Expected output:

```text
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
```

---

## Edge Cases Covered

- ✅ Empty files (returns `NULL` immediately).
- ✅ Files with a single character without newline.
- ✅ Files with only `\n` or consecutive empty lines.
- ✅ Files ending without a newline.
- ✅ Lines significantly longer than `BUFFER_SIZE`.
- ✅ `BUFFER_SIZE` = 1 (character by character read).
- ✅ Extremely large `BUFFER_SIZE` (e.g. 10,000,000).
- ✅ Invalid file descriptors (`fd < 0` or unopened descriptors).
- ✅ Reading from Standard Input (`stdin`, `fd = 0`).
- ✅ Repeated calls after reaching EOF (consistently returns `NULL`).

---

## AI Usage

Artificial Intelligence was consulted in accordance with 42 curriculum policies as an educational assistant to:

- Discuss algorithmic edge cases and buffer boundary conditions.
- Assist in diagnosing memory management and leak patterns.
- Structure clear project documentation and Markdown formatting.

All final code, implementation decisions, debugging, and verification were done by the project author.

---

## What I Learned

- Deep understanding of **static variables** in C and their lifecycle across function invocations.
- Low-level I/O manipulation with the `read()` system call and file descriptors.
- Dynamic memory allocation, pointer manipulation, and leak prevention.
- Defensive programming against invalid inputs, read errors, and unexpected EOF scenarios.
- Writing clean, modular C code compliant with 42 Norminette standards.

---

## Author

**Ariel Brandon Giron Flores**

- GitHub: [@ArielBrandonFlores](https://github.com/ArielBrandonFlores)
- 42 Intra: **agiron-f**
