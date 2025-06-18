#include "ex1.h"
#define SIZE 5

int main()
{
    int i, value;
    Stack stack;
    Item *temp;
    stack.head = NULL;
    stack.size = 0;

    int numbers[6] = {1, 2, 3, 4, 5, 6};
    for (i = 0; i < 6; i++)
    {
        if (stack.size >= SIZE)
        {
            printf("\nStack is full");
            break;
        }
        else
        {
            Push(&stack, numbers[i]);
            PrintPush(&stack);
        }
    }

    Pop(&stack, &value);
    printf("\nPop number: %d", value);
    Pop(&stack, &value);
    printf("\nPop number: %d", value);
    PrintPush(&stack);

    Push(&stack, numbers[1]);
    PrintPush(&stack);

    while (1)
    {
        if (Pop(&stack, &value) == 0)
            break;
        printf("\nPop number: %d", value);
    }

    FreeStack(&stack); // In case of memory leak
    return 1;
}