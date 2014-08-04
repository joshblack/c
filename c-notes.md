Learning C
==========

# Operators

Usefull literal translations of certain operators.

Operator    | Translation
------------|--------------
`*`         | "What's at ___"
`&`         | "The address of ___"


# Unions

Let us store different data types in the same location:

```c
union indecision {
    char c;
    int i;
    double d;
};
```

A variable of a union type will take up as much memory as the largest item it can hold.

# Working with Files

`fopen()` opens up text and binary files for read/write.
`fclose()` close file when finished

## Dealing with errors

- `errno` - globally defined external integer that is that is set to the last error code.
- `#include <errno.h>`
- `ferror()` - returns errno for file props
- `perror()` - handy output function for printing textual description of error.
- `scanf()` - reads from input
- `fscanf()` - inputs come from files. 
- `fgetc()` - read text file character at a time.
- `fgets()` - lets us read a line at a time
- `fprintf()` - output goes to file
- `fputc()` - write to a text file one character at a time
- `fputs()` - let us write to a text file one line at a time

# General Notes

- Arrays let us define a multiplicity of homogenous chunks of data
- Structs let us clump a group of logically related heterogeneous chunks of data in a single entity
- typedefs just give us syntactical sugar to create aliases for types.

// write a mixin function in C?
How to add behavior to a struct?
setup inheritance?

# Standard I/O

C defines a library of functions that support integration with standard input/output

## Output formatting

Usage: `printf("Some string with %cormat rule.", 'f');`

Format rule  |  Usage
-------------|-------
`%c`         | Outputs a single character
`%d`         | Outputs a single digit
`%p`         | Outputs a memory address
`%lu`        | Outputs a long unsigned value
`%s `        | Outputs a string

## `getchar()`

```c
/**
 * Reads the next character from standard input (if available)
 *
 * Returns EOF when end of file or error conditions are encountered
 */
int getchar(void);
```

## `putchar()`

```c
/**
 * Writes the character c (converted to an unsigned char) to standard output 
 *
 * returns the character that was written
 */
int putchar(int c);
```

## Formatted Output

### `printf()`

```c
/* display formatted output to stdout */
printf(format_str, arg1, arg2, ...);

/* arguments are the variables to be printed */
/* format string tells printf() how to display these arguments */

/* example */
printf("who: %s size: %d cost: %5.2f", "you", 12, 1.2);
/* value in format_str replaced by args */
```

### `scanf()`

Reads formatted input from standard input.

```c
/**
 * Arguments are the addresses of variables that will store the read values
 *
 * format string tells scanf() how the input is formatted
 */
scanf(format_str, &arg1, &arg2, ...);

/* Example: */
/* Input data: y 101 */

char c;
int i;
scanf("%c %d", &c, &i);

/* c => y */
/* i => 101 */
```