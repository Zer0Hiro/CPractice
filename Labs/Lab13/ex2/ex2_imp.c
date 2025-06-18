#include "ex2.h"

// Init of a new stack with capacity of size elements
void InitStack(PStack s, int size)
{
    int *temp;
    temp = (int *)malloc(sizeof(int) * size);
    if (temp == NULL)
    {
        ;
        printf("\nMemory allocation error\n");
        exit(1);
    }
    s->Array = temp;
    s->top = -1;
    s->size = size;
    s->count = 0;
}

// Add a new member to array of the stack
void Push(PStack s, int new_elem)
{
    if (s->size <= s->count)
    {
        printf("\nThe Stack is full\n");
        return;
    }
    s->top++;
    s->Array[s->top] = new_elem;
    s->count++;
}

// Delete member from the array of the stack and return the deleted value
int Pop(PStack s, int *del_value)
{
    if (s->count == 0)
    {
        printf("The stack is empty\n");
        return 0;
    }
    else
    {
        *del_value = s->Array[s->top];
        s->Array[s->top] = 0;
        s->top--;
    }
    s->count--;
    return 1;
}