#include "header.h"

// This function will create new LinkedList
void CreateLink(Node **head, Node **tail, int size, int *numbers)
{

    Node *temp = NULL;
    int i;

    // Create new node and add it to Head
    for (i = 1; i <= size; i++)
    {
        temp = (Node *)malloc(sizeof(Node));
        if (temp == NULL)
        {
            FreeAll(*head);
            ErrorMsg("Memory allocation failed");
        }

        temp->num = numbers[i - 1];
        temp->prev = NULL;

        if (*head == NULL)
        {
            temp->next = NULL;
            *head = temp;
        }
        else // Head exist
        {
            temp->next = *head;
            (*head)->prev = temp;
        }
        *head = temp;
    }
}

// This function will jump to new position
int Jumpy(Node **head, Node **tail, int amount)
{
    Node **pos = head;
    int i, j, count = 0, jsize;

    for (i = 0; i < amount; i++)
    {

        if ((*pos) == NULL)
        {
            printf("\nThe game ends: out-of-play area\n");
            return count;
        }

        // Size of jump
        jsize = (*pos)->num;

        // If number = 1 or -1
        if (jsize == 1 || jsize == -1)
            RemoveBlock(pos, jsize);

        // If number = 0
        else if (jsize == 0)
        {
            printf("\nDEAD END");
            return count;
        }

        else
            JumpDir(pos, jsize);

        count++;
    }
    printf("You reached max amount of steps");
    return count;
}

// This function will allow to jump to both direction depending on number sign
void JumpDir(Node **pos, int direction)
{
    int j, flag = 0;

    // Define direction
    if (direction < 0)
    {
        flag = 1; // Moves left
        direction *= -1;
    }

    // Move pointer
    for (j = 0; j < direction; j++)
    {
        if ((*pos) != NULL)
        {
            if (flag != 1)
            {
                (*pos) = (*pos)->next;
            }
            else
            {
                (*pos) = (*pos)->prev;
            }
        }
        else
            break;
    }
}

// This function will free all allocated memory
void FreeAll(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// This function will remove one specific block
void RemoveBlock(Node **pos, int direction)
{
    Node *temp;

    // Redirect blocks
    temp = *pos;
    (*pos)->prev->next = (*pos)->next;
    (*pos)->next->prev = (*pos)->prev;

    // Check direction of jump
    if (direction > 0)
        *pos = (*pos)->next;
    else
        *pos = (*pos)->prev;

    // Free block
    free(temp);
}

// This function prints requested error and closes the program
void ErrorMsg(char *msg)
{
    printf("%s", msg);
    exit(1);
}

// This function will print final result
void PrintResult(Node *head)
{
    printf("\nFinal array is: [ ");
    while(head != NULL)
    {
        printf("%d, ",head->num);
        head = head->next;
    }
    printf(" ]");
}