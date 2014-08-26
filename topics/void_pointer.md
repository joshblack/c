# `void` Pointer

[source](https://www.youtube.com/watch?v=mB7uQiq1ukQ)

Consider the following code:
```c
int *int_ptr = malloc(10 * sizeof(int));
float *float_ptr = malloc(10 * sizeof(float));

free_it(int_ptr);
free_it(float_ptr);
```

Big question:
> Is it possible to write a function that takes a single pointer that points to both an integer and a float? And if so, what would be the return type of the function call malloc(), does it return a pointer to an integer/float?

What should be the type of the parameter `free_it`?

> It is possible to declare a *pointer to anything* as follows: `void * ptr;`

`void` is a non-data type. We can declare a pointer to one of these and that will be the type of the parameter and the return type because of the following reason:

> No compiler errors or warning will be generated when using `ptr` in an assignment statement (or parameter passing) with any other type of pointer.

`void` pointers are used quite frequently by functions like `malloc` and `free`. Basically any function that uses memory in a *generic* way.

## Gotchas

- The value of the expression: `sizeof *ptr` is undefined.
- This means that the value of the expression `ptr[0]` is undefined. This is because we don't know how big the thing is. (Remeber we access memory blocks by adding size of the data type to base value)
- Typically, one would assign the address in a `void` pointer to another, `non-void` pointer before dereferencing it.
    - `emp *el = ptr;`

## Examples

```c
/* void.c */
#include <stdlib.h>
#include <memory.h>

void * memdup(void * mem, int size)
{
    void * newptr;

    newptr = malloc(size);
    memcpy(newptr, mem, size);
    return newptr;
/*  return memcpy(malloc(size), mem, size);
}
```