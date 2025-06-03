#include "header.h"

// This function will create new LinkedList
void CreateLink(Node **head, Node **tail, int size, int *numbers)
{

    Node *temp = NULL;
    int i;

    // Create new node and add it to Head
    for (i = 0; i < size; i++)
    {
        temp = (Node *)malloc(sizeof(Node));
        if (temp == NULL)
        {
            FreeAll(*head);
            ErrorMsg("Memory allocation failed");
        }

        temp->num = numbers[i];
        temp->prev = NULL;

        if (*head == NULL)
        {
            temp->next = NULL;
            *head = temp;
            *tail = temp;
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
    Node *pos = *head;
    int i, j, jsize;

    for (i = 0; i < amount; i++)
    {

        if ((pos) == NULL)
        {
            printf("\nThe game ends: out-of-play area\n");
            return i;
        }

        // Size of jump
        jsize = (pos)->num;

        // If number = 1 or -1
        if (jsize == 1 || jsize == -1)
            RemoveBlock(&pos, head, tail, jsize);

        // If number = 0
        else if (jsize == 0)
        {
            printf("\nDEAD END\n");
            return i;
        }

        else
            JumpDir(&pos, jsize);
    }
    printf("\nYou reached max amount of steps\n");
    return i;
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
            // Move right (pos number)
            if (flag != 1)
                (*pos) = (*pos)->next;
            // Move left (neg number)
            else
                (*pos) = (*pos)->prev;
        }
        else
            break;
    }
}

// This function will free all allocated memory
void FreeAll(Node *head)
{
    Node *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// This function will remove one specific block
int RemoveBlock(Node **pos, Node **head, Node **tail, int direction)
{
    Node *temp = *pos;

    // In case we try to remove Head
    if (temp->prev)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        *head = temp->next;
        if (direction < 0)
        {
            *pos = NULL;
            free(temp);
            return 0;
        }
    }

    // In case we try to remove Tail
    if (temp->next)
    {
        temp->next->prev = temp->prev;
    }
    else
    {
        *tail = temp->prev;
        if (direction > 0)
        {
            *pos = NULL;
            free(temp);
            return 0;
        }
    }

    // Check direction of jump
    if (direction > 0)
        *pos = (*pos)->next;
    else
        *pos = (*pos)->prev;

    // Free block
    free(temp);
    return 0;
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
    while (head)
    {
        printf("%d", head->num);
        if (head->next)
            printf(", ");
        head = head->next;
    }
    printf(" ]");
}