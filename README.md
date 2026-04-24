# README

*This project has been created as part of the 42 curriculum by molariou.*

## Description

This project implements a custom version of the C standard library's `printf()` function called `ft_printf()`. The goal is to create a library that mimics the behavior of the original printf() while learning about variadic functions in C.

The project implements all mandatory conversion specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.

Key features:
- Handles variable number of arguments using `va_list`
- Supports character, string, pointer, and numeric conversions
- Returns the number of characters printed
- Does not implement buffer management of the original printf()

## Instructions

### Compilation

To compile the project, simply run:

```bash
make
```

This will create the `libftprintf.a` library at the root of the repository.

### Cleaning

To remove object files:
```bash
make clean
```

To remove all generated files including the library:
```bash
make fclean
```

To rebuild everything from scratch:
```bash
make re
```

### Usage

To use the library in your C projects:

1. Include the header file:
```c
#include "libftprintf.h"
```

2. Link against the library:
```bash
gcc your_program.c -L. -lftprintf
```

3. Use `ft_printf()` just like the standard `printf()`:
```c
ft_printf("Hello %s, you are %d years old\n", "Alice", 25);
```

## Resources

- [printf() manual page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [C variadic functions documentation](https://en.cppreference.com/w/c/variadic)
- [Hexadecimal conversion guide](https://en.cppreference.com/w/c/language/escape)
- 42 Norm documentation and guidelines

## Algorithm and Data Structures

### Algorithm Overview

The `ft_printf()` function uses a simple string parsing algorithm:

1. **Initialization**: Use `va_start()` to access the variadic arguments
2. **Main Loop**: Iterate through the format string character by character
3. **Format Detection**: When a `%` is encountered, check the next character for the conversion specifier
4. **Conversion Handling**: Call the appropriate helper function based on the specifier
5. **Output**: Write characters to stdout using the `write()` system call
6. **Cleanup**: Use `va_end()` to properly close the variadic argument list

### Conversion Functions

- **`ft_putchar()`**: Outputs a single character and returns 1
- **`ft_putstr()`**: Outputs a complete string, handling NULL pointers
- **`ft_putnbr()`**: Recursively converts signed integers to decimal and outputs them
- **`ft_putnbr_pos()`**: Handles unsigned integers, avoiding issues with negative values
- **`puthexnbr()`**: Recursively converts to hexadecimal (both lowercase and uppercase)
- **`format_pointer()`**: Handles pointer conversion with the "0x" prefix

### Data Structures

The project uses simple, straightforward data structures:
- **`va_list`**: A standard C type for managing variadic arguments
- **Integer counter**: Tracks the total number of characters printed across all conversions

This approach prioritizes clarity and correctness over complexity. Each conversion is handled independently, making the code maintainable and easy to extend for bonus features.

## AI Usage

For this project, AI was used in compliance with the 42 norms and rules to generate examples of variadic functions, facilitating a deeper understanding of the concept.
