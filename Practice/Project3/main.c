#include "header.h"

int main()
{
    Node *head = NULL, *tail = NULL;
    Node **Phead = &head, **Ptail = &tail;
    int count, steps;
    int nums[N];
    int i;

    // Get steps from user
    printf("Enter the amount of steps please: ");
    scanf("%d", &steps);

    // Enter 10 numbers
    printf("\nEnter 10 integers please: ");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &nums[i]);
    }

    // Create list
    CreateLink(Phead, Ptail, N, nums);

    // Get amount of steps
    count = Jumpy(Phead, Ptail, steps);
    
    printf("The amount of steps are: %d", count);
    PrintResult(*Phead);
    FreeAll(head);
    return 0;
}