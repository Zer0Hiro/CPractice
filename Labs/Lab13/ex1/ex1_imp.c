#include "ex1.h"

// Add a new member to list of the stack
void Push(PStack s, int new_elem)
{
    Item *temp;

    temp = (Item *)malloc(sizeof(Item));
    if (temp == NULL)
    {
        // free all nodes
        FreeStack(s);
        printf("\nMemory error\n");
        exit(1);
    }

    // merge nodes
    temp->num = new_elem;
    temp->next = s->head;
    s->head = temp;
    s->size++;
}

// Delete member ftom the stack and return the deleted value
int Pop(PStack s, int *del_value)
{
    Item *temp;

    if (s->head == NULL)
    {
        printf("\nStack is empty\n");
        return 0;
    }

    temp = s->head;
    *del_value = temp->num;
    s->head = s->head->next;
    free(temp);

    s->size--;
    return 1;
}

// Prints whole stack
void PrintPush(PStack s)
{
    printf("\nThe stack atm is: \n");
    Item *temp = s->head;
    while (temp != NULL)
    {
        printf("->%d", temp->num);
        temp = temp->next;
    }
}

// Free all nodes in stack
void FreeStack(PStack s)
{
    Item *temp;

    while (s->head != NULL)
    {
        temp = s->head;
        s->head = s->head->next;
        free(temp);
    }
    s->size = 0;
}