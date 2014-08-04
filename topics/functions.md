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