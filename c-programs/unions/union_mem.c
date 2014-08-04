#include <stdio.h>

/**
 * In standard systems, a character represents 1 byte and an int represents 2 bytes.
 * Therefore, a character array with two elements should be equivalent in size to an int
 */
union u {
    char ch[2];
    int num;
};

int UnionInitialize(union u val);

int main(void)
{
    union u val;
    int x;

    x = UnionInitialize(val);

    printf("The two character constants held by the union:\n");
    printf("%c\n", x & 0x00FF);
    printf("%c\n", x >> 8);

    return 0;
}

/**
 * We initialize our union with two chars and return the num member, 
 * Since this is a union, num will point to the same memory location as
 * the character array
 */
int UnionInitialize(union u val)
{
    val.ch[0] = 'H';
    val.ch[1] = 'i';

    return val.num;
}