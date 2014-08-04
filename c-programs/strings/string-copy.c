#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "Copy a string";
    char str2[15];
    char str3[15];

    int i;

    /* with strcopy */
    strcpy(str2, str1);

    /* without strcopy) */
    for (i = 0; str1[i]; i++) {
        str3[i] = str1[i];
    }

    str3[i] = '\0';

    /* display strings */
    printf("The content of str1 is: %s\n", str1);
    printf("The content of str2 is: %s\n", str2);
    printf("The content of str3 is: %s\n", str3);

    return 0;
}