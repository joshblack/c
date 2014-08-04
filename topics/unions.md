# Unions

> A union is a block of memory that is used to hold data items of different types. 

These constructs are very similar to a structure except that data items that are saved in the union are overlaid in order to share teh same memory location. 

## Declaring Unions

The syntax for declaring a union is as follows:

```c
union tag_name {
    data_type variable_name1;
    data_type variable_name2;
    .
    .
    .
    data_type variable_nameN;
};
```

## Defining Union Variables

```c
union automobile {
    int year;
    char model[8];
    int enginer_power;
    float weight;
};

union automobile sedan, honda, ford;
```

## Accessing union members

Using the automobile union from above, we can do the following:

```c
union automobile honda;
honda.year = 2014;

union automobile *ford;
ford->year = 2014;
```

## Unions versus Structures

Data items in a union are overlaid at the same memory location. The size of a union is therefore equal to the size of the largest data item in the list of the union members, which is large enought o hold any members of the union, one at a time. As a result of this union property, it does not make sense to initialize all members of a union together because the value of the latest initialized member overwrites the value of the preceding member. **You initialize a member of a union only when you are ready to use it*. The value contained by a union is the value that is the last assigned member of the union.

## Union Application

There are two kinds of union applications...

1. Referencing the same memory location differently
    - [Example](../c-programs/unions/union_mem.c)
2. Making Structures Flexible
    - We can nest a union inside of a structure so that the structure can hold different types of values.
    - [Example](../c-programs/unions/flex_union.c)