#include <stdio.h>

int main()
{
    char str1[] = {'A', ' ', 
                   's', 't', 'r', 'i', 'n', 'g', ' ',
                   'c', 'o', 'n', 's', 't', 'a', 'n', 't', '\0'};

    char str2[] = "Another string constant";
    char *ptr_str;
    int i;

    /* print out str1 */
    for (i = 0; str1[i]; i++) {
        printf("%c", str1[i]);
    }

    printf("\n");

    /* print out str2 */
    for (i = 0; str2[i]; i++) {
        printf("%c", str2[i]);
    }

    printf("\n");
    
    /* assigns a pointer to a string */
    ptr_str = "Assign a string to a pointer";

    printf("Memory Addr: %p\n", ptr_str);
    printf("Value: ");

    /**
     * Think of a string as a chain and the pointer points to the first value.
     * If we increment the value of the pointer, we move on to the next value in the string which
     * we find in the next spot in memory (hence the ++).
     */
    for (i = 0; *ptr_str; i++) {
        /* We have two ways of printing out this pointer */

        printf("%c", *ptr_str++);

        /* or the following: 
        
        printf("%c", *ptr_str);
        ptr_str++;
        */
    }

    printf("\n");

    return 0;
}