Learning C
==========

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

# Arrays

You can define an array by doing the following:

```c
/* defines an array of 10 integers */
int numbers[10];

/* array of 4 chars */
char initial[4] = ['j', 'b', 'g', 'e'];

/* array of size 1000 */
int longArray = {[0] = 1, [1] = 2, [999] = 3}; 

/* multidimensional arrays */
int digits[2][2] = {{0, 1}, {1, 0}};
                 = {0, 1, 1, 0};
```

Arrays in C can only have one type of variable because they are impleted as a sequence of values in the computer's memory.

# Strings

A *string* is a character array terminated by a null character (\0).

For example:
```c
/* a character string */
char array_ch[7] = {'H', 'E', 'L', 'L', 'O', '!', '\0'};
```

A series of characters enclosed in double quotes is called a *string constant*. The C compiler automatically adds a null character at the end of the string to indicate its end.

To initialize a character array you can specify its size or allow the C compilter to calculate it for you.

```c
/* make sure to account for the extra null character at the end of the string */
char str[7] = "Hello!";

/* or you can do the following */
char str[] = "Hello!";
```

## String Constants vs Character Constants

A string constant is a series of characters enclosed in double quotes. On the other hand, a character constant is enclosed by single quotes. 

Example:
```c
char ch = 'x';
char str[] = "x";
```

In the example above, only 1 byte is reserved for the character variable ch, and two bytes are allocated for the character array str in order for the null character to be appended to the end of it. 

A string can also be interpreted as a char pointer. Therefore, you can assign a character string to a pointer variable directly. For example:

```c
char *ptr_string;
ptr_string = "A character string"; /* valid */
ptr_string = 'a'; /* invalid */
*ptr_string = 'a'; /* valid */
```
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

## Utility

## Template

```c
#include <string.h>
```

## String comparison

```c
/** 
 * Compares two strings 
 *
 * returns 0 if the two strings are equal
 * returns a different number if they are different
 */
int strncmp(string1, string2, comparisonLength) {}
```

## String length
```c
/**
 * Measure the length of a string
 *
 * Does not count the null character
 */
size_t strlen(const char *s);
```

Example:

```c
#include <stdio.h>
#include <string.h>

int main() 
{
    char str[] = "A string constant";
    char *ptr_str = "Another string constant";

    printf("String length: %d bytes\n", strlen(str));
    printf("String length: %d bytes\n", strlen(ptr_str));
    return 0;
}
```

## Copying a String
```c
/**
 * Copy a string from one array to another
 *
 * Returns the value of src if succesful
 */
char *strcpy(char *dest, const char *src);
```

## IO

### `gets()`
```c
/**
 * Read characters from the standard input stream
 *
 * @param s     the character array that contains a string.
 * @return s, if successful, otherwise null pointer
 */
char *gets(char *s);
```

### `puts()`
```c
/**
 * Used to write characters to the standard output stream (stdout)
 *
 * @param s     character array that contains a string
 * @return 0 if succesful, otherwise a nonzero value is returned
 */
int puts(const char *s);
```

### `scanf()`
```c
/**
 * An alternate way of reading strings from stdin. Can be used to read various types of input data.
 * A null character is automatically appended to the array after the reading.
 * 
 * @return number of data items read from the stdin, otherwise it returns EOF (end of file)
 */
int scanf(const char *format, …);
```

Example Usage:
```c
#include <stdio.h>

int main() 
{   
    char str[80];
    int x, y;
    float z;

    printf("Enter two integers separated by a space:\n");
    scanf("%d %d", &x, &y);

    printf("Enter a floating point number:\n");
    scanf("%f", &z);

    printf("Enter a string:\n");
    scanf("%s", str);

    return 0;
}
```

# Scope

There are four types of scope:

1) Block scope (Contained between {}'s)
2) Function scope (Anything contained within a function)
3) Program scope (Global variables)
4) File scope - a global variable defined to be static has file scope.

## Storage Class

In C, the storage class of a variable refers to the combination of its spatial and temporal regions. Scope encompasses the spatial region of a variable, duration corresponds to a variables temporal region.

There are 4 specifies and two modifiers that can be used to indicate the duration of a variable.

### The `auto` Specifier

