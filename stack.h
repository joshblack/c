typedef char stackElementT;

typedef struct {
    stackElementT *contents;
    int top;
    int maxSize;
} stackT;

void StackInit(stackT *stackP, int maxSize)
{
    stackElementT *newContents;

    /* Allocate a new array to hold the contents. */
    newContents = (stackElementT *)malloc(sizeof(stackElementT) * maxSize);

    if (newContents == NULL) {
        fprintf(stderr, "%s\n", "Insufficient memory to initialize the stack.\n");
        exit(1);
    }
}