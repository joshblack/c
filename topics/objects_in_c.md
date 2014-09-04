# Abstract Data Types, Information Hiding

## 1.1 Data Types
> Good programming principles dictate that we conceal the representation of a data item and eclare only the possible manipulations.

## 1.2 Abstract Data Types
> We call a data type *abstract* if we do not reveal its representation to the user.

ADT's offer a ton of flexibility to a programmer. They satisfy the good programming principles of *information hiding* and *divide and conquer*. This is because with an ADT we can cleanly separate the programming tasks of implementation and usage.

## 1.3 An Example -- Set
Consider a `set` with the following operations:
1. `add`
2. `find`
3. `drop`

These all apply to a `set` and an `element` and return the `element` added to, found in, or removed from a set. `find` can be used to implement a condition `contains` which tells us whether an element is already contained in a set.

```c
/* Set.h */
#ifndef SET_H
#define SET_H

extern const void * Set;

void * add(void * set, const void * element);
void * find(const void * set, const void * element);
void * drop(void * set, const void * element);
int contains(const void * set, const void * element);

#endif
```

**Note:** The preprocessor statements protect the declarations: no matter how many times we include `Set.h`, the C compiler only sees the declarations once.

We can think of `void *` as a generic pointer that allows us to pass virtually anything to `add()` and other functions. However, with this approach we are sacrificing type security in the interest of information hiding.

## 1.4 Memory Management
> How does one obtain a set?

**Set** is a pointer, not a type defined by `typedef` and therefore we cannot define local or global variables of type **Set**. We can however use pointers to refer to both **Sets** and **elements** and we declare source and sink of all data items in `new.h`

```c
/* new.h */

#ifndefine NEW_H
#define NEW_H

void * new(const void * type, ...);
void delete(void * item);

#endif
```

In this case:
- `new()` accepts a descriptior like **Set** and possibly more arguments for initialization and returns a pointer to a new data item with a representation conforming to the descriptor.
- `delete()` accepts a pointer originally produced by `new()` and recycles the associated resources.
- Both `new` and `delete` are presumably a frontend to the `calloc` and `free` functions where the descriptor indicates how much memory is required.

## 1.5 Object
If we want to collect anything interesting in a set, we need another abstract data type **Object** as follows:

```c
/* Object.h */
#ifndefine OBJECT_H
#define OBJECT_H

extern const void * Object; /* new(Object) */
int differ (const void * a, const void * b);

#endif
```

In this case:
- `differ()` can compare objects and:
    - returns true if they are not equal
    - returns false if they are

## 1.6 Example Application

```c
#include <stdio.h>

#include "new.h"
#include "Object.h"
#include "Set.h"

int main ()
{
    /* Create a set and add two new objects to it */
    void * s = new(Set);
    void * a = add(s, new(Object));
    void * b = add(s, new(Object));
    void * c = new(Object);

    /* should find both objects in the set */
    if (contains(s, a) && contains(s, b))
        puts("ok")

    /* should not find another new object in the set */
    if (contains(s, c))
        puts("contains?");

    if (differ(a, add(s, a)))
        puts("differ?");

    if (contains(s, drop(s, a)))
        puts("drop?")

    delete(drop(s, b));
    delete(drop(s, c));

    return 0;
}
```

## 1.7 An Implementation -- Set
We now must implement the abstract data types and the memory manager.

If an object stores no information and if every object belongs to at most one set, we can represent each object and each set as small, unique, positive integer values used as indices into an array `heap[]`.

If an object is a member of a set, its array element contains the integer value representing the set. Objects, therefore, point to the set containing them.

```c
/* main.c */
#if ! defined MANY || MANY < 1
#define MANY 10
#endif

static int heap[MANY];

void * new (const void * type, ...)
{
    int * p;
}
```

# Dynamic Linkage and Generic Functions
## 2.1 Constructors and Destructors

