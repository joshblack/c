#include <stdio.h>

/* forward referencing structure */
struct resume {
    char name[16];
    struct education *undergrad;
    struct education *grad;
};

/* referenced structure */
struct education {
    int year;
    char school[32];
    char degree[8];
};

void DisplayInfo(struct resume *r);

int main(void)
{
    struct education undergrad = {
        1985,
        "Rice University",
        "B.S."
    };

    struct education grad = {
        1987,
        "UT Austin",
        "M.S"
    };

    struct resume new_employee = {
        "Tony",
        &undergrad,
        &grad
    };

    printf("Here is the new employee's resume!\n");
    DisplayInfo(&new_employee);

    return 0;
}

void DisplayInfo(struct resume *r)
{
    printf("Name: %s\n", r->name);

    /* undergrad stuff */
    printf("Year Graduated: %d\n", r->undergrad->year);
    printf("School Name: %s\n", r->undergrad->school);
    printf("Degree: %s\n", r->undergrad->degree);

    /* grad stuff */
    printf("Year Graduated: %d\n", r->grad->year);
    printf("School Name: %s\n", r->grad->school);
    printf("Degree: %s\n", r->grad->degree);
}