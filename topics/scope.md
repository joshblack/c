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

For Example:

```c
#include <stdio.h>

void foo() {
    int a = 10;
    static int sa = 10;

    a += 5;
    sa += 5;

    prinf("a = %d, sa = %d\n", a, sa);
}

int main(void) {
    int i;

    for (i = 0; i < 10; i++) {
        foo();
    }
}
```

Outputs:

a       |       sa
--------|-----------
15      |   15
15      |   20
15      |   25
15      |   30

etc...

This means that `static` is useful for for maintaining state between invocations if you don't want to use global variables. Shouldn't use this though...makes your code not thread safe.


> `static` is used widely as an "access control" feature. If you have a .c file implementing some functionality, it usually exposes only a few "public" functions to users. The rest of its functions should be made static, so that the user won't be able to access them. This is encapsulation, a good practice

Therefore, `static` is used to set the scope of a global variable and functions to their containing files. 
### The `register` Specifier

> Can use this value to suggest to the compiler that this value should be stored into a register (which is faster that retrieving than memory).

### The `extern` Specifier

> Allows you to allude to a global variable specified in another file.

### The `const` modifier

> If you declare a variable with the const modifier, the content of the variable cannot be changed after it is initialized.

### The `volatile` modifier

> Used when you want to declare a variable whose value can be changed without any explicit assignment statement in your program.