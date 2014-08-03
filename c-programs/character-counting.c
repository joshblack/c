#include <stdio.h>

main()
{
    /* 
    long numCount;

    numCount = 0;
    while (getchar() != EOF)
        ++numCount;

    printf("%ld\n", numCount);
    */
   
    double numCount;

    for (numCount = 0; getchar() != EOF; ++numCount)
        ;
    printf("%.0f\n", numCount);
}