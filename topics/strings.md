# Strings

A *string* is a character array terminated by a null character (\0).

For example:
```c
/* a character string */
char array_ch[7] = {'H', 'E', 'L', 'L', 'O', '!', '\0'};
```

A series of characters enclosed in double quotes is called a *string constant*. The C compiler automatically adds a null character at the end of the string to indicate its end.

To initialize a character array you can specify its size or allow the C compilter to calculate it for you.

```c
/* make sure to account for the extra null character at the end of the string */
char str[7] = "Hello!";

/* or you can do the following */
char str[] = "Hello!";
```

## String Constants vs Character Constants

A string constant is a series of characters enclosed in double quotes. On the other hand, a character constant is enclosed by single quotes. 

Example:
```c
char ch = 'x';
char str[] = "x";
```

In the example above, only 1 byte is reserved for the character variable ch, and two bytes are allocated for the character array str in order for the null character to be appended to the end of it. 

A string can also be interpreted as a char pointer. Therefore, you can assign a character string to a pointer variable directly. For example:

```c
char *ptr_string;
ptr_string = "A character string"; /* valid */
ptr_string = 'a'; /* invalid */
*ptr_string = 'a'; /* valid */
```
## Defining strings

Strings in C are actually arrays of characters. We can use pointers to a character array to define simple strings as follows:

```c
// define a string that can only be read
char * name = "John Smith";

// define a string that can be manipulated
char name[] = "John Smith";
```

The second notation is different because it allocates an array variable so that we can manipulate it. The `[]` notation tells the compiler to calculate the size of the array automatically. As a result:

```c
char name[] = "John Smith";
/* is the same as */
char name[11] = "John Smith"; // adding one to the length of the string
```

## Utility

## Template

```c
#include <string.h>
```

## String comparison

```c
/** 
 * Compares two strings 
 *
 * returns 0 if the two strings are equal
 * returns a different number if they are different
 */
int strncmp(string1, string2, comparisonLength) {}
```

## String length
```c
/**
 * Measure the length of a string
 *
 * Does not count the null character
 */
size_t strlen(const char *s);
```

Example:

```c
#include <stdio.h>
#include <string.h>

int main() 
{
    char str[] = "A string constant";
    char *ptr_str = "Another string constant";

    printf("String length: %d bytes\n", strlen(str));
    printf("String length: %d bytes\n", strlen(ptr_str));
    return 0;
}
```

## Copying a String
```c
/**
 * Copy a string from one array to another
 *
 * Returns the value of src if succesful
 */
char *strcpy(char *dest, const char *src);
```

## IO

### `gets()`
```c
/**
 * Read characters from the standard input stream
 *
 * @param s     the character array that contains a string.
 * @return s, if successful, otherwise null pointer
 */
char *gets(char *s);
```

### `puts()`
```c
/**
 * Used to write characters to the standard output stream (stdout)
 *
 * @param s     character array that contains a string
 * @return 0 if succesful, otherwise a nonzero value is returned
 */
int puts(const char *s);
```

### `scanf()`
```c
/**
 * An alternate way of reading strings from stdin. Can be used to read various types of input data.
 * A null character is automatically appended to the array after the reading.
 * 
 * @return number of data items read from the stdin, otherwise it returns EOF (end of file)
 */
int scanf(const char *format, …);
```

Example Usage:
```c
#include <stdio.h>

int main() 
{   
    char str[80];
    int x, y;
    float z;

    printf("Enter two integers separated by a space:\n");
    scanf("%d %d", &x, &y);

    printf("Enter a floating point number:\n");
    scanf("%f", &z);

    printf("Enter a string:\n");
    scanf("%s", str);

    return 0;
}
```