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