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

*Note* - C does not have a boolean type. Usually, it is defined using the following notation:

```c
#define BOOL char
#define FALSE 0
#define TRUE 1
```

## Defining variables

```c
// variable instantiation
int foo;

// variable declaration
int bar = 1;

// multiple variable declaration
int a = 0, b = 1, c = 2;
```

# Arrays

You can define an array by doing the following:

```c
// defines an array of 10 integers
int numbers[10];
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

## Typedefs

Typedefs allow us to define types with a different name.

```c
/* Can use the following syntax to remove the `struct` keyword from each time we want to define a new point
typedef struct {
    int x;
    int y;
} point;

/* can now call */
point p;
```

Structures can also hold pointers - which allows them to hold strings, or pointers to other structures as well (which is their real power).

```c
typedef struct {
    char * brand;
    int model;
} vehicle;

vehicle mycar;
mycar.brand = "Ford";
mycar.model = 2007;
```

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

We can access memory that was allocated to us using that same pointer, and we can also use that pointer to free the memory we got once we finish using it

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