# Typedefs

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