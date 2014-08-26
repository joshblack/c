# `const`

The keyword `const` is used before the declaration of a variable to indicate that its value will not be changed. This depends however on where the `const` variable is stored, since we are allowed to change the value of a `const` variable by using a pointer.

## Pointer to `const`
`const int *ptr;`

We can change the pointer to point to any other integer variable but we cannot change the value of the object that it is pointing to.

For example:
```c
int main(void)
{
    int i = 10;
    int j = 20;
    const int * ptr = &i;

    * ptr = 100; /* invalid */
    ptr = &j;   /* valid */
}
```