#include "ex3.h"
#define SIZE 5

int main()
{
    int num[6] = {1, 2, 3, 4, 5, 6};
    int i, value;
    Queue queue;
    queue.head = NULL;
    queue.tail = NULL;
    queue.size = 0;

    for (i = 0; i < 6; i++)
    {
        if (queue.size >= SIZE)
            printf("\nQueue is full\n");
        else
            Enqueue(&queue, num[i]);
    }
    PrintQueue(&queue);

    Dequeue(&queue, &value);
    printf("\nDequed number is: %d", value);
    Dequeue(&queue, &value);
    printf("\nDequed number is: %d", value);
    PrintQueue(&queue);

    Enqueue(&queue, num[0]);
    PrintQueue(&queue);

    while (1)
    {
        if (Dequeue(&queue, &value) == 0)
            break;
        printf("\nDequed number is: %d", value);
    }

    FreeQueue(&queue); // In case of some memory errors
    return 0;
}