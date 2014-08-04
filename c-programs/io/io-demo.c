#include <stdio.h>

int main(void) 
{
    char first, middle, last;
    int age;

    printf("Enter your initials, followed by your age: ");
    scanf("%c %c %c %d", &first, &middle, &last, &age);
    printf("My initials are: %c%c%c and my age is %d.\n", first, middle, last, age);

    return (0);
}