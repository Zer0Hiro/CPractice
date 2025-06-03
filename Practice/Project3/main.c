#include "header.h"

int main()
{
    Node *head = NULL, *tail = NULL;
    int count, steps;
    int nums[N];
    int i;

    // Amount of steps for program
    printf("Enter the amount of steps please: ");
    scanf("%d", &steps);

    // Enter 10 numbers
    printf("\nEnter 10 integers please: ");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &nums[i]);
    }

    // Create list
    CreateLink(&head, &tail, N, nums);

    // Start of the game
    count = Jumpy(&head, &tail, steps);
    printf("The amount of steps are: %d", count);
    PrintResult(head);
    FreeAll(head);
    return 0;
}
