# Learning C

If you want access to standard I/O functionality you include a header file entitled `stdio.h`. The basic structure for a C program is the following:

```c
#include <stdio.h>

// the main method executes for every program
int main() {

    // return 0 if the program is successful, anything > 0 is an error
    return 0;
}
```

# Variable and Types

## Data types

- **Integers:** whole numbers which can be both positive and negative.
    - `char`, -2^07+1 to +2^07-1
    - `int`, -2^15+1 to 2^15-1
    - `short`, -2^15+1 to +2^15-1
    - `long`, -2^31+1 to +2^31-1
    - `long long`, -2^63+1 to +2^63-1
- **Unsigned integers:** whole numbers which can only be positive.
    - `unsigned char`, 0 to +2^07-1
    - `unsigned int`, 0 to 2^15-1
    - `unsigned short`, 0 to +2^15-1
    - `unsigned long`, 0 to +2^31-1
    - `unsigned long long`, 0 to +2^63-1
- **Floating Point Numbers:** real numbers (numbers with fractions).
    - `float`
    - `double`

`char` - normally consumes 1 byte in memory.
`short` - 2 bytes
`int` - 4 bytes
`long` - 4 bytes
`float` - 4 bytes
`double` - 8 bytes

## Defining variables

```c
// variable instantiation
int foo;

// variable declaration
int bar = 1;

// multiple variable declaration
int a = 0, b = 1, c = 2;
```

# Operators and Precedence




# Arrays

You can define an array by doing the following:

```c
// defines an array of 10 integers
int numbers[10];

// array of 4 chars
char names[4] = [1, 2, 3, 4];

char name = ['josh', 'black', 'whoa', 'there']; 

int longArray = {[0] = 1, [1] = 2, [999] = 3}; // array of size 1000

multidimensional arrays
int digits[2][2] = {{0, 1}, {1, 0}};
                 = {0, 1, 1, 0};
```

Arrays in C can only have one type of variable because they are impleted as a sequence of values in the computer's memory.

# Strings

## Defining strings

Strings in C are actually arrays of characters. We can use pointers to a character array to define simple strings as follows:

```c
// define a string that can only be read
char * name = "John Smith";

// define a string that can be manipulated
char name[] = "John Smith";
```

The second notation is different because it allocates an array variable so that we can manipulate it. The `[]` notation tells the compiler to calculate the size of the array automatically. As a result:

```c
char name[] = "John Smith";
/* is the same as */
char name[11] = "John Smith"; // adding one to the length of the string
```

## String comparison

```c
// Compares two strings
int strncmp(string1, string2, comparisonLength) {}
// returns 0 if the two strings are equal
// returns a different number if they are different
```

# Functions

- Functions receive either a fixed or variable amount of arguments
- Functions can only return one value, or no value
- Arguments are `pass by value`, in order to modify arguments we must use pointers

```c
int foo(int bar) {
    return bar;
}
```

We define the return type, then the function name and parameters. The parameters are pairs representing the type of the argument and its name.

```c
/* function declaration */
int foo(int bar);

int main() {
    /* calling foo from main */
    printf("The value of foo is %d", foo(1));
}

int foo(int bar) {
    return bar + 1;
}
```

To define a function that has no return value simply use `void` at the beginning of its declaration.

# Pointers

Pointers are a very important part of C. They are used for many things, including:

- Strings
- Dynamic memory allocation
- Sending function arguments by reference
- Building complicated data structures
- etc.

A pointer is essentially a simple integer variable which holds a memory address that points to a value, instead of holding the actual value itself.

## Strings as pointers

```c
char * name = "John";
```

This line does the following:

1. It allocates a local (stack) variable called `name` which is a pointer to a single character.
2. It causes the string "John" to appear somewhere in the program memory (after it is compiled and executed)
3. It initializes the `name` argument to point to where the `J` character resides at (which is followed by the rest of the string in the memory).

If we try to access the `name` variable as an array, it will return the ordinal value of the character `J` since `name` points to the beginning of the string.

Since memory is sequential we can assume that we can keep moving ahead in memory until we reach the end of the string, marked with a null terminator (the character whose ordinal value is 0, which is `\0`).

## Dereferencing

Dereferencing is the act of referring to where the pointer points at, instead of the memory address.

Accessessing the first item in the array is the same as dereferencing a pointer.

> Dereferencing a pointer is done using the asterisk operator `*`

If we want to create an array that will point to a different variable in our stack, we can write the following code:

```c
/* define a local variable a */
int a = 1;

/* define a pointer variable, and point it to a using the & operator */
int * pointer_to_a = &a;

a += 1;
/* is equivalent to */
*pointer_to_a += 1;
```

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

# Dynamic Allocation

Dynamic allocation of memory allows building complex data structures such as linked lists. Allocating memory dynamically helps us to store data without initially knowing the size of the data in the time we wrote the program.

In order to allocate a chunk of memory dynamically, we need to already have a pointer. This pointer will store the location of the newly allocated memory.

We can access memory that was allocated to us using that same pointer, and we can also use that pointer to free the memory we got once we finish using it.

As a programmer, you are responsible for:

- Explicitly allocating the amount of memory that is needed and when it is needed (using `malloc()` and `calloc()`)
- Explicity deallocate the memory when it is no longer needed. (`free()`)

> To access C's memory allocation functions you need to include `stdlib.h`

## The `malloc()` function

- Used to allocate an arbitrarly sized chunk of memory

`void *malloc(size_t size)`

- size is the number of bytes to allocate (normally computed with `sizeof()`)
- allocated memory is uninitialized
- returns a pointer to the allocated memory, or NULL if error is encountered

## The `calloc()` function

- allocates memory for an array of *nmemb* members of size bytes each.

`void *calloc(size_t nmemb, size_t size);`

- nmemb is the number of members
- size is the number of bytes to allocate for each member 
- allocated memory is initialized to 0
- returns a pointer on success, or NULL.


## The `free()` function

- Used to deallocate previously allocated memory

`void free(void *ptr);`

- ptr is a pointer to previously allocated memory (via `malloc()/calloc()`)
- if ptr is invalid, or points to previously deallocated memory, behavior is undefined



```c
typedef struct {
    char * name;
    char age;
} person;

person * mypseron = malloc(sizeof(person));
```

This tells the compiler that we want to dynamically allocate just enough to a hold a person struct in memory and then return a pointer to the newly allocated data.

To access the person's members we can use `->`.

```c
myperson->name = "Josh";
myperson->age = 27;

/* to free up the memory we can use */
free(myperson);
```

Free does not delete the myperson variable itself, but rather it releases the data that it points to.

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