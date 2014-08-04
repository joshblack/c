#include <stdio.h>

int main() 
{
    char *ptr_ch;
    int *ptr_int;
    double *ptr_dbl;

    /* char pointer ptr_ch */
    printf("Current position of ptr_ch: %p\n", ptr_ch);
    printf("The position after ptr_ch + 1: %p\n", ptr_ch + 1);
    printf("The position after ptr_ch - 1: %p\n", ptr_ch - 1);

    /* int pointer ptr_int */
    printf("Current position of ptr_int: %p\n", ptr_int);
    printf("The position after ptr_int + 1: %p\n", ptr_int + 1);
    printf("The position after ptr_int - 1: %p\n", ptr_int - 1);

    /* double pointer ptr_dbl */
    printf("Current position of ptr_dbl: %p\n", ptr_dbl);
    printf("The position after ptr_dbl + 1: %p\n", ptr_dbl + 1);
    printf("The position after ptr_dbl - 1: %p\n", ptr_dbl - 1); 

    return 0;
}