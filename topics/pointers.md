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

### Passing Multidimensional Arrays as Arguments

> You can either pass the unsized format of a multidimensional array or a pointer that contains the start address of the multidimensional array to a function.

**[Example](c-learning/c-programs/functions/mult_arr_arg.c)**

## Arrays of Pointers

> In some cases, it's useful to dclare an array of pointers and access the contents pointed to by the array by dereferencnig each pointer.

**Example:**
```c
/* int array of pointers */
int *ptr_int[3];

int x1 = 10;
int x2 = 100;
int x3 = 1000;
ptr_int[0] = &x1;
ptr_int[1] = &x2;
ptr_int[2] = &x3;
```