#include "ex3.h"

// Add a new member to list of the queue
void Enqueue(PQue Q, int new_elem)
{
    Item *temp;

    temp = (Item *)malloc(sizeof(Item));
    if (temp == NULL)
    {
        FreeQueue(Q);
        printf("\nMemory error\n");
        exit(1);
    }

    temp->num = new_elem;
    temp->next = NULL;

    // First node only
    if (Q->head == NULL)
        Q->head = temp;
    else
        Q->tail->next = temp;

    Q->tail = temp;
    Q->size++;
}

// Delete member from the queue and return the deleted value
int Dequeue(PQue Q, int *del_value)
{
    Item *temp;

    if (Q->head == NULL)
    {
        printf("\nQueue underflow\n");
        return 0;
    }

    temp = Q->head;
    *del_value = temp->num;

    Q->head = Q->head->next;
    if (Q->head == NULL)
        Q->tail = NULL;

    free(temp);
    Q->size--;
    return 1;
}

// Free all nodes in queue
void FreeQueue(PQue Q)
{
    Item *temp;

    while (Q->head != NULL)
    {
        temp = Q->head;
        Q->head = Q->head->next;
        free(temp);
    }
    Q->tail = NULL;
    Q->size = 0;
}

// Prints whole Queue
void PrintQueue(PQue Q)
{
    Item *temp = Q->head;
    int i;
    printf("\nThe Queue atm is (FIFO from left): \n");
    for (i = 0; i < Q->size; i++)
    {
        printf("->%d", temp->num);
        temp = temp->next;
    }
}