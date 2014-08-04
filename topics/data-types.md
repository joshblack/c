# Data types

- **Integers:** whole numbers which can be both positive and negative.
    - `char`, -2^07+1 to +2^07-1
    - `int`, -2^15+1 to 2^15-1
    - `short`, -2^15+1 to +2^15-1
    - `long`, -2^31+1 to +2^31-1
    - `long long`, -2^63+1 to +2^63-1
- **Unsigned integers:** whole numbers which can only be positive.
    - `unsigned char`, 0 to +2^07-1
    - `unsigned int`, 0 to 2^15-1
    - `unsigned short`, 0 to +2^15-1
    - `unsigned long`, 0 to +2^31-1
    - `unsigned long long`, 0 to +2^63-1
- **Floating Point Numbers:** real numbers (numbers with fractions).
    - `float`
    - `double`

`char` - normally consumes 1 byte in memory.
`short` - 2 bytes
`int` - 4 bytes
`long` - 4 bytes
`float` - 4 bytes
`double` - 8 bytes

## The `enum` Data Type

> enum, short for *enumerated*, can be used to declare integer constants. The usage of this data type is to make C programs more readable and easier to maintain. An alternate way to declare a named constant is to use the #define drective.

### Declaring the `enum` data type

The general form of the enum data type declaration is: `enum tag_name {enumeration_list} variable_list;`.

## Making `typedef` Definitions

> You can create your own names for data types with the help of the typedef keyword in C, and make those name synonyms for the data types.

For instance you can declare TWO_BYTE as a synonym for the int data type:

```c
typedef int TWO_BTYE;

/* then you can do... */
TWO_BYTE i, j;
int i, j;
```

[Example](c-learning/c-programs/typedef.c)