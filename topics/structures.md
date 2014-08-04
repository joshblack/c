# Structures

C structures are special, large variables which contain several named variables inside.

Structures are used for:
- Serialization of data
- Passing multiple arguments in and out of functions through a single argument
- Data structures such as linked lists, binary trees, etc.

Data items in a structure are called *fields* or *members* of the structure.

## Declaring Structures

```c
struct struct_tag {
     data_type1 variable1;
     data_type2 variable2;
     data_type3 variable3;
     .
     .
     .
     };
```

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

As evidenced above, you reference structure members with the dot operator. 

[More robust struct example](../c-programs/structures/struct.c)

We can initialize a structure using initializers, which are just separate data items in a list of data separated by commas. So for our point example, we can do the following:

```c
struct point p = {10, 5};
```

We're also able to build arrays of structures...

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
checkins[1].lat;
checkins[2].long;
```

## Structures and Function Calls

> The C language allows you to pass an entire structure to a function. A function can also return a structure back to its caller.

[Example](../c-programs/functions/struct_arg.c)

### Pointing to Structures

> You can pass a function with a pointer that points to a structure in a similar way that you can pass a function with a pointer that refers to an array. 

When passing a structure to a function you copy the entire copy of the structure to the function (pass by value), whereas if you pass a pointer to the structure you get the address that associates the structure inside of the function (pass by reference). In this case, you can reference a structure member with `->` which refers to a structure member with a pointer that points to the structure.

[Example](../c-programs/functions/struct_ptr_arg.c)

## Nested Structures

> A structure is called a ensted structure when one of the members of the structure is itself a structure.

### Forward-Referencing Structures

> If one of the members of a structure is a pointer pointing to another structure that has not been declared yet, the structure is called a **forward-referencing structure**

For example:

```c
struct x {
    int i;
    char ch[8];
    struct y *ptr;
};
```

In this case, it is assumed that y has not been declared yet.

If the pointer in a structure points to the structure itself, the structure is called a self-referencing structure.

[Forward-Referencing Example](../c-programs/structures/forward_ref_struct.c)