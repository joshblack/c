# Dynamic Memory Allocation

Dynamic allocation of memory allows building complex data structures such as linked lists. Allocating memory dynamically helps us to store data without initially knowing the size of the data in the time we wrote the program.

In order to allocate a chunk of memory dynamically, we need to already have a pointer. This pointer will store the location of the newly allocated memory.

We can access memory that was allocated to us using that same pointer, and we can also use that pointer to free the memory we got once we finish using it.

As a programmer, you are responsible for:

- Explicitly allocating the amount of memory that is needed and when it is needed (using `malloc()` and `calloc()`)
- Explicity deallocate the memory when it is no longer needed. (`free()`)

> To access C's memory allocation functions you need to include `stdlib.h`

## The `malloc()` function

```c
/**
 * Used to allocate an arbitrarly sized chunk of memory, this allocated memory is uninitialized.
 *
 * @param size, the number of bytes to allocate (normally computed with sizeof())
 * @return returns a void pointer to the allocated memory, or NULL if error is encountered
 */
void *malloc(size_t size);
```

[Example](c-learning/c-programs/memory/malloc.c)

## The `calloc()` function

```c
/**
 * Similar to malloc except the memory space is always initialized to 0
 * 
 * @param nmemb, the number of items/members you want to save in the allocated memory space
 * @param size, gives the number of bytes that each item takes
 * @return void pointer
 */
void *calloc(size_t nmemb, size_t size);
```

## The `free()` function

```c
/**
 * Used to deallocate previously allocated memory
 *
 * @param ptr, pointer to previously allocated memory
 * @return if ptr is invalid, or points to previously deallocated memory, behavior is undefined
 */
void free(void *ptr);
```

## The `realloc()` function

```c
/**
 * Allows you to change the size of a piece of memory space allocated by malloc(), calloc(), or even itself
 *
 * @param block, pointer to the start of a piece of memory space previously allocated
 * @param size, specifies the total byte number you want to change it to
 * @return void pointer
 */
void *realloc(void *block, size_t size);
```