#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

typedef struct Item
{
    int code;
    char name[10];
    struct Item *next;
} Item;

int main()
{
    int i, j;
    Item *Head = NULL, *temp;

    // Create node
    for (i = 1; i <= N; i++)
    {
        temp = (Item *)malloc(sizeof(Item));
        if (temp == NULL)
        {
            // free memory of all nodes
            while (Head != NULL)
            {
                temp = Head;
                Head = Head->next;
                free(temp);
            }
            printf("Memory allocation error");
            exit(1);
        }

        // Get data for node
        printf("Enter a new code and name: ");
        while (scanf("%d %s", &(temp->code), temp->name) != 2)
        {
            printf("Wrong input try again");
            rewind(stdin);
            printf("\nEnter a new code and name: ");
        }

        // Add node to the head of list
        temp->next = Head;
        Head = temp;
    }

    // Print list
    printf("The list is: ");
    temp = Head;
    while (temp != NULL)
    {
        printf("%d,%s --> ", temp->code, temp->name);
        temp = temp->next;
    }

    // free memory of all nodes
    while (Head != NULL)
    {
        temp = Head;
        Head = Head->next;
        free(temp);
    }

    return 0;
}