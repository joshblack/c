#include <stdio.h>

/**
 * Example of a structure with multiple data types.
 * 
 */
int main(void)
{
    struct computer {
        float cost;
        int year;
        int cpu_speed;
        char cpu_type[16];
    };

    struct computer model;

    printf("The type of the CPU inside your computer?\n");
    /* fgets(model.cpu_type, sizeof(model.cpu_type), stdin); */
    scanf("%s", model.cpu_type);

    printf("The speed(MHz) of the CPU?\n");
    scanf("%d", &model.cpu_speed);

    printf("The year your computer was made?\n");
    scanf("%d", &model.year);

    printf("How much did you pay for the computer?\n");
    scanf("%f", &model.cost);

    printf("Here is what you entered:\n");
    printf("Year: %d\n", model.year);
    printf("Cost: $%6.2f\n", model.cost);
    printf("CPU Type: %s\n", model.cpu_type);
    printf("CPU Speed: %d MHz\n", model.cpu_speed);

    return 0;
}