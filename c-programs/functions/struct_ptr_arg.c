#include <stdio.h>

struct computer {
    float cost;
    int year;
    int cpu_speed;
    char cpu_type[16];
};

typedef struct computer COMP;

void DataReceive(COMP *m);

int main(void)
{
    COMP model;

    DataReceive(&model);

    printf("Here is what you entered:\n");
    printf("Year: %d\n", model.year);
    printf("Cost: $%6.2f\n", model.cost);
    printf("CPU Type: %s\n", model.cpu_type);
    printf("CPU Speed: %d MHz\n", model.cpu_speed);

    return 0;
}

void DataReceive(COMP *m)
{
    printf("The type of the CPU inside your computer?\n");
    scanf("%s", (*m).cpu_type);
    scanf("%s", m->cpu_type);

    printf("The speed(MHz) of the CPU?\n");
    scanf("%d", &(*m).cpu_speed);
    scanf("%d", &m->cpu_speed);

    printf("The year your computer was made?\n");
    scanf("%d", &(*m).year);
    scanf("%d", &m->year);

    printf("How much did you pay for the computer?\n");
    scanf("%f", &(*m).cost);
    scanf("%f", &m->cost);

    return m;
}