> Indicates that the memory location of a variable is temporary. Rarely used because the duration of a variable with block scope is temporary by default.

### The `static` Specifier

> When a variable within a function is declared with the static specifier, the variable has a permanent duration. In other words, the memory storage allocated for the variable is not destroyed when the scope of the variable is exited, the value of the variable is maintained outside the scope, and if execution ever returns to the scope of the variable, the last value stored in the variable is still there.

### The `register` Specifier

> Can use this value to suggest to the compiler that this value should be stored into a register (which is faster that retrieving than memory).

### The `extern` Specifier

> Allows you to allude to a global variable specified in another file.

### The `const` modifier

> If you declare a variable with the const modifier, the content of the variable cannot be changed after it is initialized.

### The `volatile` modifier

> Used when you want to declare a variable whose value can be changed without any explicit assignment statement in your program. 


# Functions

## Declaring Functions

### Declaration vs Definition

- A ***function declaration*** alludes to a function that is defined elsewhere and specifies what kind of value is returned by the function. 
- A ***function definition*** defines what the function does, as well as gives the number and type of arguments passed to the function.

### Specifying return types

> A function can be declared to return any data type, except an array or function. The return statement used in a function definition returns a single value whose type should match the one declared in the function declaration.

By default, the return type of a function is int. 

### Using Prototypes

```c
data_type_specifier  function_name(
      data_type_specifier argument_name1,
      data_type_specifier argument_name2,
      data_type_specifier argument_name3,
      .
      .
      .
      data_type_specifier argument_nameN,
);
```

## Prototyping Functions

There are three cases regarding arguments being passed into functions:
1. A function that takes no arguments
2. A function that takes a fixed number of arguments
3. A function that takes a variable number of arguments

### A function that takes no arguments

The declaration would be `data_type function_name(void)`.

### A function that takes a fixed number of arguments

`int function_1(int x, int y);`

### A function that takes a multiple number of arugments

```c
data_type_specifier  function_name(
      data_type_specifier argument_name1, ...
);
```

#### Processing variable arguments

There are three routines, declared in the header file `<stdarg.h>`, that enable you to write functions that take a variable number of arguments

1. `va_start()`
2. `va_arg()`
3. `va_end()`

Also included in `<stdarg.h>` is `va_list`, that defines an array type suitable for containing data items needed by `va_start()`, `va_arg()`, and `va_end()`

#### va_start()

```c
#include <stdarg.h>

/**
 * @param ap, the name of the array about to be initialized by the va_start macro routine
 * @param lastfix, the argument before the ellipsis in the function declaration
 */
void va_start(va_list ap, lastfix);
```

#### va_arg()

```c
/**
 * Allows you to be able to deal with the type and value of the next argument. 
 * Is used to get the next argument passed to the function.
 *
 * @param ap, the name of the array that is initialized by the va_arg macro routine
 * @param data_type, the data type of the argument passed
 */
type va_arg(va_list ap, data_type);
```

#### va_end()

```c
/**
 * Used to facilitate a normal return from your function after all your arguments have been processed
 * @param ap, the name of the array that is initialized by the va_end macro routine
 */
void va_end(va_list ap);
```

- Functions receive either a fixed or variable amount of arguments
- Functions can only return one value, or no value
- Arguments are `pass by value`, in order to modify arguments we must use pointers

```c
int foo(int bar) {
    return bar;
}
```

#### Example processing multiple variables

```c
#include <stdio.h>
#include <stdarg.h>

double AddDouble(int x, ...);

int main()
{
    double d1 = 1.5;
    double d2 = 2.5;
    double d3 = 3.5;
    double d4 = 4.5;

    printf("Given an argument: %2.1f\n", d1);
    printf("The result returned by AddDouble() is: %2.1f\n\n", AddDouble(1, d1));

    printf("Given arguments: %2.1f and %2.1f\n", d1, d2);
    printf("The result returned by AddDouble() is: %2.1f\n\n", AddDouble(2, d1, d2));

    printf("Given arguments: %2.1f, %2.1f and %2.1f\n", d1, d2, d3);
    printf("The result returned by AddDouble() is: %2.1f\n\n",
       AddDouble(3, d1, d2, d3));

    printf("Given arguments: %2.1f, %2.1f, %2.1f, and %2.1f\n", d1, d2, d3, d4);
    printf("The result returned by AddDouble() is: %2.1f\n",
       AddDouble(4, d1, d2, d3, d4));

    return 0;
}

double AddDouble(int x, ...)
{
    va_list arglist;
    int i;
    double result = 0.0;

    printf("The number of arguments is: %d\n", x);
    va_start(arglist, x);

    for (i = 0; i < x; i++) {
        result += va_arg(arglist, double);
    }

    va_end(arglist);

    return result;
}
```

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
char *name = "John";
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

