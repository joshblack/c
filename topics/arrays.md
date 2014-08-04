# Arrays

You can define an array by doing the following:

```c
/* defines an array of 10 integers */
int numbers[10];

/* array of 4 chars */
char initial[4] = ['j', 'b', 'g', 'e'];

/* array of size 1000 */
int longArray = {[0] = 1, [1] = 2, [999] = 3}; 

/* multidimensional arrays */
int digits[2][2] = {{0, 1}, {1, 0}};
                 = {0, 1, 1, 0};
```

Arrays in C can only have one type of variable because they are impleted as a sequence of values in the computer's memory.