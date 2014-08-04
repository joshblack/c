#include <stdio.h>
#include <string.h>

struct survey {
    char name[20];
    char c_d_p;
    int age;
    int hour_per_week;
    union {
        char cable_company[16];
        char dish_company[16];
    } provider;
};

void DataEnter(struct survey *s);
void DataDisplay(struct survey *s);

int main(void)
{
    struct survey tv;

    DataEnter(&tv);
    DataDisplay(&tv);

    return 0;
}

void DataEnter(struct survey *s)
{
    char is_yes[4];

    printf("Are you using cable at home? Yes or No\n");
    scanf("%s", is_yes);

    if (is_yes[0] == 'Y' || is_yes[0] == 'y') {
        printf("Enter the cable company name:\n");
        scanf("%s", s->provider.cable_company);

        s->c_d_p = 'c';
    } else {
        printf("Are you using satellite dish? Yes or No\n");
        scanf("%s", is_yes);

        if (is_yes[0] == 'Y' || is_yes[0] == 'y') {
            printf("Enter the satellite company name:\n");
            scanf("%s", s->provider.dish_company);
            s->c_d_p = 'd';
        } else {
            s->c_d_p = 'p';
        }
    }

    printf("Please enter your name:\n");
    scanf("%s", s->name);

    printf("Your age:\n");
    scanf("%d", &s->age);

    printf("How many hours do you spend on watching TV per week:\n");
    scanf("%d", &s->hour_per_week);
}

void DataDisplay(struct survey *s) 
{
    printf("\nHere's what you've entered so far:\n");
    printf("Name: %s\n", s->name);
    printf("Age: %d\n", s->age);
    printf("Hours per week: %d\n", s->hour_per_week);

    if (s->c_d_p == 'c') {
        printf("Your cable company is: %s\n", s->provider.cable_company);
    } else if (s->c_d_p == 'd') {
        printf("Your dish company is: %s\n", s->provider.dish_company);
    } else {
        printf("You don't have cable or a satellite dish.\n");
    }

    printf("Thanks and bye!\n");
}