## Pointer Arithmetic

> You can move the position of a pointer by adding or subtracting integers to or from the pointer.

```c
/**
 * Indicates to the compiler to move to the memory location that is one byte away from the
 * current position of ptr_string
 */
ptr_str + 1;
```

It's important to note that the addition or subtraction of some integer does not necessarily correspond 1:1 with bytes, but rather it adjusts the address over one element of the type of the pointer you are adjusting.

As a result, when you perform `pointer_name + n`, the compiler is actually doing the following:

```c
data_type_specifier *pointer_name;

pointer_name + n * sizeof(data_type_specifier);
```

### Subtracting Pointers

When subtracting pointers, you don't get a result with the amount of bytes between the two pointers but rather the number of that data_type between the two values. 

A good example to illustrate this would be the following:

```c
/* Everything in pointer land is about offsets. When you say: */
int array[10];
array[7] = 42;

/* this translates to... */
*( &array[0] + 7 ) = 42;

/* which is literally translated as... */
* = "what's at"
(
    & = "the address of"
    array[0] = "the first slot in array"
    plus 7
)
set that thing to 42

/* so, if we can add 7 to make the offset to the right place, then we need to be able to go the other direction */
&array[0] + 7 == &array[7]

/* for sanity, and symmetry... */
&array[7] - &array[0] == 7
```

This reinforces the following section...

## Pointers and Arrays

> Pointers and arrays have a close relationship. You can accress an array through a pointer that contains the start address of the array. You can also access array elements through pointers.

Any array name that is not followed by a subscript is interpreted as a pointer to the first element of the array.  As a result, you can assign the start address of the array to a pointer of the same data type and subsequently access indexed elements of that array by using the appropriate offset.

## Pointers and Functions

### Passing Arrays to Functions

> Arrays decay immediately into pointers and, as such, an array is never actually passed to a function.

Therefore,

```c
void f(char a[]) { ... }
/* actually is... */
void f(char *a) { ... }
```

This makes sense because of what we mentioned earlier, that an array name that is not followed by a subscript is interpreted as a pointer to the first element of the array.

Actual Example:

```c
#include <stdio.h>

int AddThree(int list[]);

int main()
{
    int sum, list[3];

    printf("Enter three integers separated by spaces:\n");
    scanf("%d%d%d", &list[0], &list[1], &list[2]);

    sum = AddThree(list);

    printf("The sum of the three integers is: %d\n", sum);

    return 0;
}

int AddThree(int list[])
{
    int i;
    int result = 0;

    for (i = 0; i < 3; i++) {
        result += list[i];
    }

    return result;
}
```

### Passing Pointers to Functions

> Since the address of the first element in an array is the start address of the array itself, we can assign the start address of an array to a pointer and then pass the pointer name to a function.

Example:
```c
#include <stdio.h>

void ChPrint(char *ch);
int DataAdd(int *list, int max);

int main()
{
    char str[] = "It's a string!";
    char *ptr_str;

    int list[5] = {1, 2, 3, 4, 5};
    int *ptr_int;

    /* assign addr to pointer */
    ptr_str = str;
    ChPrint(ptr_str);
    ChPrint(str);

    /* assign addr to pointer */
    ptr_int = list
    printf("The sum returned by DataAdd(): %d\n", DataAdd(ptr_int, 5));
    printf("The sum returned by DataAdd(): %d\n", DataAdd(list, 5));

    return 0;
}

void ChPrint(char *ch) 
{
    printf("%s\n", ch);
}

int DataAdd(int *list, int max)
{
    int i;
    int sum = 0;

    for (i = 0; i < max; i++) {
        sum += list[i];
        /* sum += *(list + i) */
    }

    return sum;
}
```

## Passing Multidimensional Arrays as Arguments


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