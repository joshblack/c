# `extern`
> `extern` extends the visibility of the C variables and functions.

As a reminder, declaration of a variable or a function simply declares that the variable or function exists *somewhere* in the program. It *does not* allocate memory for them. The declaration of a variable or a function is important because ***it reveals the type of the variable or function***.

When we define a variable or a function, the compiler allocates memory for the variable or function.

As a result, definition is a super set of declaration.

So it becomes possible that a variable or a function can be declared any number of times but it can only be defined *once*. (Remember the basic principle that you can't have two locations of the same function or variable).

## `extern` with functions
Going back to `extern`: the declaration and definition of a C function have `extern` prepended with them.

Example:
```c
int foo(int arg1, char arg2);
/* is equivalent to */
extern int foo(int arg1, char arg2);
```

`extern` extends the visibility of a function or variable to the whole system. As a result, a function can be used (called) anywhere in any of the files of the whole program *provided the declaration of the function is known*

## `extern` with variables

```c
/* Declare a C variable without defining it */
extern int var;

/* Declared and defined */
int var;
```

In the first case, the memory will not be allocated and the variable will be declared only. Therefore, we put `extern` explicity for C variables when we want to *declare them without defining them*.

Example 1:
```c
int var;
int main(void)
{
    var = 10;
    return 0;
}
```
No problems.

Example 2:
```c
extern int var;
int main(void)
{
    return 0;
}
```
No problems since var is declared only and is never used.

Example 3:
```c
extern int var;
int main(void)
{
    var = 10;
    return 0;
}
```
This program throws an error at compilation because are variable was declared but the memory for it was never allocated.

Example 4:
```c
#include "vardefinition.h"

extern int var;
int main(void)
{
    var = 10;
    return 0;
}
```
Since the variable has a definition we're all good

## Summary

1. Declaration can be done any number of times but definition only once
2. `extern` keyword is used to extend the visibilty of variables or functions
3. Since functions are visible through out the program by default the use of `extern` is not needed.
4. When `extern` is used with a variable, it's only declared and NOT defined.
5. As an exception, when an `extern` variable is declared with initialization, it is taken as definition of the variable as well.