<i>This project has been created as part of the 42 curriculum by **agiron-f**</i>


# get_next_line

## Description

`get_next_line` is a 42 School project that implements a function for reading a file descriptor one line at a time.

The function returns the next available line on each call, including the newline character when one is present. It keeps unread data between calls so that the caller does not need to manage the file buffer manually.

## Prototype

```c
char *get_next_line(int fd);
```

## Return value

- The next line read from `fd`, including `\n` when the line ends with a newline.
- `NULL` when the end of the file is reached, an invalid file descriptor is supplied, or a read/allocation error occurs.

## Project structure

| File | Purpose |
| --- | --- |
| `get_next_line.c` | Public function and line-reading logic. |
| `get_next_line_utils.c` | String and newline helper functions. |
| `get_next_line.h` | Function declarations and the default `BUFFER_SIZE`. |


## How it works

The implementation uses a static pointer named `stash` to preserve data that has been read but not yet returned.

1. `get_next_line` validates the file descriptor and `BUFFER_SIZE`.
2. `read_and_stash` allocates a temporary buffer and reads up to `BUFFER_SIZE` bytes.
3. Reading continues until the stash contains a newline or `read` reaches end-of-file.
4. `extract_line` copies the first line from the stash.
5. `clear_stash` removes the returned line and keeps the remaining characters for the next call.
6. The returned line is owned by the caller and must be released with `free`.

This design allows the function to work with lines shorter than, equal to, or longer than `BUFFER_SIZE`.

## Internal functions

### `search_newline`

Checks whether a string contains a newline character.

### `ft_strjoin`

Concatenates the current stash with newly read data and frees the previous stash.

### `ft_strlen`

Calculates the length of a string.

### `read_and_stash`

Reads data from the file descriptor until a complete line is available or EOF is reached.

### `extract_line`

Allocates and returns the first line stored in the stash.

### `clear_stash`

Removes the returned line from the stash and preserves unread data.

# Usage

Include the header and repeatedly call `get_next_line()` until it returns `NULL`.

## Example

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*buffer;

	fd = open("test", O_RDONLY);

	printf("%d", fd);
	if (fd == -1)
		return (1);
	while ((buffer = get_next_line(fd)) != NULL)
	{
		printf("%s", buffer);
		free(buffer);
	}
	close(fd);
	return (0);
}
```

---


## Compilation

Compile the project with the required warning flags:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \\
   get_next_line.c get_next_line_utils.c main.c \\
   -o get_next_line
```

If `BUFFER_SIZE` is not supplied by the compiler, the header uses the default value `42`.


## Memory management

Each successful call to `get_next_line` allocates a new string. The caller is responsible for freeing that string:

```c
char *buffer;

while ((buffer = get_next_line(fd)) != NULL)
{
	printf("%s", buffer);
	free(buffer);
}
```

The internal stash is released when all remaining data has been consumed or when a read error occurs.

## Current limitations

- The current implementation uses one static stash, so it is intended to be used with one file descriptor at a time.
- The multi-file-descriptor bonus behavior is not implemented.
- `main.c` is a local test harness and is not part of the mandatory `get_next_line` API.

## 42 project compliance

The implementation follows the mandatory project requirements:

- Reads from a file descriptor using `read`.
- Returns one line per function call.
- Works with a configurable `BUFFER_SIZE`.
- Includes the newline character when it is present.
- Returns `NULL` at EOF or on error.
- Does not use external string-reading libraries.

## License

This project was created as part of the 42 School curriculum and is intended for educational purposes.
