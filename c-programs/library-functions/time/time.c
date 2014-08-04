#include <stdio.h>
#include <time.h>

void GetDateTime(void);

int main()
{
    GetDateTime();
    return 0;
}

void GetDateTime(void)
{
    /* declare a value for current time */
    time_t now;

    /* set the current time to now */
    time(&now);

    printf("Current date and time is: %s\n", asctime(localtime(&now)));
}