#include <stdio.h>

typedef struct foo {
    int i;
    char a;
    double d;
} Foo;

/* union fills space of largest member */
typedef union bar {
    int i;
    char a;
    double d;
} Bar;

int main(void) 
{
    Foo foo;
    Bar bar;
    printf("Size of Foo is %d.\n", sizeof(foo)); /* 16 bytes */
    printf("Size of Bar is %d.\n", sizeof(bar)); /* 8 bytes */
}