Learning C
==========

# Variable and Types


## Defining variables

```c
/* variable instantiation */
int foo;

/* variable declaration */
int bar = 1;

/* multiple variable declaration */
int a = 0, b = 1, c = 2;
```

# Operators

Usefull literal translations of certain operators.

Operator    | Translation
------------|--------------
`*`         | "What's at ___"
`&`         | "The address of ___"

# Structures

C structures are special, large variables which contain several named variables inside.

Structures are used for:
- Serialization of data
- Passing multiple arguments in and out of functions through a single argument
- Data structures such as linked lists, binary trees, etc.

The most basic example of structures are **points**, which are a single entity that contains two variables - `x` and `y`. Let's define a point in a two-dimensional point:

```c
struct point {
    int x;
    int y;
}

struct point p;
p.x = 10;
p.y = 5;
draw(p); /* assume draw() receives a point and draws it on a screen */
```

Structures can also hold pointers - which allows them to hold strings, or pointers to other structures as well (which is their real power). They can also hold other structures

```c
struct geofix {
    float latitude;
    float longitidue;
};

struct location {
    char* description
    struct geofix pos;
} home_location = {"UFL", {42.9709, -85.8857}};

home_location.pos.latitude;
home_location.pos.longitude;
```

Can also do arrays of structures

```c
struct location {
    char* description;
    float lat;
    float long;
}

struct location checkins[3] = {
    {"UF", 0, 0},
    {"Starbucks", 0, 0},
    {"Home", 0, 0}
}

checkins[0].description;
checkins[0].lat;
checkins[0].long;
```

> Note: Structs are passed by value.

## Typedefs

Typedefs allow us to create aliases for data types.

Typedefs and arrays
```c
typedef char Buffer [1024];
char b1[1024];
Buffer b2; /* same as previous statement, b1 = b2 */
```

Typedefs and pointers
```c
typedef char *String;
char *strl;
String str2; /* str2 == str1 */
```

You define a typedef by doing the following:
1. Write the statement as if a variable of the desired type was being declared
2. Where the name of the declared variable would normally appear, substitute the new type name
3. In front of everything else, place the keyword typedef


```c
/* Can use the following syntax to remove the `struct` keyword from each time we want to define a new point
typedef struct {
    int x;
    int y;
} point;

/* can now call */
point p;
```

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

# Function arguments by reference

Function arguments are passed by value, which means they are copied into and out of functions. If we copied pointers to values instead of values themselves then it would enable us to give fu nctions control over variables and structores of the parent functions and not just copy them.

```c
void addone(int * n) {
    (*n)++;
}

int n;
printf("Before: %d\n", n);
addone(&n);
printf("After: %d\n", n);
```

This function receives a pointer to the variable n as an argument and as a result it can manipulate it because it knows where the variable is stored in memory.

Notice that we must pass a **reference** to the variable `n` inside of the function call, and not the variable itself. This is done so that the function knows the address of the variable, and won't just receive a copy of the variable itself.

## Pointers to structures

You can also pass in pointers to structures as parameters in your functions. This allows us to dereference a structure and access one of its internal members.

```c
void move(point * p) {
    (*p).x++;
    (*p).y++;
}

/* OR */
void move (point * p) {
    p->x++;
    p->y++;
}
```


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